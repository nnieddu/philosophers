/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 12:16:59 by ninieddu          #+#    #+#             */
/*   Updated: 2021/07/02 12:32:08 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	*ft_monitor(void *phil)
{
	t_philo			*philo;
	struct timeval	now;
	long long		ms;
	int				i;

	philo = phil;
	while (1)
	{
		sem_wait(philo->check);
		sem_wait(philo->args->acting);
		gettimeofday(&now, NULL);
		ms = ft_time(now) - ft_time(philo->last_meal);
		gettimeofday(&now, NULL);
		if (ms >= philo->args->time_to_die)
		{
			printf("%ld\t%d\t %s\n", ft_time(now) - ft_time(philo->args->start_t), philo->name + 1, "died");
			i = 0;
			while (i < philo->args->nbr_of_philos)
				kill(philo->args->philos[i++].pid, SIGTERM);
			sem_post(philo->args->finish);
			return (NULL);
		}
		sem_post(philo->args->acting);
		sem_post(philo->check);
	}
	return (NULL);
}

void	*ft_monitor_each_meals(void *phil)
{
	t_philo			*philo;
	int				i;

	philo = phil;	
	i = -1;
	while (++i < philo->args->nbr_of_philos)
		sem_wait(philo->args->finish_meals);
	sem_post(philo->args->finish);
	return (NULL);
}

void	ft_clean(t_args *args)
{
	int		i;
	int		status;

	i = -1;
	while (++i < args->nbr_of_philos)
	{
		waitpid(args->philos[i].pid, &status, 0);
		sem_close(args->philos[i].check);
		free(args->philos[i].namee);
	}
	free(args->philos);
	sem_close(args->finish);
	sem_close(args->acting);
	sem_close(args->forks);
	sem_close(args->finish_meals);
}

static void	ft_create_philos(t_args *args)
{
	int			i;

	gettimeofday(&args->start_t, NULL);
	i = 0;
	while (i < args->nbr_of_philos)
	{
		args->philos[i].last_meal = args->start_t;
		args->philos[i].pid = fork();
		if (args->philos[i].pid == 0)
			return (ft_philo(&args->philos[i]));
		else if (args->philos[i].pid < 0)
		{
			ft_error("ERROR: fork failed");
			exit(1);
		}
		++i;
	}
}

int	main(int ac, char **av)
{
	t_args		args;

	if (ac != 5 && ac != 6)
		return (ft_error("Error : need at least 4 args to start (5 max).\n"));
	memset(&args, 0, sizeof(args));
	if (ft_init(&args, ac, av))
		return (1);
	ft_create_philos(&args);
	ft_clean(&args);
	return (0);
}

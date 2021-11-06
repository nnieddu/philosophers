/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 12:16:59 by ninieddu          #+#    #+#             */
/*   Updated: 2021/11/06 11:28:52 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	*ft_monitor(void *phil)
{
	t_philo			*philo;
	struct timeval	now;
	long			ms;

	philo = phil;
	while (1)
	{
		sem_wait(philo->args->acting);
		gettimeofday(&now, NULL);
		ms = ft_time(now) - ft_time(philo->last_meal);
		if (ms >= philo->args->time_to_die)
		{
			sem_post(philo->args->acting);
			ft_print_status(philo, "is dead.", 1);
			sem_post(philo->args->finish);
			return (NULL);
		}
		sem_post(philo->args->acting);
		if (philo->meals_count == philo->args->nbr_each_must_eat)
			return (NULL);
	}
}

void	*ft_master_monitor(void *argz)
{
	t_args			*args;
	int				i;

	i = -1;
	args = argz;
	sem_wait(args->finish);
	if (args->stop == 0)
		args->stop = 1;
	if (args->stop == 1)
		while (++i < args->nbr_of_philos)
			kill(args->philos[i].pid, SIGTERM);
	sem_post(args->end);
	return (NULL);
}

void	ft_clean(t_args *args)
{
	int		i;
	int		status;

	i = -1;
	sem_wait(args->end);
	if (args->stop == 0)
	{
		args->stop = 2;
		while (++i < args->nbr_of_philos)
			waitpid(args->philos[i].pid, &status, 0);
		sem_post(args->finish);
	}
	sem_close(args->acting);
	sem_close(args->forks);
	sem_close(args->end);
	sem_close(args->finish);
	free(args->philos);
}

void	ft_create_philos(t_args *args)
{
	int			i;
	pthread_t	thread;

	i = -1;
	gettimeofday(&args->start_t, NULL);
	pthread_create(&thread, NULL, ft_master_monitor, args);
	pthread_detach(thread);
	while (++i < args->nbr_of_philos)
	{
		args->philos[i].last_meal = args->start_t;
		args->philos[i].pid = fork();
		if (args->philos[i].pid < 0)
		{
			ft_error("Error : fork failed !");
			ft_clean(args);
			exit (1);
		}
		if (args->philos[i].pid == 0)
			ft_philo(&args->philos[i]);
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

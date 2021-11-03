/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 12:16:59 by ninieddu          #+#    #+#             */
/*   Updated: 2021/11/03 09:37:25 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	*ft_monitor(void *phil)
{
	t_philo			*philo;
	struct timeval	now;
	long			ms;

	philo = phil;
	while (philo->args->stop == 0)
	{
		pthread_mutex_lock(&philo->args->stop_mutex);
		gettimeofday(&now, NULL);
		ms = ft_time(now) - ft_time(philo->last_meal);
		if (ms > philo->args->time_to_die && philo->args->stop == 0)
		{
			philo->args->stop = 1;
			printf("[%ld]\t%d\t %s\n", ms, philo->name, "died");
		}
		if (philo->args->end_of_meals == philo->args->nbr_of_philos)
			philo->args->stop = 1;
		pthread_mutex_unlock(&philo->args->stop_mutex);
	}
	return (NULL);
}

void	ft_clean(t_args *args)
{
	int		i;

	i = -1;
	while (++i < args->nbr_of_philos)
		pthread_join(args->philos[i].thread, NULL);
	free(args->philos);
	i = -1;
	while (++i < args->nbr_of_philos)
		pthread_mutex_destroy(&args->forks[i]);
	pthread_mutex_destroy(&args->stop_mutex);
	free(args->forks);
}

void	ft_create_philos(t_args *args)
{
	int			i;
	pthread_t	thread;

	i = -1;
	// gettimeofday(&args->start_t, NULL);
	while (++i < args->nbr_of_philos)
	{
		// args->philos[i].last_meal = args->start_t;
		pthread_create(&args->philos[i].thread, NULL, \
			ft_philo, &args->philos[i]);
	pthread_create(&thread, NULL, ft_monitor, &args->philos[0]);
	pthread_detach(thread);
	}
}

int	main(int ac, char **av)
{
	t_args	args;

	if (ac != 5 && ac != 6)
		return (ft_error("Error : need at least 4 args to start (5 max).\n"));
	memset(&args, 0, sizeof(args));
	if (ft_init(&args, ac, av))
		return (1);
	ft_create_philos(&args);
	ft_clean(&args);
	return (0);
}

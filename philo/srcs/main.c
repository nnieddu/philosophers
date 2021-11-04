/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 12:16:59 by ninieddu          #+#    #+#             */
/*   Updated: 2021/11/04 00:04:09 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	*ft_monitor(void *phil)
{
	t_philo			*philo;
	struct timeval	now;
	long			ms;

	philo = phil;
	while (!philo->args->stop)
	{
		pthread_mutex_lock(&philo->args->stop_mutex);
		gettimeofday(&now, NULL);
		ms = ft_time(now) - ft_time(philo->last_meal);
		if (ms > philo->args->time_to_die && philo->args->stop == 0)
		{
			printf("[%ld]\t%d\t %s\n", ms, philo->name, "died");
			pthread_mutex_unlock(philo->right);
			pthread_mutex_unlock(philo->left);
			philo->args->stop = 1;
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

int	ft_create_philos(t_args *args)
{
	int			i;
	int			ret;
	pthread_t	thread;

	ret = 0;
	i = -1;
	ret = gettimeofday(&args->start_t, NULL);
	while (++i < args->nbr_of_philos && ret == 0)
	{
		args->philos[i].last_meal = args->start_t;
		ret = pthread_create(&args->philos[i].thread, NULL, \
			ft_philo, &args->philos[i]);
		ret = pthread_create(&thread, NULL, ft_monitor, &args->philos[i]);
		ret = pthread_detach(thread);
	}
	if (ret != 0)
		return (ft_error("Error : thread creation problem !"));
	return (0);
}

int	main(int ac, char **av)
{
	t_args	args;

	if (ac != 5 && ac != 6)
		return (ft_error("Error : need at least 4 args to start (5 max).\n"));
	memset(&args, 0, sizeof(args));
	if (ft_init(&args, ac, av))
		return (1);
	if (ft_create_philos(&args))
		return (1);
	ft_clean(&args);
	return (0);
}

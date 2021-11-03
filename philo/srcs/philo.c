/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 09:04:44 by ninieddu          #+#    #+#             */
/*   Updated: 2021/06/29 12:01:01 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	ft_take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right);
	ft_print_status(philo, "has taken a fork");
	pthread_mutex_lock(philo->left);
	ft_print_status(philo, "has taken a fork");
}

void	ft_eat(t_philo *philo)
{
	long	ms;

	pthread_mutex_lock(&philo->args->stop_mutex);
	gettimeofday(&philo->last_meal, NULL);
	ms = ft_time(philo->last_meal) - \
		ft_time(philo->args->start_t);
	if (!philo->args->stop)
		printf("[%ld]\t%d\t %s\n", ms, philo->name, "is eating");
	philo->meals_count++;
	if (philo->meals_count == philo->args->nbr_each_must_eat)
		philo->args->end_of_meals++;
	pthread_mutex_unlock(&philo->args->stop_mutex);
	usleep(philo->args->time_to_eat * 1000);
	pthread_mutex_unlock(philo->right);
	pthread_mutex_unlock(philo->left);
}

void	*ft_philo(void *phil)
{
	t_philo	*philo;

	philo = phil;
	if ((philo->name - 1) % 2 == 0)
		usleep(10000);
	while (!philo->args->stop)
	{
		ft_take_fork(philo);
		ft_eat(philo);
		if (philo->meals_count == philo->args->nbr_each_must_eat)
			return (0);
		ft_print_status(philo, "is sleeping");
		usleep(philo->args->time_to_sleep * 1000);
		ft_print_status(philo, "is thinking");
	}
	return (0);
}

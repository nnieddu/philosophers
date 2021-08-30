/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 09:04:44 by ninieddu          #+#    #+#             */
/*   Updated: 2021/07/02 12:21:41 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	ft_take_fork(t_philo *philo)
{
	sem_wait(philo->args->forks);
	ft_print_status(philo, "has taken a fork");
	sem_wait(philo->args->forks);
	ft_print_status(philo, "has taken a fork");
}

void	ft_eat(t_philo *philo)
{
	sem_wait(philo->check);
	gettimeofday(&philo->last_meal, NULL);
	ft_print_status(philo, "is eating");
	philo->meals_count += 1;
	// if (philo->meals_count == philo->args->nbr_each_must_eat)
	// 	sem_post(philo->args->finish_meals);
	usleep(philo->args->time_to_eat * 1000);
	sem_post(philo->args->forks);
	sem_post(philo->args->forks);
	sem_post(philo->check);	
}

void	ft_philo(t_philo *philo)
{
	pthread_t	thread;

	pthread_create(&thread, NULL, ft_monitor, philo);
	if (philo->name % 2 == 0)
		usleep(10000);
		// usleep(philo->args->time_to_eat * 1000);
	while (1)
	{
		ft_take_fork(philo);
		ft_eat(philo);
		if (philo->meals_count == philo->args->nbr_each_must_eat)
			break;
		ft_print_status(philo, "is sleeping");
		usleep(philo->args->time_to_sleep * 1000);
		ft_print_status(philo, "is thinking");
	}
	exit(0);
}

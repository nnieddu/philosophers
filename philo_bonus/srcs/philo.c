/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 09:04:44 by ninieddu          #+#    #+#             */
/*   Updated: 2021/11/06 11:36:15 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	ft_take_fork(t_philo *philo)
{
	sem_wait(philo->args->forks);
	ft_print_status(philo, "has taken a fork", 0);
	sem_wait(philo->args->forks);
	ft_print_status(philo, "has taken a fork", 0);
}

void	ft_eat(t_philo *philo)
{
	gettimeofday(&philo->last_meal, NULL);
	ft_print_status(philo, "is eating", 0);
	philo->meals_count += 1;
	usleep(philo->args->time_to_eat * 1000);
	sem_post(philo->args->forks);
	sem_post(philo->args->forks);
}

void	ft_philo(t_philo *philo)
{
	pthread_t	thread;

	pthread_create(&thread, NULL, ft_monitor, philo);
	pthread_detach(thread);
	if (philo->name % 2 == 0)
		usleep(10000);
	while (1)
	{
		ft_take_fork(philo);
		ft_eat(philo);
		if (philo->meals_count == philo->args->nbr_each_must_eat)
		{
			sem_post(philo->args->end);
			break ;
		}
		ft_print_status(philo, "is sleeping", 0);
		usleep(philo->args->time_to_sleep * 1000);
		ft_print_status(philo, "is thinking", 0);
	}
	exit(0);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 09:08:50 by ninieddu          #+#    #+#             */
/*   Updated: 2021/06/28 10:58:28 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

long	ft_time(struct timeval now)
{
	long	ms;

	ms = now.tv_sec * 1000;
	ms += now.tv_usec / 1000;
	return (ms);
}

void	ft_print_status(t_philo *philo, char *str)
{
	long			ms;
	struct timeval	now;

	pthread_mutex_lock(&philo->args->stop_mutex);
	gettimeofday(&now, NULL);
	ms = ft_time(now) - ft_time(philo->args->start_t);
	if (!philo->args->stop)
		printf("[%ld]\t%d\t %s\n", ms, philo->name, str);
	pthread_mutex_unlock(&philo->args->stop_mutex);
}

int	ft_error(char *str)
{
	printf("%s", str);
	return (1);
}

int	ft_atoi(const char *str)
{
	size_t	big;
	int		nbr;
	char	sign;

	big = 0;
	sign = '+';
	while ((*str < 14 && *str > 8) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			sign = *str;
		}
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		big = big * 10 + (*str - 48);
		str++;
	}
	nbr = big;
	if (sign == '-')
		return (-nbr);
	return (nbr);
}

int	ft_malloc(void *dst, size_t size)
{
	*(void **)dst = malloc(size);
	if (*(void **)dst == NULL)
		return (1);
	memset(*(void **)dst, 0, size);
	return (0);
}

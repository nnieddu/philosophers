/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 09:08:50 by ninieddu          #+#    #+#             */
/*   Updated: 2021/11/06 11:04:56 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

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

void	ft_print_status(t_philo *philo, char *str, int x)
{
	long			ms;
	struct timeval	now;

	gettimeofday(&now, NULL);
	ms = ft_time(now) - ft_time(philo->args->start_t);
	sem_wait(philo->args->acting);
	printf("[%ld]\t%d\t %s\n", ms, philo->name, str);
	if (x == 0)
		sem_post(philo->args->acting);
}

long	ft_time(struct timeval now)
{
	long	ms;

	ms = now.tv_sec * 1000;
	ms += now.tv_usec / 1000;
	return (ms);
}

int	ft_error(char *str)
{
	printf("%s", str);
	return (1);
}

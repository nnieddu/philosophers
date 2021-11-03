/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 09:06:19 by ninieddu          #+#    #+#             */
/*   Updated: 2021/07/02 12:07:20 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		++i;
	return (i);
}

char	*ft_name(char *name, int n)
{
	char	*result;
	int		num;
	int		i;

	i = 0;
	num = n;
	while (num)
	{
		num /= 10;
		++i;
	}
	result = malloc(sizeof(char) * (i + ft_strlen(name) + 1));
	if (result == NULL)
		return (NULL);
	num = -1;
	while (++num < i)
		result[num] = name[num];
	while (n)
	{
		result[i++] = n % 10 + '0';
		n /= 10;
	}
	result[i] = 0;
	return (result);
}

static sem_t	*ft_sem_init(const char *name, unsigned int value)
{
	sem_t	*sem;

	sem = sem_open(name, O_CREAT | O_EXCL, 0644, value);
	if (sem != SEM_FAILED)
		return (sem);
	sem_unlink(name);
	return (sem_open(name, O_CREAT | O_EXCL, 0644, value));
}

void	ft_parse_args(t_args *args, int ac, char **av)
{
	args->nbr_of_philos = ft_atoi(av[1]);
	args->time_to_die = ft_atoi(av[2]);
	args->time_to_eat = ft_atoi(av[3]);
	args->time_to_sleep = ft_atoi(av[4]);
	args->nbr_each_must_eat = -1;
	if (ac == 6)
		args->nbr_each_must_eat = ft_atoi(av[5]);
}

int	ft_check_args(t_args *args, int ac)
{
	if (args->nbr_of_philos <= 1)
		return (ft_error("Error : need at least 2 philosophers.\n"));
	if (args->time_to_die < 0)
		return (ft_error("Error : this argument can't be negative.\n"));
	if (args->time_to_eat < 0)
		return (ft_error("Error : this argument can't be negative.\n"));
	if (args->time_to_sleep < 0)
		return (ft_error("Error : this argument can't be negative.\n"));
	if (ac == 6 && args->nbr_each_must_eat <= 0)
		return (ft_error("Error : last arg can't be less than 1.\n"));
	return (0);
}

int	ft_init_philos(t_args *args)
{
	int		i;

	args->acting = ft_sem_init("acting", 1);
	args->forks = ft_sem_init("forks", args->nbr_of_philos);
	args->finish = ft_sem_init("finish", 0);
	// args->finish_meals = ft_sem_init("finish_meals", 0);
	if (ft_malloc(&args->philos, sizeof(t_philo) * args->nbr_of_philos))
		return (ft_error("Error : malloc error\n"));
	i = 0;
	while (i < args->nbr_of_philos)
	{
		args->philos[i].namee = ft_name("philo", i);
		args->philos[i].check = ft_sem_init(args->philos[i].namee, 1);
		args->philos[i].name = i;
		args->philos[i].args = args;
		++i;
	}
	return (0);
}

int	ft_init(t_args *args, int ac, char **av)
{
	ft_parse_args(args, ac, av);
	if (ft_check_args(args, ac))
		return (1);
	if (ft_init_philos(args))
		return (1);
	return (0);
}

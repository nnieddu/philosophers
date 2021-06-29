/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 12:24:59 by ninieddu          #+#    #+#             */
/*   Updated: 2021/06/29 06:08:51 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	int				name;
	int				nbr_of_meals;
	pthread_t		thread;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	struct s_args	*args;
	struct timeval	last_meal;
}					t_philo;

typedef struct s_args
{
	int				nbr_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				end_of_meals;
	int				count_each_must_eat;
	int				stop;
	pthread_mutex_t	stop_mutex;
	struct timeval	start_t;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}			t_args;

void		*ft_philo(void *phil);
void		ft_print_status(t_philo *philo, char *str);
int			ft_init(t_args *info, int argc, char *argv[]);
int			ft_strlen(char *str);
int			ft_atoi(const char *str);
int			ft_error(char *str);
int			ft_malloc(void *dst, size_t size);
long		ft_time(struct timeval now);

#endif

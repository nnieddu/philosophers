/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 12:24:59 by ninieddu          #+#    #+#             */
/*   Updated: 2021/07/02 11:53:12 by ninieddu         ###   ########lyon.fr   */
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
# include <semaphore.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/wait.h>

typedef struct s_philo
{
	int				name;
	char			*namee;
	sem_t			*check;
	pid_t			pid;	
	int				meals_count;
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
	int				nbr_each_must_eat;
	int				end_of_meals;
	int				stop;

	sem_t			*acting;
	sem_t			*finish_meals;
	sem_t			*finish;
	sem_t			*forks;
	t_philo			*philos;
	struct timeval	start_t;
}			t_args;

void		ft_philo(t_philo *philo);
void		*ft_monitor(void *phil);
void		ft_print_status(t_philo *philo, char *str);
int			ft_init(t_args *args, int argc, char *av[]);
int			ft_atoi(const char *str);
int			ft_error(char *str);
int			ft_malloc(void *dst, size_t size);
long		ft_time(struct timeval now);

#endif
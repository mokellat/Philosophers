/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <mokellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 14:19:12 by mokellat          #+#    #+#             */
/*   Updated: 2021/10/31 14:19:12 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct t_philosophers
{
	int				num_philos;
	int				num_forks;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				must_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
}	t_philos;

typedef struct t_threads
{
	pthread_t		ph_th;
	int				ph_id;
	int				lf_id;
	int				rf_id;
	long long		eat_start;
	int				num_eat;
	long long		dif;
	int				check;
}	t_threads;

int			assign(char **argv, t_philos *philo, int argc);
int			ft_atoi(const char *str);
int			threads_assign(t_philos *philos, t_threads *threads);
int			mutexes_assign(t_philos *philos);
long long	time_fun(void);
void		ft_error(void *pointer);
t_philos	*static_philo(void);
void		philo_fork_print(t_threads *th);
void		philo_eating_print(t_threads *th, t_philos *philo);
void		philo_sleep_print(t_threads *th);
void		philo_thinking_print(t_threads *th);
void		philo_dies_print(t_threads *th, t_philos *ph);
int			supervisor(t_threads *threads);
void		ft_usleep(long long time);
#endif
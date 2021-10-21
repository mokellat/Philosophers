/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 11:32:25 by marvin            #+#    #+#             */
/*   Updated: 2021/09/23 11:32:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    *threads_exec(void   *arg)
{
    g_threads	*thread;
	g_philos	*philos;

	thread->eat_num = 0;
	while(1) // cause every philosophers needs to eat each till is there a condition that stops hime
	{
		thread = (g_threads*)arg;
		philos = static_philo();
		pthread_mutex_lock(&philos->forks[thread->lf_id]);
		philo_fork_print(thread);
		pthread_mutex_lock(&philos->forks[thread->rf_id]);
		philo_fork_print(thread);
		thread->eat_num++;
		philo_eating_print(thread);
		thread->eat_start = time_fun();
		usleep(philos->time_to_eat);
		pthread_mutex_unlock(&philos->forks[thread->lf_id]);
		pthread_mutex_unlock(&philos->forks[thread->rf_id]);
		philo_sleep_print(thread);
		usleep(philos->time_to_sleep);
		philo_thinking_print(thread);
	}
    return (NULL);
}

int	threads_assign(g_philos *philos, g_threads *threads)
{
	int i;

	i = 0;
	while(i < philos->num_philos)
	{
		threads[i].ph_id = i + 1;
        threads[i].lf_id = i % philos->num_philos;
        threads[i].rf_id = (i + 1) % philos->num_philos;
		if (pthread_create(&threads[i].ph_th, NULL, threads_exec, &threads[i]) != 0)
			return (0);
		usleep(100);
		i++;
	}
	if(!supervisor(threads))
		return (1);
	return (1);
}
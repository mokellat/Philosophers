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

void	*threads_exec(void *arg)
{
	t_threads	*thread;
	t_philos	*philos;

	while (1)
	{
		thread = (t_threads *)arg;
		philos = static_philo();
		if (thread->ph_id % 2 == 0)
			usleep(100);
		pthread_mutex_lock(&philos->forks[thread->lf_id]);
		philo_fork_print(thread);
		pthread_mutex_lock(&philos->forks[thread->rf_id]);
		philo_fork_print(thread);
		thread->num_eat++;
		philo_eating_print(thread, philos);
		thread->eat_start = time_fun();
		ft_usleep(philos->time_to_eat);
		pthread_mutex_unlock(&philos->forks[thread->rf_id]);
		pthread_mutex_unlock(&philos->forks[thread->lf_id]);
		philo_sleep_print(thread);
		ft_usleep(philos->time_to_sleep);
		philo_thinking_print(thread);
	}
	return (NULL);
}

int	threads_assign(t_philos *philos, t_threads *threads)
{
	int			i;
	long long	start ;

	i = 0;
	start = time_fun();
	while (i < philos->num_philos)
	{
		threads[i].ph_id = i + 1;
		threads[i].lf_id = i % philos->num_philos;
		threads[i].rf_id = (i + 1) % philos->num_philos;
		threads[i].num_eat = 0;
		threads[i].eat_start = time_fun();
		threads[i].dif = time_fun();
		if (pthread_create(&threads[i].ph_th, NULL,
				threads_exec, &threads[i]) != 0)
			return (0);
		i++;
	}
	if (!supervisor(threads))
		return (1);
	return (1);
}

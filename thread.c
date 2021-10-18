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
	g_summary	*sum;

	while(1)
	{
		// sum = (g_summary*)arg;
		thread = (g_threads*)arg;
		// printf("%d \n", sum->th->lf_id);
		// printf("%d \n", sum->th->rf_id);
		pthread_mutex_lock(&sum->ph.forks[sum->th->lf_id]);
		// philo_fork_print(sum);
		pthread_mutex_lock(&sum->ph.forks[sum->th->rf_id]);
		// philo_fork_print(sum);
		sum->th->eat_start = time_fun();
		// printf("|im here %ld|\n", thread->eat_start);
		// philo_eating_prin);
		// printf("time %d\n",sum->ph.time_to_eat);
		usleep(sum->ph.time_to_eat);
		pthread_mutex_unlock(&sum->ph.forks[sum->th->lf_id]);
		pthread_mutex_unlock(&sum->ph.forks[sum->th->rf_id]);
		// philo_sleep_print(sum);
		usleep(sum->ph.time_to_sleep);
		// philo_thinking_print(sum);
	}
    return (NULL);
}

int	threads_assign(g_summary *sum)
{
	int i;

	i = 0;
	while(i < sum->ph.num_philos)
	{
		sum->th[i].ph_id = i + 1;
        sum->th[i].lf_id = i % sum->ph.num_philos;
        sum->th[i].rf_id = (i + 1) % sum->ph.num_philos;
		// printf("%d \n", sum->th[i].lf_id);
		// printf("%d \n", sum->th[i].rf_id);
		if (pthread_create(&sum->th[i].ph_th, NULL, threads_exec, &sum->th[i]) != 0)
			return (0);
		usleep(100);
		i++;
	}
	return (1);
}
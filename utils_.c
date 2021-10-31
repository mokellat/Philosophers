/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:27:24 by marvin            #+#    #+#             */
/*   Updated: 2021/10/15 17:27:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_fork_print(t_threads *th)
{
	printf("%d %d has taken a fork\n", (int)((time_fun() - th->dif) / 1000),
		th->ph_id);
}

void	philo_eating_print(t_threads *th, t_philos *philo)
{
	pthread_mutex_lock(&philo->lock);
	printf("%d %d is eating\n", (int)((time_fun() - th->dif) / 1000), th->ph_id);
	pthread_mutex_unlock(&philo->lock);
}

void	philo_sleep_print(t_threads *th)
{
	printf("%d %d is sleeping\n", (int)((time_fun() - th->dif) / 1000),
		th->ph_id);
}

void	philo_thinking_print(t_threads *th)
{
	printf("%d %d is thinking\n", (int)((time_fun() - th->dif) / 1000),
		th->ph_id);
}

void	philo_dies_print(t_threads *th, t_philos *philo)
{
	pthread_mutex_lock(&philo->lock);
	printf("%d %d died\n", (int)((time_fun() - th->eat_start) / 1000),
		th->ph_id);
	pthread_mutex_unlock(&philo->lock);
}

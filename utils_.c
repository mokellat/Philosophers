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

void    philo_fork_print(g_threads *th)
{
    printf("%d philo %d is taken a fork\n",(int)((time_fun()- th->dif) / 1000), th->ph_id);
}

void    philo_eating_print(g_threads *th)
{
    printf("%d philo %d is eating\n",(int)((time_fun()- th->dif) / 1000), th->ph_id);
}

void    philo_sleep_print(g_threads *th)
{
    printf("%d philo %d is sleeping\n",(int)((time_fun()- th->dif) / 1000), th->ph_id);
}

void    philo_thinking_print(g_threads *th)
{
    printf("%d philo %d is thinking\n",(int)((time_fun()- th->dif) / 1000), th->ph_id);
}

void    philo_dies_print(g_threads *th)
{
    printf("%lld philo %d died\n",time_fun()- th->eat_start, th->ph_id);
}
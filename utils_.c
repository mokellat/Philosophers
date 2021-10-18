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

void    philo_fork_print(g_summary *sum)
{
    printf("philo %d is taken a fork\n", sum->th->ph_id);
}

void    philo_eating_print(g_summary *sum)
{
    printf("philo %d is eating\n", sum->th->ph_id);
}

void    philo_sleep_print(g_summary *sum)
{
    printf("philo %d is sleeping\n", sum->th->ph_id);
}

void    philo_thinking_print(g_summary *sum)
{
    printf("philo %d is thinking\n", sum->th->ph_id);
}
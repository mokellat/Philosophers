/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:17:28 by marvin            #+#    #+#             */
/*   Updated: 2021/10/21 15:17:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int supervisor(g_threads *threads)
{
    int         i;
    g_philos    *philo;

    philo = static_philo();
    while(1)
    {
        i = 0;
        while(i < philo->num_philos)
        {
            if(time_fun() - threads[i].eat_start >= (philo->time_to_die * 1000))
            {
                philo_dies_print(threads);
                return (0);
            }
            if(philo->must_eat > 0 && (threads[i].eat_start * philo->num_philos) > philo->must_eat)
                return (0);
            i++;
        }
    }
    return (1);
}
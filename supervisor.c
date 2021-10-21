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
    int var;

    philo = static_philo();
    while(1)
    {
        i = 0;
        var = 0;
        while(i < philo->num_philos)
        {
            if(time_fun() - threads[i].eat_start >= (philo->time_to_die * 1000))
            {
                philo_dies_print(threads);
                return (0);
            }
            if(philo->must_eat > 0 && (threads[i].num_eat  >= philo->must_eat))
                var++;
            i++;
        }
        if (var >= philo->num_philos)
        {
            printf("VAR:%d\n", var);
            return 0;
        }
    }
    return (1);
}
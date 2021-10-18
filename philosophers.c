/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:16:44 by mokellat          #+#    #+#             */
/*   Updated: 2021/09/23 12:25:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int argc, char **argv)
{
    // g_philos    philo;
    // g_threads   *threads;
    g_summary   sum;
    
    // checking the args
    
    if(argc < 5 || argc > 6)
    {
        printf("Error: Arguments are invalid");
        exit(EXIT_FAILURE);
    }

    // assigning the general data
        
    if(!assign(argv, &sum, argc))
    {
        printf("Error: Arguments are invalid");
        exit(EXIT_FAILURE);
    }
    
    // Starting creating threads and mutexes

    sum.th = malloc(sizeof(g_threads) * sum.ph.num_philos);
    if(!mutexes_assign(&sum))
    {
        printf("Error: mutex are uncorrect");
        exit(EXIT_FAILURE);
    }
    if(!threads_assign(&sum))
    {
        printf("Error: threads are uncorrect");
        exit(EXIT_FAILURE);
    }
}
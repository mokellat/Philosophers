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
    g_philos    philo;
    g_threads   *threads;
    
    // checking the args
    
    if(argc < 5 || argc > 6)
    {
        printf("Error: Arguments are invalid");
        exit(EXIT_FAILURE);
    }

    // assigning the general data
        
    if(!assign(argv, &philo, argc))
    {
        printf("Error: Arguments are invalid");
        exit(EXIT_FAILURE);
    }
    
    // Starting creating threads and mutexes
    threads = malloc(sizeof(g_threads) * philo.num_philos);
    if(!mutexes_assign(philo))
        ft_error(philo.forks);
    if(!threads_assign(philo, threads))
        ft_error(threads);
}
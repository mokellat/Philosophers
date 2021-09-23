/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:16:44 by mokellat          #+#    #+#             */
/*   Updated: 2021/09/22 15:52:29 by marvin           ###   ########.fr       */
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
    
    threads = malloc(sizeof(g_threads) * philo.num_philos);
    // Starting creating threads
    if(!threads_assign(philo, threads))
        ft_error(threads);
}
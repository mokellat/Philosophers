/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:16:44 by mokellat          #+#    #+#             */
/*   Updated: 2021/09/21 22:43:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int argc, char **argv)
{
    g_philos philo;
    
    if(argc < 5 || argc > 6)
    {
        printf("Error: Arguments are invalid");
        exit(EXIT_FAILURE);
    }
    if(!assign(argv, &philo, argc))
    {
        printf("Error: Arguments are invalid");
        exit(EXIT_FAILURE);
    } 
    // printf("%d \n", philo.num_philos);
    // printf("%d \n", philo.num_forks);
    // printf("%d \n", philo.time_to_eat);
    // printf("%d \n", philo.time_to_die);
    // printf("%d \n", philo.time_to_sleep);
    // printf("%d \n", philo.must_eat);
}
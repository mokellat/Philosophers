/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 11:30:55 by marvin            #+#    #+#             */
/*   Updated: 2021/09/23 11:30:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	mutexes_assign(g_philos philos)
{
	int i;
	
	i = 0;
	philos.forks = malloc(philos.num_forks * sizeof(pthread_mutex_t*));
	while(i < philos.num_philos)
	{
		pthread_mutex_init(&philos.forks[i], NULL);
		i++;
	}
}
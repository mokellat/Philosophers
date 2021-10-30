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

int	mutexes_assign(t_philos *philos)
{
	int	i;

	i = 0;
	philos->forks = malloc(philos->num_forks * sizeof(pthread_mutex_t *));
	while (i < philos->num_forks)
	{
		if (pthread_mutex_init(&philos->forks[i], NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}

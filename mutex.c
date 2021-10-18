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

int	mutexes_assign(g_summary *sum)
{
	int i;
	
	i = 0;
	sum->ph.forks = malloc(sum->ph.num_forks * sizeof(pthread_mutex_t *));
	while(i < sum->ph.num_forks)
	{
		if (pthread_mutex_init(&sum->ph.forks[i], NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}
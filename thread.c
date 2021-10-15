/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 11:32:25 by marvin            #+#    #+#             */
/*   Updated: 2021/09/23 11:32:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    *threads_exec(void   *arg)
{
    g_threads *thread;

    thread = (g_threads*)arg;
    return (NULL);
}

int	threads_assign(g_philos philos, g_threads *threads)
{
	int i;

	i = 0;
	while(i < philos.num_philos)
	{
		threads[i].ph_id = i + 1;
        threads[i].lf_id = i % philos.num_philos;
        threads[i].rf_id = (i + 1) % philos.num_philos;
		if(pthread_create(&threads[i].ph_th, NULL, threads_exec, NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}
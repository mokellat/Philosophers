/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_fun.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 21:05:32 by marvin            #+#    #+#             */
/*   Updated: 2021/09/21 21:05:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int is_digit(char **argv)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while(argv[i])
	{
		j = 0;
		while(argv[i][j])
		{
			if(argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int assign(char **argv, g_philos *philo, int argc)
{
	if(is_digit(argv))
	{
		philo->num_philos = ft_atoi(argv[1]);
		philo->num_forks = ft_atoi(argv[1]);
		philo->time_to_die = ft_atoi(argv[2]);
		philo->time_to_eat = ft_atoi(argv[3]);
		philo->time_to_sleep = ft_atoi(argv[4]);
		if(argc == 6)
			philo->must_eat = ft_atoi(argv[5]);
		else
			philo->must_eat = -1;
		if(philo->num_philos <= 0 || philo->time_to_die <= 0
		|| philo->time_to_eat <= 0 || philo->time_to_sleep <= 0)
			return(0);
	}
	else
		return (0);
	return(1);
}

void    *threads_exec(void   *arg)
{
    g_threads *thread;

    thread = (g_threads*)arg;
    if(thread->ph_id % 2 == 0)
    {
        
    }
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
		if(pthread_create(threads[i].ph_th, NULL, threads_exec, NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}

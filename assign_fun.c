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

int assign(char **argv, g_summary *sum, int argc)
{
	if(is_digit(argv))
	{
		sum->ph.num_philos = ft_atoi(argv[1]);
		sum->ph.num_forks = ft_atoi(argv[1]);
		sum->ph.time_to_die = ft_atoi(argv[2]);
		sum->ph.time_to_eat = ft_atoi(argv[3]);
		sum->ph.time_to_sleep = ft_atoi(argv[4]);
		if(argc == 6)
			sum->ph.must_eat = ft_atoi(argv[5]);
		else
			sum->ph.must_eat = -1;
		if(sum->ph.num_philos <= 0 || sum->ph.time_to_die <= 0
		|| sum->ph.time_to_eat <= 0 || sum->ph.time_to_sleep <= 0)
			return(0);
		// philo->eat_start = malloc(sizeof(double) * philo->num_philos);
	}
	else
		return (0);
	return(1);
}
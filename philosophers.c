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

int	main(int argc, char **argv)
{
	t_philos	*philo;
	t_threads	*threads;

	if (argc < 5 || argc > 6)
	{
		printf("Error: Arguments are invalid");
		exit(EXIT_FAILURE);
	}
	philo = static_philo();
	if (!assign(argv, philo, argc))
	{
		printf("Error: Arguments are invalid");
		exit(EXIT_FAILURE);
	}
	threads = malloc(sizeof(t_threads) * philo->num_philos);
	if (!mutexes_assign(philo))
	{
		printf("Error: mutex are uncorrect");
		exit(EXIT_FAILURE);
	}
	if (!threads_assign(philo, threads))
	{
		printf("Error: threads are uncorrect");
		exit(EXIT_FAILURE);
	}
}

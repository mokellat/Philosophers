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

void	error_message(char *str, t_threads	*threads)
{
	free(threads);
	printf("%s\n", str);
	exit(EXIT_FAILURE);
}

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
	if(philo->must_eat == 0 || philo->num_philos == 0)
		return (0);
	threads = malloc(sizeof(t_threads) * philo->num_philos);
	if (!mutexes_assign(philo))
		error_message("Error : mutex is uncorrect", threads);
	if (!threads_assign(philo, threads))
		error_message("Error : thread is uncorrect", threads);
	free(threads);
	return (0);
}

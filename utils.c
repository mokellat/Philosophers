/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 21:15:31 by marvin            #+#    #+#             */
/*   Updated: 2021/09/21 21:15:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		ft_atoi(const char *str)
{
	int		sign;
	int		result;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] && (str[i] == '\f' || str[i] == '\t' || str[i] == ' ' ||
			str[i] == '\n' || str[i] == '\r' || str[i] == '\v'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i++] - '0';
	}
	result *= sign;
	return (result);
}

long int	time_fun()
{

	long int		ret;
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	ret = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (ret);
}

void	ft_error(void *pointer)
{
	free(pointer);
	printf("A problem occured with threads or mutexes");
	exit(EXIT_FAILURE);
}

g_philos	*static_philo(void)
{
	static g_philos philos;

	return (&philos);
}

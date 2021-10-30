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

long long	time_fun()
{

	long long			ret;
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	ret = (current_time.tv_sec * 1000000) + (current_time.tv_usec);
	return (ret);
}

void	ft_error(void *pointer)
{
	free(pointer);
	printf("A problem occured with threads or mutexes");
	exit(EXIT_FAILURE);
}

t_philos	*static_philo(void)
{
	static t_philos philos;

	return (&philos);
}

void	ft_usleep(long long time)
{
	long long	r;
	long long	mic;

	mic = time_fun();
	r = (time * 1000) - 1000;
	usleep(r);
	while ((time_fun() - mic) <= ((time * 1000)))
		;
}
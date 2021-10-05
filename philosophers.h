#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct t_philosophers
{
	int             num_philos;
	int             num_forks;
	int             time_to_die;
	int             time_to_eat;
	int             time_to_sleep;
	int             must_eat;
	pthread_mutex_t *forks;
	long int		time_start;
}   g_philos;


typedef struct t_threads
{
	pthread_t       ph_th;
	int             ph_id;
	int             lf_id;
	int             rf_id;
	
}   g_threads;


int     	assign(char **argv, g_philos *philo, int argc);
int     	ft_atoi(const char *str);
int	    	threads_assign(g_philos philos, g_threads *threads);
void    	mutexes_assign(g_philos philos);
long int	time_fun();

#endif
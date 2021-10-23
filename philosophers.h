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
	long long             time_to_die;
	long long           time_to_eat;
	long long            time_to_sleep;
	int             must_eat;
	pthread_mutex_t *forks;
	pthread_mutex_t lock;
}   g_philos;


typedef struct t_threads
{
	pthread_t       ph_th;
	int             ph_id;
	int             lf_id;
	int             rf_id;
	long long			eat_start;
	int				num_eat;
	g_philos 		*data;
}   g_threads;

int     	assign(char **argv, g_philos *philo, int argc);
int     	ft_atoi(const char *str);
int	    	threads_assign(g_philos *philos, g_threads *threads);
int	    	mutexes_assign(g_philos *philos);
long long	time_fun();
void		ft_error(void *pointer);
g_philos	*static_philo(void);
void		philo_fork_print(g_threads *th);
void    	philo_eating_print(g_threads *th);
void    	philo_sleep_print(g_threads *th);
void    	philo_thinking_print(g_threads *th);
void		philo_dies_print(g_threads *th);
int			supervisor(g_threads *threads);
void		ft_usleep(long long time);
#endif
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
	pthread_mutex_t lock;
	// double			*eat_start;
}   g_philos;


typedef struct t_threads
{
	pthread_t       ph_th;
	int             ph_id;
	int             lf_id;
	int             rf_id;
	long int		eat_start;
}   g_threads;

typedef struct t_summary
{
	g_threads	*th;
	g_philos	ph;
}   g_summary;

int     	assign(char **argv, g_summary *sum, int argc);
int     	ft_atoi(const char *str);
int	    	threads_assign(g_summary *sum);
int	    	mutexes_assign(g_summary *sum);
long int	time_fun();
void		ft_error(void *pointer);
g_philos	*static_philo(void);
void		philo_fork_print(g_summary *sum);
void    	philo_eating_print(g_summary *sum);
void    	philo_sleep_print(g_summary *sum);
void    	philo_thinking_print(g_summary *sum);

#endif
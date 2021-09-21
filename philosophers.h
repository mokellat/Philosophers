#ifndef PHILOSOPHERS_C
# define PHILOSOPHERS_C

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>

typedef struct t_philosophers
{
    int num_philos;
    int num_forks;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int must_eat;
}   g_philos;

int assign(char **argv, g_philos *philo, int argc);
int ft_atoi(const char *str);

#endif
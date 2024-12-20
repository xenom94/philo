# ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h> 
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdbool.h>

typedef struct s_philo
{
    int id;
    unsigned long last_meal;
    pthread_t thread;
    pthread_mutex_t mutex;
    struct s_data   *data;
}   t_philo;

typedef struct s_data
{
    int nb_philo;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int nb_must_eat;
    bool check_dead;
    bool stop;
    long start_time;
    pthread_mutex_t *forks;
    pthread_mutex_t print;
    pthread_mutex_t mutex;
    t_philo *philo;
}   t_data;

void is_valid(char **av);
int parse_args(int argc, char **argv, t_data *data);
int assign_philos(t_data *data);
int is_number(char *str);
int input_is_valid(int ac, char **av);
int is_empty(char *str);
int ft_atoi(char *str);




# endif
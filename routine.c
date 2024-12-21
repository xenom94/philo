/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabboudi <iabboudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 04:27:18 by iabboudi          #+#    #+#             */
/*   Updated: 2024/12/21 07:13:18 by iabboudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool close_to_die(t_philo *philo, bool usethemtx)
{   
    int time;
    if(usethemtx)
        pthread_mutex_lock(&philo->mutex);
    time = get_time() - philo->last_meal;
    if (usethemtx)
        pthread_mutex_unlock(&philo->mutex);
    if(time > philo->data->time_to_die)
        return (true);
    return (false);
        
}
bool check_stop(t_data *data)
{
    bool stop;
    pthread_mutex_lock(&data->mutex);
    stop = data->stop;
    pthread_mutex_unlock(&data->mutex);
    return (stop);
}

ft_modulo(int a, int b)
{
    while(a < 0)
        a = a + b;
    return (a % b);
}

void ft_write_message(t_philo *philo, bool status, char *str)
{   
    long long time;
    
    if(!status && close_to_die(philo, false))
        return;
    pthread_mutex_lock(&philo->data->print);
    time = get_time() - philo->data->start_time;
    if (!check_stop(philo->data))
        printf("%lld %d %s\n", time, philo->id, str);
    pthread_mutex_unlock(&philo->data->print);

    
}

void ft_eat(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->forks[(philo->id - 1), philo->data->nb_philo]);
    ft_write_message(philo, false ,"took the fork at the right");    
    
}

void *routine(void *arg)
{
    t_philo *philo;
    int eat_count;

    philo = (t_philo*)arg;
    eat_count = 0;
    
    if (philo->id % 2 == 0)
    usleep((philo->data->time_to_eat / 2) * 1000);

    while(!check_stop(philo->data))
    {
        ft_eat()
    }
}


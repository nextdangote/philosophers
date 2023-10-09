#include "../include/philosophers.h"

void ft_die(t_philo *philo, int i)
{
    philo[i].dead = TRUE;
    ft_print_action("died\n", philo, i);
}

void ft_eat(t_philo *philo, int i)
{
    //struct timeval current_time;

    //gettimeofday(&current_time, NULL);
    if ((get_proper_time() - philo[i].last_meal_time) >= philo->time_to_die)
        ft_die(philo, i);
    //take r_fork and l_fork
    pthread_mutex_lock(&philo[i].right_fork);
    ft_print_action("has taken the right fork\n", philo, i);
    pthread_mutex_lock(&philo[i].left_fork);
    ft_print_action("has taken the left fork\n", philo, i);
    usleep(philo[i].time_to_sleep);
    pthread_mutex_lock(&philo[i].lock);
    ft_print_action("is eating\n", philo, i);
    //update last meal time
    philo[i].last_meal_time = get_proper_time();
    pthread_mutex_unlock(&philo[i].lock);
    //on incremente le nombre de repas mange
    if (philo[i].total_eating_round != '\0' && ++philo[i].eating_round >= philo[i].total_eating_round && i == philo->total_eating_round)
        philo->full = TRUE;
    pthread_mutex_unlock(&philo[i].right_fork);
    pthread_mutex_unlock(&philo[i].right_fork);
    return;
}

void ft_sleep(t_philo *philo, int i)
{
    ft_print_action("is sleeping\n", philo, i);
    pthread_mutex_lock(&philo[i].lock);
    usleep(philo[i].time_to_sleep);
    pthread_mutex_unlock(&philo[i].lock);
    return;
}

void ft_think(t_philo *philo, int i)
{
    pthread_mutex_lock(&philo[i].lock);
    ft_print_action("is thinking\n", philo, i);
    pthread_mutex_unlock(&philo[i].lock);    
    return;
}

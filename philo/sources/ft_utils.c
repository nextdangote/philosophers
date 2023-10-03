#include "../include/philosophers.h"

void    ft_error_message(char *str)
{
    printf("%s\n", str);
    exit(1);
}

void    ft_print_action(char *str, t_philo *philo, int i)
{
    struct timeval current_time;
    gettimeofday(&current_time, NULL);
    pthread_mutex_lock(&philo[i].lock);
    printf("%lu ", current_time.tv_usec - philo->start_time);
    printf("%d ", i);
    printf("%s", str);
    pthread_mutex_unlock(&philo[i].lock);
}

void    ft_destroy(pthread_mutex_t *forks, int amount, t_philo *philo)
{
    int i;

    i = 0;
    while (i < amount)
    {
        pthread_mutex_destroy(&forks[i]);
        pthread_mutex_destroy(&philo[i].lock);
        pthread_mutex_destroy(&philo[i].left_fork);
        pthread_mutex_destroy(&philo[i].right_fork);
        i++;
    }
}

void ft_pjoin(t_philo *philo, pthread_t *threads)
{
    int i;
    int amount;

    i = 0;
    amount = philo[i].amount;
    while (i < amount)
    {
        pthread_join(threads[i], NULL);
        i++;
    }
}
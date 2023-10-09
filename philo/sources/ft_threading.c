#include "../include/philosophers.h"

void    *ft_philo_life_routine(void *param)
{
    t_philo *philo;
    int i;

    philo = param;
    i = philo->index;
    // if (philo->total_eating_round < 0)
    // {
    //     while(i > philo->total_eating_round)
    //     {
    //         ft_eat(philo, i);
    //         ft_sleep(philo, i);
    //         ft_think(philo, i);
    //         i++;
    //     }
    // }
    // else
    // {
    //     while(1)
    //     {
    //         ft_eat(philo, i);
    //         ft_sleep(philo, i);
    //         ft_think(philo, i);
    //         i++;
    //     }
    // }
    if (philo->total_eating_round != 1)
    {
        ft_eat(philo, i);
        ft_sleep(philo, i);
        ft_think(philo, i);
        if (philo->total_eating_round != 0)
            philo->total_eating_round--;
    }
    return (philo);
}

void    ft_threading(pthread_t *threads_phil, t_philo *philo)
{
    int	i;
	int amount_of_threads;
    //pthread_t   checker;

	i = 0;
	amount_of_threads = philo[i].amount;
	//threads_phil = (pthread_t *) malloc (sizeof(pthread_t) * amount_of_threads);
	if(!threads_phil)
		ft_error_message("Error with malloc in threads init\n");
	while(i < amount_of_threads)
	{
		pthread_create(&threads_phil[i], NULL, ft_philo_life_routine, &philo[i]);
        i++;
	}
    //pthread_create(&checker, NULL, ft_checker, &philo);
}

pthread_t  *ft_create_threads(int amount)
{
    pthread_t  *threads;

    threads = (pthread_t *) malloc (sizeof(pthread_t) * amount);
    return(threads);
}
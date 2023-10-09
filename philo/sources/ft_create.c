#include "../include/philosophers.h"

void    ft_init_forks(pthread_mutex_t *fork, int amount, t_philo *philo, char **argv)
{
    int i;

    i = 0;
	fork = (pthread_mutex_t *) malloc (sizeof(pthread_mutex_t) * ft_atoi(argv[1]));
	if (!fork)
		return;
    while (i < amount)
    {
        philo[i].left_fork = fork[i];
        if (i == 0)
            philo[i].right_fork = fork[amount - 1];
        else
            philo[i].right_fork = fork[i - 1];
        i++;
    }
}

t_philo    *ft_init_philos(pthread_mutex_t *forks, t_philo *philo, int argc, char **argv)
{
    int i;
	size_t	time;
	//struct timeval current_time;

    i = 0;
	time = get_proper_time();
    philo = (t_philo *)malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	if (!philo)
		return(NULL);
	//gettimeofday(&current_time, NULL);
	
	while(i < ft_atoi(argv[1]))
	{
		philo[i].full = FALSE;
		philo[i].dead = FALSE;
		philo[i].amount = ft_atoi(argv[1]);
		philo[i].index = i;
		philo[i].start_time = time; //get_proper_time();//current_time.tv_usec;
		philo[i].last_meal_time = time; //get_proper_time();//current_time.tv_usec;
		philo[i].dead = FALSE;
		philo[i].time_to_die = (size_t)ft_atoi(argv[2]);
		philo[i].time_to_eat = (size_t)ft_atoi(argv[3]);
		philo[i].time_to_sleep = (size_t)ft_atoi(argv[4]);
		philo[i].eating_round = 0;
		if(argc == 6)
			philo[i].total_eating_round = ft_atoi(argv[5]) + 1;
		else
			philo[i].total_eating_round = 0;
		i++;
	}
	ft_init_forks(forks, ft_atoi(argv[1]), philo, argv);
	return(philo);
}

// void	ft_init_threads(pthread_t *threads, t_philo *philo)
// {
	
// }

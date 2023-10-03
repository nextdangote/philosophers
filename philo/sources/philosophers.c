#include "../include/philosophers.h"

void    ft_check_arg_for_6(char **argv, int argc)
{
	int i;

	i = 1;
	while(i < argc)
	{
		if(!ft_atoi((const char *)argv[i]))
			ft_error_message(E_NOVALIDNBR);
		i++;
	}
	i = 1;
	while(i < argc + 1)
	{
		if(ft_atoi((const char *)argv[i]) < 0)
			ft_error_message(E_NO_NEG_VAL);
		i++;
	}
	if(ft_atoi((const char *)argv[1]) > 200)
		ft_error_message(E_TOOMUCHPHIL);
	printf("check arg for 6\n");
}

int    ft_check_arg(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc == 6)
		ft_check_arg_for_6(argv, argc - 1);
	else
	{
		while(i < argc)
		{
			if(!ft_atoi((const char *)argv[i]))
				ft_error_message(E_NOVALIDNBR);
			i++;
		}
		i = 1;
		while(i < argc)
		{
			if(ft_atoi((const char *)argv[i]) < 0)
				ft_error_message(E_NO_NEG_VAL);
			i++;
		}
		if(ft_atoi((const char *)argv[1]) > 200)
			ft_error_message(E_TOOMUCHPHIL);
		printf("check arg for 5\n");
	}
	return(1);
}

int main(int argc, char **argv)
{
	t_philo   *philo;
	pthread_t *threads;
	pthread_mutex_t *forks;
	int i;

	i = 0;
	philo = NULL;
	threads = NULL;
	forks = NULL;
	if (argc != 5 && argc != 6)
		ft_error_message(E_WRONGINPUT);
	ft_check_arg(argc , argv);
	// il faudrait initialiser des mutexs dont je ne comprend pas l'utilite encore
	philo = ft_init_philos(forks, philo, argc, argv);
	printf("id : %d\n", philo[0].index);
	printf("id : %d\n", philo[3].index);
	//ft_init_forks(forks, ft_atoi(argv[1]), philo, argv);
	// ft_threading(threads, philo);
	// ft_pjoin(philo, threads);
	// ft_destroy(philo->amount, philo);
	return 0;
}
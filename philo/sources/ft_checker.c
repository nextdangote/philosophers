#include "../include/philosophers.h"

void    ft_check_all_eat(t_philo *philo)
{
    
}

void    ft_check_death(t_philo *philo)
{
    
}

void    *ft_checker(void *param)
{
    t_philo *philo;
    int     i;

    i = 0;
    philo = param;
    //ici on va checker les statuts des philos si il y en a qui sont morts
    //if the philo.dead = TRUE or philo.full = TRUE -> on va arreter le programme
    ft_check_death(philo);
    ft_check_all_eat(philo);
    return(philo);
}
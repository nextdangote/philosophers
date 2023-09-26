#include "../include/philosophers.h"

void    *ft_eat()
{
    printf("I eat\n");
    return NULL;
}

void    *ft_sleep()
{
    printf("I sleep\n");
    return NULL;
}

void    *ft_think()
{
    printf("I think\n");
    return NULL;
}

void    *ft_die()
{
    printf("I died\n");
    return NULL;
}

int main(int argc, char **argv)
{
    pthread_t   philo_1;

    //if (argc != 5 || argc != 6)
        //printf("name of program, number of philosophers, time to die, time to eat, time to sleep, (amount of times each of them eat)");
    pthread_create(&philo_1, NULL, ft_die, NULL);
    pthread_join(philo_1, NULL);

    return 0;
    
}
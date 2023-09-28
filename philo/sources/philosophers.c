#include "../include/philosophers.h"

pthread_mutex_t mutex;

void    *ft_eat()
{
    pthread_mutex_lock(&mutex);
    printf("I eat\n");
    pthread_mutex_unlock(&mutex);

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
    }
    return(1);
}

int main(int argc, char **argv)
{
    pthread_t   philo_1;

    if (argc != 5 && argc != 6)
        ft_error_message(E_WRONGINPUT);
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&philo_1, NULL, ft_die, NULL);
    pthread_join(philo_1, NULL);
    ft_check_arg(argc , argv);


    pthread_mutex_destroy(&mutex);
    return 0;
}

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <stdarg.h>

#define E_TOOMUCHPHIL "Too much philosophers, use max 200\n"
#define E_NO_NEG_VAL "Your values can not be negative\n"
#define E_WRONGINPUT "Your input is not correct, it should be that way :name of program, number of philosophers, time to die, time to eat, time to sleep, (amount of times each of them eat)\n"
#define E_NOVALIDNBR "You can only send numbers brooo and no 0 apart from the amount of times each of them eat\n"

typedef struct s_philo
{
    int nbr;
}   t_philo;

typedef struct s_prog
{
    int nbr;
}   t_prog;
int ft_atoi(const char *str);
void    ft_error_message(char *str);


#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phillos.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skvackov <skvackov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-13 08:37:17 by skvackov          #+#    #+#             */
/*   Updated: 2025-02-13 08:37:17 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>


#define ERROR_MSG "failed.\n"
#define ERROR_MSG_L (sizeof(ERROR_MSG) - 1)
#define SLEEP_MSG "is sleeping\n"
#define SLEEP_MSG_L (sizeof(SLEEP_MSG) - 1)
#define	EAT_MSG "is eating\n"
#define EAT_MSG_L (sizeof(EAT_MSG) - 1)
#define FORK_MSG "has taken a fork\n"
#define FORK_MSG_L (sizeof(FORK_MSG) - 1)
#define THIN_MSG " is thinking\n"
#define THINK_MSG_L (sizeof(THINK_MSG) - 1)

typedef struct waiter
{
    int isforkfree;

}   waiter;

typedef struct forks
{
    int numberofforks;
    pthread_mutex_t *forklocker;
}   forks;

typedef struct myphilonumbers
{
    int numberofphilos;
    int time_to_die;
    int time_to_sleep;
    int time_to_eat;
    int must_eat;
    int eatsleepdie;
}   myphilonumbers;

typedef struct table
{
    myphilonumbers *philos;
    waiter *waiter;
    forks *forks;
    struct timeval start_time;
    struct timeval current_time;
    struct timeval eating;

}   table;

typedef struct onephilo
{
    int philoid;
    table *sharedtable;
} onephilo;


int myatoi(char *str);
// correct time checking
int	countlenght(long lenghtoffuturestr);
void printmyclock(table *philos);
char	*ltoa(long number, int lenght, char *str);
void startspaghettiparty(table *philos);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putstr(char *s);
// void theydie(onephilo *philosopher);


// prekopat structy -> stul s odkazem na phillos a na cisnika.

#endif
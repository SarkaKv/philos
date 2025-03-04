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



typedef struct myphilonumbers
{
    int numberofphilos;
    int numberofforks;
    int time_to_die;
    int time_to_sleep;
    int time_to_eat;
    int must_eat;
    struct timeval start_time;
    struct timeval current_time;
    int eatsleepdie;
    pthread_mutex_t forklock;
}   myphilonumbers;

typedef struct data_philos
{
    int philoid;
    struct timeval eating;
    myphilonumbers *philos;
}   data_philos;

int myatoi(char *str);
// correct time checking
int	countlenght(long lenghtoffuturestr);
void printmyclock(myphilonumbers *philos);
char	*ltoa(long number, int lenght, char *str);
void startspaghettiparty(myphilonumbers *philos);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starttheparty.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skvackov <skvackov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-13 12:02:28 by skvackov          #+#    #+#             */
/*   Updated: 2025-02-13 12:02:28 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h" 

// bool forkchecker(data_philos **waiter)
// {
//     if()
    
// }

void think(data_philos *philosopher)
{
    printmyclock(philosopher->philos);
    printf("%d is thinking\n", philosopher->philoid);
    return;
}

void eatspaghetti(data_philos **forkslifted)
{
    printmyclock()
    printf("%d is eating\n", (*forkslifted)->philoid);
    usleep(200000);
}

void takefork(data_philos *forklift)
{
    int leftfork = forklift->philoid;
    int rightfork = (forklift->philoid+1)%forklift->philos->numberofphilos;
    // if(forkchecker(&forklift) == false)
    // {
    //     return;
    // } 
    pthread_mutex_lock(&forklift->philos->forklocker[leftfork]);
    pthread_mutex_lock(&forklift->philos->forklocker[rightfork]);
    printmyclock(forklift->philos);
    printf("\033[31m%d has taken forks %d and %d\033[0m\n", forklift->philoid, leftfork, rightfork);
    eatspaghetti(&forklift);
    usleep(20000);
    printf("\033[34m%d is done eating\n", forklift->philoid);
    pthread_mutex_unlock(&forklift->philos->forklocker[leftfork]);
    pthread_mutex_unlock(&forklift->philos->forklocker[rightfork]);
    return;
}

void* philoroutine(void *arg)
{
    int test = 4;
    data_philos *data = (data_philos*)arg;
    printf("\033[32mcurrentphilo: %d\033[0m\n", data->philoid);
    while(test>0)
    {
        if(data->philoid % 2 == 0)
            think(data);
        takefork(data);
        think(data);
        test--;
    }
    return NULL;
}

void startspaghettiparty(myphilonumbers *philos)
{
    gettimeofday(&philos->start_time, NULL);
    // printmyclock(philos);
    int philoid = 0;
    int forklockingmutex = 0;
    int nphillos = philos->numberofphilos;
    pthread_t myphilo[nphillos];
    philos->numberofforks = philos->numberofphilos;
    philos->forklocker = malloc(sizeof(pthread_mutex_t) * philos->numberofphilos);
    while(forklockingmutex < nphillos)
    {
        pthread_mutex_init(&philos->forklocker[forklockingmutex], NULL);
        forklockingmutex++;
    }
    data_philos *data = malloc(sizeof(data_philos) * nphillos);
    while(nphillos > 0) 
    {
        data[philoid].philoid = philoid+1;
        data[philoid].philos = philos;
        pthread_create(&myphilo[philoid], NULL, philoroutine, (void*)&data[philoid]);
        nphillos--;
        philoid++;
    }
    usleep(20000000);
}
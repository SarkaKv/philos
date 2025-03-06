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

void eatspaghetti(data_philos *forkslifted)
{
    printmyclock(forkslifted->philos);
    printf("%d is eating\n", forkslifted->philoid);
    usleep(20000);
    pthread_mutex_unlock(&forkslifted->philos->forklock);
}

void takefork(data_philos *forklift)
{
    pthread_mutex_lock(&forklift->philos->forklock);
    int forkstotake = forklift->philos->numberofforks-2;
    while(forklift->philos->numberofforks > forkstotake)
    {
        printmyclock(forklift->philos);
        printf("%d has taken a fork\n", forklift->philoid);
        printf("number of forks: %d\n", forklift->philos->numberofforks);
        forklift->philos->numberofforks--;
        usleep(2000);
    }
    eatspaghetti(forklift);
}

// mutex protects the modifying
void* philoroutine(void *arg)
{
    data_philos *data = (data_philos*)arg;
    int philoid = data->philoid;
    printf("philonumber %d", data->philoid);
    while(philoid > 0)
    {
        takefork(data);
        printf("%d philo is doing anything else\n", data->philoid);
    }
    return NULL;
}
//malloc mutexes, mutex to the actual phillo struct, protect bith forks by mutexes, wrap forks for correct fork taking
void startspaghettiparty(myphilonumbers *philos)
{
    gettimeofday(&philos->start_time, NULL);
    int philoid = 0;
    pthread_t myphilo[philos->numberofphilos];
    philos->numberofforks = philos->numberofphilos;
    pthread_mutex_init(&philos->forklock, NULL);
    // here i have to start with eat sleap etc.
    while(philos->numberofphilos > 0) 
    {
        data_philos *data = malloc(sizeof(data_philos));
        data->philoid = philoid+1;
        data->philos = philos;
        pthread_create(&myphilo[philoid], NULL, philoroutine, (void*)data); 
        philos->numberofphilos--;
        philoid++;
    }
    usleep(20000000);
}

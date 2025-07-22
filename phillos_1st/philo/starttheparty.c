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

int waiterthings(data_philos *canihavfork)
{
    if(canihavfork->isforkfree == 1)
        return(1);
}

void think(data_philos *philosopher)
{
    printmyclock(philosopher->philos);
    printf("%d is thinking\n", philosopher->philoid);
    return;
}

void eatspaghetti(data_philos **forkslifted)
{
    printmyclock((*forkslifted)->philos);
    printf("%d is eating\n", (*forkslifted)->philoid);

}

void takefork(data_philos *forklift)
{
    int leftfork = forklift->philoid;
    int rightfork = (forklift->philoid+1)%forklift->philos->numberofphilos;
    pthread_mutex_lock(&forklift->philos->forklocker[leftfork]);
    pthread_mutex_lock(&forklift->philos->forklocker[rightfork]);
    printmyclock(forklift->philos);
    printf("\033[31m%d has taken forks %d and %d\033[0m\n", forklift->philoid, leftfork, rightfork);
    eatspaghetti(&forklift);
    usleep(20000);
    // printf("\033[34m%d is done eating\n", forklift->philoid);
    pthread_mutex_unlock(&forklift->philos->forklocker[leftfork]);
    pthread_mutex_unlock(&forklift->philos->forklocker[rightfork]);

    return;
}

void* philoroutine(void *arg)
{
    philloscreate *data = (data_philos*)arg;
    // printf("\033[32mcurrentphilo: %d\033[0m\n", data->philoid);
    while(1)
    {
        if(data->philoid % 2 == 0)
        {
            think(data);
            if(askwaiter(data) == 1);
            {
                takefork(data);
                printf("eating was attempted");
            }
        }
        takefork(data);
        usleep(20000);
        think(data);
    }
    return NULL;
}

void startspaghettiparty(table *table)
{
    gettimeofday(&table->start_time, NULL);
    int philoid = 0;
    int forklockingmutex = 0;
    int nphillos = table->philos->numberofphilos;
    pthread_t myphilo[nphillos];
    pthread_t waiter;
    table->forks->numberofforks = nphillos;
    table->forks->forklocker = malloc(sizeof(pthread_mutex_t) * nphillos);
    while(forklockingmutex < nphillos)
    {
        pthread_mutex_init(&table->forks->forklocker[forklockingmutex], NULL);
        forklockingmutex++;
    }
    onephilo *philloscreate = malloc(sizeof(onephilo) * nphillos);
    pthread_create(&waiter, NULL, waiterthings, (void*)philloscreate);
    while(nphillos > 0) 
    {
        philloscreate[philoid].philoid = philoid;
        philloscreate[philoid].philos = table->philos;
        pthread_create(&myphilo[philoid], NULL, philoroutine, (void*)&philloscreate[philoid]);
        nphillos--;
        philoid++;
    }
    usleep(20000000);
}

// void theydie(data_philos *philosopher)
// {
//     printmyclock(philosopher->philos);
//     printf("%d died\n", philosopher->philoid);
// }

// prekopane structy -> table is the main thing with references to other things -> repair the mistakes and continue with waiter so it signals wwhen odd and even phillos can take forkies
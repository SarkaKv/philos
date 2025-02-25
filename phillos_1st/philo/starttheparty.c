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

void philosophersareborn(myphilonumbers *philos)
{
    int *philoid;
    pthread_t myphilo[philos->numberofphilos];
    philos->numberofforks = philos->numberofphilos;
    while(philos->numberofphilos > 0)
    {
        philoid = malloc(sizeof(int));
        *philoid = philos->numberofphilos;
        pthread_create(myphilo, NULL,  ,philos->numberofphilos);
        philos->numberofphilos--;
    }

}

// each phillo a seperate thread - create them mutex the fork - ODD can start with sleep even can start by taking forkies. 
void startspaghettiparty(myphilonumbers *philos)
{
    gettimeofday(&philos->start_time, NULL);
    printmyclock(philos);
    philosophersareborn(philos);
       int *philoid;
    pthread_t myphilo[philos->numberofphilos];
    philos->numberofforks = philos->numberofphilos;
    while(philos->numberofphilos > 0)
    {
        philoid = malloc(sizeof(int));
        *philoid = philos->numberofphilos;
        pthread_create(myphilo, NULL,  ,philos->numberofphilos);
        philos->numberofphilos--;
    }

}
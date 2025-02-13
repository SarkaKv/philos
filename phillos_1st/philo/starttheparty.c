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

void startspaghettiparty(myphilonumbers *philos)
{
    p_thread myphilo;
    philos->numberofforks = philos->numberofphilos;
    while(philos->numberofphilos > 0)
    {
        pthread_create(myphilo, NULL, takefork,philos);
        philos->numberofphilos--;
    }
}
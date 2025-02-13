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

typedef struct myphilonumbers
{
    int numberofphilos;
    int numberofforks;
    int time_to_die;
    int time_to_sleep;
    int time_to_eat;
    int must_eat;

}   myphilonumbers;

int myatoi(char *str);

#endif
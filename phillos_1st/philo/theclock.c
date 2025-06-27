/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   theclock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skvackov <skvackov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-21 09:10:58 by skvackov          #+#    #+#             */
/*   Updated: 2025-02-21 09:10:58 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	*ltoa(long number, int lenght, char *str)
{
    str[lenght] = '\0';
    lenght--;
	if (number == 0)
		str[lenght] = '0';
	else
	{
		while (number > 0)
		{
			str[lenght] = (number % 10) + '0';
			number = number / 10;
            lenght--;
		}
	}
    return(str);
}

int	countlenght(long lenghtoffuturestr)
{
	int	len;

	len = 0;
	if (lenghtoffuturestr == 0)
		return (1);
	while (lenghtoffuturestr > 0)
	{
		lenghtoffuturestr = lenghtoffuturestr / 10;
		len++;
	}
	return (len);
}

void	printmyclock(myphilonumbers *philos)
{
	long	seconds_diff;
	long	usec_diff;
	long	elapsedtimeinms;
	int		lenghtofthetimer;
	char	*to_print;

	gettimeofday(&philos->current_time, NULL);
	seconds_diff = philos->current_time.tv_sec - philos->start_time.tv_sec;
	usec_diff = philos->current_time.tv_usec - philos->start_time.tv_usec;
	elapsedtimeinms = seconds_diff * 1000 + usec_diff / 1000;
	lenghtofthetimer = countlenght(elapsedtimeinms);
	to_print = malloc(sizeof(char) * (lenghtofthetimer + 1));
	if (!to_print)
	{
		write(1, ERROR_MSG, ERROR_MSG_L);
		exit(0);
	}
	ltoa(elapsedtimeinms, lenghtofthetimer, to_print);
	printf("%ld    ", elapsedtimeinms);
	// write(1, to_print, lenghtofthetimer);
	// write(1, " ", 1);
}

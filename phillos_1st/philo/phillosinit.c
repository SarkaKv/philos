/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phillosinit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skvackov <skvackov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-13 08:47:15 by skvackov          #+#    #+#             */
/*   Updated: 2025-02-13 08:47:15 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	validargcheck(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] == '-' || (argv[i] >= 'a' && argv[i] <= 'z'))
		{
			exit(0);
		}
		i++;
	}
	return ;
}
// change atoi to atol
int	main(int argc, char **argv)
{
	int				argcounter;
	myphilonumbers	philos;

	if (argc < 5 || argc > 6)
		return (0);
	argcounter = 1;
	while (argcounter < argc)
	{
		validargcheck(argv[argcounter]);
		argcounter++;
	}
	if (argc >= 5)
	{
		philos.numberofphilos = myatoi(argv[1]);
		philos.time_to_die = myatoi(argv[2]);
		philos.time_to_eat = myatoi(argv[3]);
		philos.time_to_sleep = myatoi(argv[4]);
		philos.must_eat = -1;
	}
	if (argc == 6)
		philos.must_eat = myatoi(argv[5]);
	startspaghettiparty(&philos);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsfromlibft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skvackov <skvackov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-06 09:12:46 by skvackov          #+#    #+#             */
/*   Updated: 2025-03-06 09:12:46 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
	}
	if (n >= 0 && n <= 9)
		ft_putchar(n + '0');
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

void	ft_putstr(char *s)
{
	int	oki;

	oki = 0;
	while (s[oki] != '\0')
	{
		ft_putchar(s[oki]);
		oki++;
	}
}

int	myatoi(char *str)
{
	int	results;

	results = 0;
	while (*str)
	{
		results = results * 10 + (*str - '0');
		str++;
	}
	return (results);
}

//make this so it prints the whole line preferably and the number. (2 functions)
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 17:04:28 by melshata          #+#    #+#             */
/*   Updated: 2026/01/18 18:54:24 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

#include "../ft_printf/ft_printf.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	int		neg;
	long	num;

	i = 0;
	neg = 1;
	num = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			neg = -neg;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		num = num * 10 + (nptr[i++] - '0');
	return ((int)(num * neg));
}

int	main(int ac, char **av)
{
	int		i;
	int		s_pid;
	char	*c;

	if (ac != 3)
	{
		ft_printf ("Error\nmust take -server_pid- -message-\n");
		return (0);
	}
	s_pid = ft_atoi (av[1]);
	ft_printf ("s_pid: %d\n", s_pid);
	c = av[2];
	while (*c)
	{
		i = 0;
		while (i < 8)
		{
			if (((*c) >> i++) % 2 == 1)
				kill (s_pid, SIGUSR1);
			else
				kill (s_pid, SIGUSR2);
			usleep (50);
		}
		ft_printf ("char: %c\n", *c);
		c++;
	}
	i = 0;
	while (i < 8)
	{
		if (((*c) >> i++) % 2 == 1)
			kill (s_pid, SIGUSR2);
		else
			kill (s_pid, SIGUSR1);
		usleep (500);
	}
	return (0);
}

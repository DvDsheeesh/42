/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 17:04:28 by melshata          #+#    #+#             */
/*   Updated: 2026/01/19 19:31:55 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

#include "../ft_printf/ft_printf.h"

int	g_var;

int	ft_atoi(const char *nptr)
{
	int		i;
	int		neg;
	long	num;

	i = 0;
	neg = 1;
	num = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		num = num * 10 + (nptr[i++] - '0');
	if (nptr[i])
	{
		write (2, "Error\nwrong input format\n", 25);
		exit (1);
	}
	return ((int)(num * neg));
}

void	ack_receiver(int sig)
{
	(void)sig;
	g_var = 1;
}

void	str_sender(char *c, int s_pid)
{
	int		i;

	while (*c || *(c - 1))
	{
		i = 8;
		while (i > 0)
		{
			g_var = 0;
			if (((*c) >> --i) % 2 == 1)
				kill (s_pid, SIGUSR2);
			else
				kill (s_pid, SIGUSR1);
			while (!g_var)
				;
		}
		if (!(*c))
			break ;
		c++;
	}
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		ft_printf ("Error\nmust take -server_pid- -message-\n");
		return (0);
	}
	signal (SIGUSR1, ack_receiver);
	str_sender (av[2], ft_atoi (av[1]));
	return (0);
}

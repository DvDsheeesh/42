/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 16:48:01 by melshata          #+#    #+#             */
/*   Updated: 2026/06/24 16:55:47 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	my_int_length(long n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		i;
	long	num;

	num = n;
	s = (char *)malloc (my_int_length(num) + 1);
	if (!s)
		return (NULL);
	s[my_int_length(num)] = '\0';
	i = 0;
	if (num < 0)
	{
		s[0] = '-';
		num = -num;
		i = 1;
	}
	if (num == 0)
		s[0] = '0';
	while (num)
	{
		s[my_int_length(num) - 1 + i] = (char)((num % 10) + 48);
		num /= 10;
	}
	return (s);
}

void	print_configs(t_config config)
{
	ft_putstr_fd("number_of_philosophers: ", 1);
	ft_putstr_fd(ft_itoa(config.number_of_philosophers), 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("time_to_die: ", 1);
	ft_putstr_fd(ft_itoa(config.time_to_die), 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("time_to_eat: ", 1);
	ft_putstr_fd(ft_itoa(config.time_to_eat), 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("time_to_sleep: ", 1);
	ft_putstr_fd(ft_itoa(config.time_to_sleep), 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("must_eat_count: ", 1);
	ft_putstr_fd(ft_itoa(config.must_eat_count), 1);
	ft_putstr_fd("\n", 1);
}

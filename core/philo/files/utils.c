/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 13:52:16 by melshata          #+#    #+#             */
/*   Updated: 2026/06/27 13:11:41 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	all_numbers(const char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	long	res;
	int		i;

	res = 0;
	i = 0;
	while (str[i])
	{
		res = res * 10 + (str[i] - '0');
		if (res > INT_MAX)
			return (-1);
		i++;
	}
	return ((int)res);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	len;

	len = 0;
	if (!str)
		return ;
	while (str[len])
		len++;
	write(fd, str, len);
}

size_t	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((size_t)(tv.tv_sec * 1000 + tv.tv_usec / 1000));
}

void	ft_usleep(long ms, t_philo *philo)
{
	size_t	start;

	start = get_time_ms();
	while ((long)(get_time_ms() - start) < ms)
	{
		if (is_simulation_stopped(philo->data))
			break ;
		usleep(500);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 13:51:34 by melshata          #+#    #+#             */
/*   Updated: 2026/06/26 13:51:36 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	validate_args(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!all_numbers(av[i]))
		{
			ft_putstr_fd("ERROR: arguments must be positive numbers\n", 2);
			exit(1);
		}
		i++;
	}
}

static void	check_values(t_data *data, int ac)
{
	if (data->config.number_of_philosophers <= 0
		|| data->config.time_to_die <= 0
		|| data->config.time_to_eat <= 0
		|| data->config.time_to_sleep <= 0
		|| (ac == 6 && data->config.must_eat_count <= 0))
	{
		ft_putstr_fd("ERROR: arguments must be positive\n", 2);
		exit(1);
	}
}

void	parse_args(t_data *data, int ac, char **av)
{
	validate_args(ac, av);
	data->config.number_of_philosophers = ft_atoi(av[1]);
	data->config.time_to_die = ft_atoi(av[2]);
	data->config.time_to_eat = ft_atoi(av[3]);
	data->config.time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->config.must_eat_count = ft_atoi(av[5]);
	else
		data->config.must_eat_count = -1;
	check_values(data, ac);
}

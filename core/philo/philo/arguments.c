/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 16:50:19 by melshata          #+#    #+#             */
/*   Updated: 2026/06/24 16:56:25 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	validate_args(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!all_numbers(av[i]))
		{
			ft_putstr_fd("ERROR: non-numeric values found.", 2);
			exit(1);
		}
		i++;
	}
}

void	check_args_number(t_config *config, int ac, char **av)
{
	if (ac == 6)
		config->must_eat_count = ft_atoi(av[5]);
	else if (ac == 5)
		config->must_eat_count = -1;
	else
	{
		ft_putstr_fd("ERROR: bad number of arguments\n", 2);
		ft_putstr_fd("    must be:\n", 2);
		ft_putstr_fd("	number_of_philosophers time_to_die ", 2);
		ft_putstr_fd("time_to_eat time_to_sleep [number_of_meals]\n", 2);
		exit(1);
	}
}

t_config	parse_args(int ac, char **av)
{
	t_config	config;

	validate_args(ac, av);
	check_args_number(&config, ac, av);
	config.number_of_philosophers = ft_atoi(av[1]);
	config.time_to_die = ft_atoi(av[2]);
	config.time_to_eat = ft_atoi(av[3]);
	config.time_to_sleep = ft_atoi(av[4]);
	return (config);
}

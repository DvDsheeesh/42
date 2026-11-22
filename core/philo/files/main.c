/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 13:51:42 by melshata          #+#    #+#             */
/*   Updated: 2026/06/26 13:51:44 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	create_threads(t_data *data, pthread_t *monitor)
{
	int	i;

	i = 0;
	while (i < data->config.number_of_philosophers)
	{
		data->philos[i].last_meal_time = data->start_time;
		if (pthread_create(&data->philos[i].thread, NULL,
				philo_routine, &data->philos[i]) != 0)
			return (0);
		i++;
	}
	if (pthread_create(monitor, NULL, monitor_routine, data) != 0)
		return (0);
	return (1);
}

static void	join_threads(t_data *data, pthread_t monitor)
{
	int	i;

	i = 0;
	while (i < data->config.number_of_philosophers)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
	pthread_join(monitor, NULL);
}

int	main(int ac, char **av)
{
	t_data		data;
	pthread_t	monitor;

	if (ac != 5 && ac != 6)
	{
		ft_putstr_fd("ERROR: wrong number of arguments\n", 2);
		ft_putstr_fd("usage: ./philo number_of_philos time_to_die ", 2);
		ft_putstr_fd("time_to_eat time_to_sleep [number_of_meals]\n", 2);
		return (1);
	}
	parse_args(&data, ac, av);
	if (!init_data(&data))
		return (1);
	data.start_time = get_time_ms();
	if (!create_threads(&data, &monitor))
	{
		ft_putstr_fd("ERROR: thread creation failed\n", 2);
		return (1);
	}
	join_threads(&data, monitor);
	destroy_data(&data);
	return (0);
}

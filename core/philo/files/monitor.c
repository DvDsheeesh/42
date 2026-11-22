/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 13:51:39 by melshata          #+#    #+#             */
/*   Updated: 2026/06/27 10:10:32 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_all_full(t_data *data)
{
	int	i;
	int	full_count;

	if (data->config.must_eat_count <= 0)
		return (0);
	full_count = 0;
	i = 0;
	while (i < data->config.number_of_philosophers)
	{
		pthread_mutex_lock(&data->philos[i].meal_lock);
		if (data->philos[i].meals_eaten >= data->config.must_eat_count)
			full_count++;
		pthread_mutex_unlock(&data->philos[i].meal_lock);
		i++;
	}
	if (full_count == data->config.number_of_philosophers)
	{
		stop_simulation(data);
		return (1);
	}
	return (0);
}

void	*monitor_routine(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (!is_simulation_stopped(data))
	{
		if (check_death(data))
			break ;
		if (check_all_full(data))
			break ;
		usleep(1000);
	}
	return (NULL);
}

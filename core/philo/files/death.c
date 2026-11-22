/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 13:54:50 by melshata          #+#    #+#             */
/*   Updated: 2026/06/27 12:33:26 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_simulation_stopped(t_data *data)
{
	int	stop;

	pthread_mutex_lock(&data->state_lock);
	stop = data->simulation_stop;
	pthread_mutex_unlock(&data->state_lock);
	return (stop);
}

void	stop_simulation(t_data *data)
{
	pthread_mutex_lock(&data->state_lock);
	data->simulation_stop = 1;
	pthread_mutex_unlock(&data->state_lock);
}

static int	philo_is_dead(t_philo *philo, size_t now)
{
	size_t	last_meal;

	pthread_mutex_lock(&philo->meal_lock);
	last_meal = philo->last_meal_time;
	pthread_mutex_unlock(&philo->meal_lock);
	return ((long)(now - last_meal) > philo->data->config.time_to_die);
}

int	check_death(t_data *data)
{
	int		i;
	size_t	now;

	i = 0;
	while (i < data->config.number_of_philosophers)
	{
		now = get_time_ms();
		if (philo_is_dead(&data->philos[i], now))
		{
			pthread_mutex_lock(&data->state_lock);
			if (!data->simulation_stop)
			{
				data->simulation_stop = 1;
				printf("%zu %d has died\n", now - data->start_time,
					data->philos[i].id);
			}
			pthread_mutex_unlock(&data->state_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

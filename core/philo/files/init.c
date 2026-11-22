/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 13:51:59 by melshata          #+#    #+#             */
/*   Updated: 2026/06/26 13:52:00 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	alloc_data(t_data *data)
{
	int	n;

	n = data->config.number_of_philosophers;
	data->forks = malloc(sizeof(pthread_mutex_t) * n);
	if (!data->forks)
		return (0);
	data->philos = malloc(sizeof(t_philo) * n);
	if (!data->philos)
	{
		free(data->forks);
		return (0);
	}
	return (1);
}

static void	init_mutexes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->config.number_of_philosophers)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&data->state_lock, NULL);
}

static void	init_philos(t_data *data)
{
	int	i;
	int	n;

	n = data->config.number_of_philosophers;
	i = 0;
	while (i < n)
	{
		data->philos[i].id = i + 1;
		data->philos[i].left_fork = i;
		data->philos[i].right_fork = (i + 1) % n;
		data->philos[i].meals_eaten = 0;
		data->philos[i].last_meal_time = 0;
		data->philos[i].data = data;
		pthread_mutex_init(&data->philos[i].meal_lock, NULL);
		i++;
	}
}

int	init_data(t_data *data)
{
	if (!alloc_data(data))
	{
		ft_putstr_fd("ERROR: allocation failed\n", 2);
		return (0);
	}
	data->simulation_stop = 0;
	init_mutexes(data);
	init_philos(data);
	return (1);
}

void	destroy_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->config.number_of_philosophers)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].meal_lock);
		i++;
	}
	pthread_mutex_destroy(&data->state_lock);
	free(data->forks);
	free(data->philos);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 13:52:12 by melshata          #+#    #+#             */
/*   Updated: 2026/06/27 13:10:11 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	take_forks(t_philo *philo, int *first, int *second)
{
	if (philo->left_fork < philo->right_fork)
	{
		*first = philo->left_fork;
		*second = philo->right_fork;
	}
	else
	{
		*first = philo->right_fork;
		*second = philo->left_fork;
	}
	pthread_mutex_lock(&philo->data->forks[*first]);
	if (!is_simulation_stopped(philo->data))
		safe_print(philo, "has taken a fork");
	pthread_mutex_lock(&philo->data->forks[*second]);
	if (!is_simulation_stopped(philo->data))
		safe_print(philo, "has taken a fork");
}

static void	philo_eat(t_philo *philo)
{
	int	first;
	int	second;

	take_forks(philo, &first, &second);
	if (!is_simulation_stopped(philo->data))
	{
		pthread_mutex_lock(&philo->meal_lock);
		philo->last_meal_time = get_time_ms();
		philo->meals_eaten++;
		pthread_mutex_unlock(&philo->meal_lock);
		safe_print(philo, "is eating");
		ft_usleep(philo->data->config.time_to_eat, philo);
	}
	pthread_mutex_unlock(&philo->data->forks[second]);
	pthread_mutex_unlock(&philo->data->forks[first]);
}

static int	philo_life_cycle(t_philo *philo)
{
	if (is_simulation_stopped(philo->data))
		return (0);
	philo_eat(philo);
	if (is_simulation_stopped(philo->data))
		return (0);
	if (is_simulation_stopped(philo->data))
		return (0);
	safe_print(philo, "is sleeping");
	if (is_simulation_stopped(philo->data))
		return (0);
	ft_usleep(philo->data->config.time_to_sleep, philo);
	if (is_simulation_stopped(philo->data))
		return (0);
	safe_print(philo, "is thinking");
	if (is_simulation_stopped(philo->data))
		return (0);
	return (1);
}

static void	single_philo_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[0]);
	safe_print(philo, "has taken a fork");
	while (!is_simulation_stopped(philo->data))
		ft_usleep(1, philo);
	pthread_mutex_unlock(&philo->data->forks[0]);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	int		stopped;

	philo = (t_philo *)arg;
	if (philo->data->config.number_of_philosophers == 1)
	{
		single_philo_routine(philo);
		return (NULL);
	}
	if (philo->id % 2 != 0)
		ft_usleep(20, philo);
	stopped = 0;
	while (!is_simulation_stopped(philo->data) && !stopped)
		stopped = !philo_life_cycle(philo);
	return (NULL);
}

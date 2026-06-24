#include "philo.h"

int	free_forks_philos(t_data *data)
{
	if (data->philos)
		free(data->philos);
	if (data->forks)
		free(data->forks);
	return (0);
}

int	init_philosophers_loop(t_data *data)
{
	int	index;

	index = 0;
	while (index < data->philo_count)
	{
		if (pthread_mutex_init(&data->forks[index], NULL) != 0)
		{
			destroy_mutexes(data, index - 1);
			return (0);
		}
		init_philosopher(data, index);
		index++;
	}
	return (1);
}

void	destroy_mutexes(t_data *data, int initialized_forks)
{
	int	index;

	index = 0;
	while (index < initialized_forks)
	{
		pthread_mutex_destroy(&data->forks[index]);
		index++;
	}
	if (initialized_forks >= 0)
	{
		pthread_mutex_destroy(&data->print_mutex);
		pthread_mutex_destroy(&data->death_mutex);
		pthread_mutex_destroy(&data->meal_mutex);
	}
}

void	init_philosopher(t_data *data, int index)
{
	int	left;
	int	right;

	data->philos[index].id = index + 1;
	left = index;
	right = (index + 1) % data->philo_count;
	data->philos[index].left_fork = left;
	data->philos[index].right_fork = right;
	if (left < right)
	{
		data->philos[index].first_fork = left;
		data->philos[index].second_fork = right;
	}
	else
	{
		data->philos[index].first_fork = right;
		data->philos[index].second_fork = left;
	}
	data->philos[index].meals_eaten = 0;
	data->philos[index].data = data;
}

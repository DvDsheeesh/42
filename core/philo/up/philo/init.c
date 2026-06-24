#include "philo.h"

int	init_general_mutexes(t_data *data)
{
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&data->death_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&data->print_mutex);
		return (0);
	}
	if (pthread_mutex_init(&data->meal_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&data->print_mutex);
		pthread_mutex_destroy(&data->death_mutex);
		return (0);
	}
	return (1);
}

int	allocate_data_arrays(t_data *data, int philo_count)
{
	data->forks = malloc(sizeof(pthread_mutex_t) * philo_count);
	if (!data->forks)
		return (0);
	data->philos = malloc(sizeof(t_philo) * philo_count);
	if (!data->philos)
	{
		free(data->forks);
		data->forks = NULL;
		return (0);
	}
	return (1);
}

int	init_data(t_data *data, const t_config *config)
{
	int	index;

	data->philo_count = config->number_of_philosophers;
	data->config = *config;
	data->start_time = get_time();
	data->dead = 0;
	if (!allocate_data_arrays(data, data->philo_count))
		return (0);
	if (!init_general_mutexes(data))
		return (free_forks_philos(data));
	if (!init_philosophers_loop(data))
		return (free_forks_philos(data));
	index = 0;
	while (index < data->philo_count)
	{
		data->philos[index].last_meal = data->start_time;
		index++;
	}
	return (1);
}

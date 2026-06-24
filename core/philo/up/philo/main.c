#include "philo.h"

void	join_philosophers(t_data *data)
{
	int	index;

	index = 0;
	while (index < data->philo_count)
	{
		pthread_join(data->threads[index], NULL);
		index++;
	}
}

void	free_data(t_data *data)
{
	int	index;

	if (data->threads)
		free(data->threads);
	index = 0;
	while (index < data->philo_count)
	{
		pthread_mutex_destroy(&data->forks[index]);
		index++;
	}
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->death_mutex);
	pthread_mutex_destroy(&data->meal_mutex);
	free(data->philos);
	free(data->forks);
	data->threads = NULL;
	data->philos = NULL;
	data->forks = NULL;
}

int	main(int argc, char **argv)
{
	t_config	config;
	t_data		data;
	pthread_t	monitor;

	config = (t_config){0};
	data = (t_data){0};
	if (!parse_arguments(argc, argv, &config) || !init_data(&data, &config))
		return (1);
	if (pthread_create(&monitor, NULL, monitor_routine, &data) != 0)
	{
		free_data(&data);
		return (1);
	}
	if (!start_threads(&data))
	{
		set_dead(&data);
		pthread_join(monitor, NULL);
		free_data(&data);
		return (1);
	}
	pthread_join(monitor, NULL);
	set_dead(&data);
	join_philosophers(&data);
	free_data(&data);
	return (0);
}

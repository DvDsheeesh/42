#include "philo.h"
#include <fcntl.h>

int	open_named_sem(sem_t **sem, const char *name, int value)
{
	sem_unlink(name);
	*sem = sem_open(name, O_CREAT | O_EXCL, 0644, value);
	return (*sem == SEM_FAILED);
}

int	open_core_semaphores(t_data *data)
{
	if (open_named_sem(&data->forks, "forks", data->philo_count))
		return (0);
	if (open_named_sem(&data->print_sem, "print", 1))
		return (0);
	if (open_named_sem(&data->death_sem, "death", 1))
		return (0);
	{
		if (open_named_sem(&data->take_sem, "take", data->philo_count / 2
				+ data->philo_count % 2))
			return (0);
	}
	return (1);
}

int	init_general_semaphores(t_data *data)
{
	data->forks = NULL;
	data->print_sem = NULL;
	data->death_sem = NULL;
	data->take_sem = NULL;
	if (!open_core_semaphores(data))
		return (destroy_semaphores(data), 0);
	return (1);
}

int	allocate_data_arrays(t_data *data, int philo_count)
{
	int	index;

	index = 0;
	data->pids = malloc(sizeof(pid_t) * philo_count);
	if (!data->pids)
		return (0);
	while (index < philo_count)
	{
		data->pids[index] = -1;
		index++;
	}
	data->philos = malloc(sizeof(t_philo) * philo_count);
	if (!data->philos)
	{
		free(data->pids);
		data->pids = NULL;
		return (0);
	}
	data->pipes = NULL;
	return (1);
}

int	init_data(t_data *data, const t_config *config)
{
	int	index;

	data->philo_count = config->number_of_philosophers;
	data->config = *config;
	data->start_time = get_time();
	data->someone_died = 0;
	if (!allocate_data_arrays(data, data->philo_count))
		return (0);
	if (!init_general_semaphores(data))
		return (free_forks_philos(data));
	index = 0;
	while (index < data->philo_count)
	{
		init_philosopher(data, index);
		index++;
	}
	return (1);
}

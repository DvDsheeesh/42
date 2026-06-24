#include "philo.h"
#include <fcntl.h>

void	destroy_semaphores(t_data *data)
{
	if (data->forks != NULL)
		sem_close(data->forks);
	if (data->print_sem != NULL)
		sem_close(data->print_sem);
	if (data->death_sem != NULL)
		sem_close(data->death_sem);
	if (data->take_sem != NULL)
		sem_close(data->take_sem);
	sem_unlink("forks");
	sem_unlink("print");
	sem_unlink("death");
	sem_unlink("take");
}

int	free_forks_philos(t_data *data)
{
	if (data->philos)
		free(data->philos);
	if (data->pids)
		free(data->pids);
	if (data->pipes)
		free(data->pipes);
	return (0);
}

void	init_philosopher(t_data *data, int index)
{
	data->philos[index].id = index + 1;
	data->philos[index].pid = -1;
	data->philos[index].meals_eaten = 0;
	data->philos[index].pipe_fd = -1;
	data->philos[index].data = data;
	data->philos[index].died = 0;
	data->philos[index].last_meal = data->start_time;
}

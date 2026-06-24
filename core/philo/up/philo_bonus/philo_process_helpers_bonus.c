#include "philo.h"
#include <pthread.h>

int	take_forks_and_eat(t_philo *philo, t_data *data)
{
	if (take_first_fork(philo, data) == -1)
		return (-1);
	if (take_second_fork(philo, data) == -1)
		return (-1);
	sem_wait(data->death_sem);
	philo->last_meal = get_time();
	sem_post(data->death_sem);
	if (!has_died(philo))
		safe_print(data, timestamp(data), philo->id, " is eating\n");
	ft_usleep(data->config.time_to_eat);
	philo->meals_eaten++;
	sem_post(data->forks);
	sem_post(data->forks);
	if (data->config.must_eat_count > 0
		&& philo->meals_eaten == data->config.must_eat_count)
		return (1);
	return (0);
}

int	take_first_fork(t_philo *philo, t_data *data)
{
	sem_wait(data->take_sem);
	if (has_died(philo))
	{
		sem_post(data->take_sem);
		return (-1);
	}
	sem_wait(data->forks);
	if (has_died(philo))
	{
		sem_post(data->take_sem);
		sem_post(data->forks);
		return (-1);
	}
	if (!has_died(philo))
		safe_print(data, timestamp(data), philo->id, " has taken a fork\n");
	return (0);
}

int	take_second_fork(t_philo *philo, t_data *data)
{
	if (data->philo_count == 1)
	{
		sem_post(data->take_sem);
		while (1)
		{
			if (has_died(philo))
				return (-1);
			usleep(500);
		}
	}
	sem_wait(data->forks);
	if (has_died(philo))
	{
		sem_post(data->take_sem);
		sem_post(data->forks);
		sem_post(data->forks);
		return (-1);
	}
	sem_post(data->take_sem);
	if (!has_died(philo))
		safe_print(data, timestamp(data), philo->id, " has taken a fork\n");
	return (0);
}

int	sleep_and_think(t_philo *philo, t_data *data)
{
	if (!has_died(philo))
		safe_print(data, timestamp(data), philo->id, " is sleeping\n");
	ft_usleep(data->config.time_to_sleep);
	if (has_died(philo))
		return (-1);
	if (!has_died(philo))
		safe_print(data, timestamp(data), philo->id, " is thinking\n");
	if (data->philo_count % 2 != 0)
		ft_usleep(data->config.time_to_eat / 2);
	if (has_died(philo))
		return (-1);
	return (0);
}

void	clane_routine(t_data *data)
{
	sem_close(data->forks);
	sem_close(data->take_sem);
	sem_close(data->death_sem);
	sem_close(data->print_sem);
	free(data->philos);
	free(data->pids);
	if (data->someone_died)
		exit(1);
	else
		exit(0);
}

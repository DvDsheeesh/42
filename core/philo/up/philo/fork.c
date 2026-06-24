#include "philo.h"

int	handle_single_fork(t_data *data, t_philo *philo, int fork)
{
	if (fork == philo->left_fork && fork == philo->right_fork)
	{
		pthread_mutex_lock(&data->forks[fork]);
		safe_print(data, timestamp(data), philo->id, " has taken a fork\n");
		while (!is_dead(data))
			usleep(200);
		pthread_mutex_unlock(&data->forks[fork]);
		return (1);
	}
	return (0);
}

int	acquire_first_fork(t_data *data, t_philo *philo, int first_fork)
{
	pthread_mutex_lock(&data->forks[first_fork]);
	if (is_dead(data))
	{
		pthread_mutex_unlock(&data->forks[first_fork]);
		return (0);
	}
	safe_print(data, timestamp(data), philo->id, " has taken a fork\n");
	return (1);
}

int	acquire_second_fork(t_data *data, t_philo *philo,
						int first_fork, int second_fork)
{
	pthread_mutex_lock(&data->forks[second_fork]);
	if (is_dead(data))
	{
		pthread_mutex_unlock(&data->forks[first_fork]);
		pthread_mutex_unlock(&data->forks[second_fork]);
		return (0);
	}
	safe_print(data, timestamp(data), philo->id, " has taken a fork\n");
	return (1);
}

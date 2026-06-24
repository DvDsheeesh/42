#include "philo.h"

int	process_eating(t_data *data, t_philo *philo, int first_fork,
		int second_fork)
{
	if (!acquire_first_fork(data, philo, first_fork))
		return (0);
	if (!acquire_second_fork(data, philo, first_fork, second_fork))
		return (0);
	pthread_mutex_lock(&data->meal_mutex);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&data->meal_mutex);
	safe_print(data, timestamp(data), philo->id, " is eating\n");
	ft_usleep(data, data->config.time_to_eat);
	pthread_mutex_lock(&data->meal_mutex);
	philo->meals_eaten++;
	pthread_mutex_unlock(&data->meal_mutex);
	pthread_mutex_unlock(&data->forks[first_fork]);
	pthread_mutex_unlock(&data->forks[second_fork]);
	return (1);
}

int	check_must_eat_count(t_data *data, t_philo *philo)
{
	if (data->config.must_eat_count <= 0)
		return (0);
	pthread_mutex_lock(&data->meal_mutex);
	if (philo->meals_eaten >= data->config.must_eat_count)
	{
		pthread_mutex_unlock(&data->meal_mutex);
		return (1);
	}
	pthread_mutex_unlock(&data->meal_mutex);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	if (philo->id % 2 == 0)
		ft_usleep(data, data->config.time_to_eat / 2);
	while (!is_dead(data))
	{
		if (check_must_eat_count(data, philo) || handle_single_fork(data, philo,
				philo->first_fork) || !process_eating(data, philo,
				philo->first_fork, philo->second_fork))
			break ;
		if (is_dead(data))
			break ;
		safe_print(data, timestamp(data), philo->id, " is sleeping\n");
		ft_usleep(data, data->config.time_to_sleep);
		if (is_dead(data))
			break ;
		safe_print(data, timestamp(data), philo->id, " is thinking\n");
		if (data->philo_count % 2 != 0)
			ft_usleep(data, data->config.time_to_eat / 2);
	}
	return (NULL);
}

int	start_threads(t_data *data)
{
	int	index;

	data->threads = malloc(sizeof(pthread_t) * data->philo_count);
	if (!data->threads)
		return (0);
	index = 0;
	while (index < data->philo_count)
	{
		if (pthread_create(&data->threads[index], NULL, routine,
				&data->philos[index]) != 0)
		{
			set_dead(data);
			while (index > 0)
			{
				index--;
				pthread_join(data->threads[index], NULL);
			}
			return (0);
		}
		index++;
	}
	return (1);
}

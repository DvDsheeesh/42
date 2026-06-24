#include "philo.h"

int	are_all_philosophers_full(t_data *data)
{
	int	index;
	int	all_full;

	index = 0;
	all_full = 1;
	while (index < data->philo_count)
	{
		pthread_mutex_lock(&data->meal_mutex);
		if (data->philos[index].meals_eaten < data->config.must_eat_count)
			all_full = 0;
		pthread_mutex_unlock(&data->meal_mutex);
		if (!all_full)
			break ;
		index++;
	}
	return (all_full);
}

void	set_dead(t_data *data)
{
	pthread_mutex_lock(&data->death_mutex);
	data->dead = 1;
	pthread_mutex_unlock(&data->death_mutex);
}

void	check_philosopher_death(t_data *data, int index)
{
	long long	last_meal;
	long long	death_time;

	pthread_mutex_lock(&data->meal_mutex);
	last_meal = data->philos[index].last_meal;
	pthread_mutex_unlock(&data->meal_mutex);
	if ((get_time() - last_meal) > data->config.time_to_die)
	{
		death_time = timestamp(data);
		set_dead(data);
		pthread_mutex_lock(&data->print_mutex);
		printf("%lld %d died\n", death_time, data->philos[index].id);
		pthread_mutex_unlock(&data->print_mutex);
	}
}

int	is_dead(t_data *data)
{
	int	is_dead_flag;

	pthread_mutex_lock(&data->death_mutex);
	is_dead_flag = data->dead;
	pthread_mutex_unlock(&data->death_mutex);
	return (is_dead_flag);
}

void	*monitor_routine(void *arg)
{
	t_data	*data;
	int		index;

	data = (t_data *)arg;
	while (!is_dead(data))
	{
		index = 0;
		while (index < data->philo_count)
		{
			check_philosopher_death(data, index);
			if (is_dead(data))
				return (NULL);
			index++;
		}
		if (data->config.must_eat_count > 0 && are_all_philosophers_full(data))
			set_dead(data);
		usleep(500);
	}
	return (NULL);
}

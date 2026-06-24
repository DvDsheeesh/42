#include "philo.h"

long long	get_time(void)
{
	t_timeval	time_value;

	gettimeofday(&time_value, NULL);
	return ((time_value.tv_sec * 1000LL) + (time_value.tv_usec / 1000));
}

long long	timestamp(t_data *data)
{
	return (get_time() - data->start_time);
}

void	ft_usleep(t_data *data, long long milliseconds)
{
	long long	start_time;

	start_time = get_time();
	while ((get_time() - start_time) < milliseconds && !is_dead(data))
		usleep(500);
}

void	safe_print(t_data *data, long long timestamp, int id, const char *msg)
{
	pthread_mutex_lock(&data->death_mutex);
	if (data->dead)
	{
		pthread_mutex_unlock(&data->death_mutex);
		return ;
	}
	pthread_mutex_lock(&data->print_mutex);
	pthread_mutex_unlock(&data->death_mutex);
	printf("%lld %d%s", timestamp, id, msg);
	pthread_mutex_unlock(&data->print_mutex);
}

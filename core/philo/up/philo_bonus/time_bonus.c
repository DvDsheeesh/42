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

void	ft_usleep(long long milliseconds)
{
	long long	start_time;

	start_time = get_time();
	while ((get_time() - start_time) < milliseconds)
		usleep(200);
}

void	safe_print(t_data *data, long long timestamp, int id, char *msg)
{
	sem_wait(data->print_sem);
	printf("%lld %d%s", timestamp, id, msg);
	sem_post(data->print_sem);
}

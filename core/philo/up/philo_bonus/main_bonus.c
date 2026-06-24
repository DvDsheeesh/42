#include "philo.h"
#include <pthread.h>

int	main(int argc, char **argv)
{
	t_config	config;
	t_data		data;

	config = (t_config){0};
	data = (t_data){0};
	if (!parse_arguments(argc, argv, &config) || !init_data(&data, &config))
		return (1);
	if (!start_processes(&data))
	{
		cleanup_data(&data);
		return (1);
	}
	monitor_philosophers(&data);
	cleanup_data(&data);
	return (0);
}

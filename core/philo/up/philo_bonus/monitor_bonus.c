#include "philo.h"
#include <signal.h>
#include <sys/wait.h>

void	monitor_philosophers(t_data *data)
{
	int	status;
	int	i;
	int	pid;

	while (1)
	{
		pid = waitpid(-1, &status, 0);
		if (pid <= 0)
			break ;
		if (WIFEXITED(status) && WEXITSTATUS(status) == 1)
		{
			i = 0;
			while (i < data->philo_count)
				kill(data->pids[i++], SIGKILL);
			while (waitpid(-1, NULL, 0) > 0)
				;
			return ;
		}
	}
}

void	cleanup_data(t_data *data)
{
	destroy_semaphores(data);
	if (data->pipes)
	{
		free(data->pipes);
		data->pipes = NULL;
	}
	if (data->pids)
	{
		free(data->pids);
		data->pids = NULL;
	}
	if (data->philos)
	{
		free(data->philos);
		data->philos = NULL;
	}
}

#include "philo.h"
#include <pthread.h>

int	has_died(t_philo *philo)
{
	int	died;

	sem_wait(philo->data->death_sem);
	died = philo->died;
	sem_post(philo->data->death_sem);
	return (died);
}

void	set_died(t_philo *philo)
{
	sem_wait(philo->data->death_sem);
	philo->died = 1;
	sem_post(philo->data->death_sem);
}

void	*death_watcher(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	while (1)
	{
		usleep(1000);
		sem_wait(data->death_sem);
		if (philo->died)
		{
			sem_post(data->death_sem);
			return (NULL);
		}
		if ((get_time() - philo->last_meal) >= data->config.time_to_die)
		{
			philo->died = 1;
			sem_post(data->death_sem);
			sem_wait(data->print_sem);
			data->someone_died = 1;
			printf("%lld %d died\n", timestamp(data), philo->id);
			return (NULL);
		}
		sem_post(data->death_sem);
	}
}

void	philosopher_routine(t_philo *philo, t_data *data)
{
	pthread_t	watcher;

	pthread_create(&watcher, NULL, death_watcher, philo);
	sem_wait(data->death_sem);
	philo->last_meal = get_time();
	sem_post(data->death_sem);
	if (philo->id % 2 == 0)
		ft_usleep(data->config.time_to_eat / 2);
	while (!has_died(philo))
	{
		if (take_forks_and_eat(philo, data) != 0)
			break ;
		if (has_died(philo))
			break ;
		if (sleep_and_think(philo, data) != 0)
			break ;
	}
	if (!has_died(philo))
		set_died(philo);
	pthread_join(watcher, NULL);
	clane_routine(data);
}

int	start_processes(t_data *data)
{
	int	index;
	int	i;

	index = 0;
	while (index < data->philo_count)
	{
		data->pids[index] = fork();
		if (data->pids[index] == -1)
		{
			i = index - 1;
			while (i >= 0)
				kill(data->pids[i--], SIGKILL);
			return (0);
		}
		if (data->pids[index] == 0)
		{
			philosopher_routine(&data->philos[index], data);
			exit(0);
		}
		index++;
	}
	return (1);
}

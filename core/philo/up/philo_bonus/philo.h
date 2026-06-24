#ifndef PHILO_H
# define PHILO_H

# include <errno.h>
# include <limits.h>
# include <semaphore.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <time.h>
# include <unistd.h>

typedef struct timeval	t_timeval;

typedef struct s_config
{
	int					number_of_philosophers;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					must_eat_count;
}						t_config;

typedef struct s_data	t_data;

typedef struct s_philo
{
	int					id;
	int					pid;
	long long			last_meal;
	int					meals_eaten;
	int					pipe_fd;
	int					died;
	t_data				*data;
}						t_philo;

typedef struct s_data
{
	int					philo_count;
	long long			start_time;
	sem_t				*forks;
	sem_t				*take_sem;
	sem_t				*print_sem;
	sem_t				*death_sem;
	int					*pipes;
	pid_t				*pids;
	t_philo				*philos;
	t_config			config;
	int					someone_died;
}						t_data;

// init_helpers.c
void		destroy_semaphores(t_data *data);
int			free_forks_philos(t_data *data);
void		init_philosopher(t_data *data, int index);

// init.c
int			open_named_sem(sem_t **sem, const char *name, int value);
int			open_core_semaphores(t_data *data);
int			init_general_semaphores(t_data *data);
int			allocate_data_arrays(t_data *data, int philo_count);
int			init_data(t_data *data, const t_config *config);

// monitor.c
void		monitor_philosophers(t_data *data);
void		cleanup_data(t_data *data);

// parse_args.c
int			is_str_positive_number(const char *str);
int			parse_positive_int(const char *str, int *out);
int			parse_required_args(char **argv, int argc, t_config *config);
void		print_error_message(void);
int			parse_arguments(int argc, char **argv, t_config *config);

// philo_process_helpers.c
int			take_forks_and_eat(t_philo *philo, t_data *data);
int			take_first_fork(t_philo *philo, t_data *data);
int			take_second_fork(t_philo *philo, t_data *data);
int			sleep_and_think(t_philo *philo, t_data *data);
void		clane_routine(t_data *data);

// philo_process.c
int			has_died(t_philo *philo);
void		set_died(t_philo *philo);
void		*death_watcher(void *arg);
void		philosopher_routine(t_philo *philo, t_data *data);
int			start_processes(t_data *data);

// time.c
long long	get_time(void);
long long	timestamp(t_data *data);
void		ft_usleep(long long milliseconds);
void		safe_print(t_data *data, long long timestamp, int id, char *msg);

#endif
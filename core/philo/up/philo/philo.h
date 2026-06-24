#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
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
	int					left_fork;
	int					right_fork;
	int					first_fork;
	int					second_fork;
	long long			last_meal;
	int					meals_eaten;
	t_data				*data;
}						t_philo;

typedef struct s_data
{
	int					philo_count;
	long long			start_time;
	int					dead;
	pthread_mutex_t		*forks;
	pthread_mutex_t		print_mutex;
	pthread_mutex_t		death_mutex;
	pthread_mutex_t		meal_mutex;
	pthread_t			*threads;
	t_philo				*philos;
	t_config			config;
}						t_data;

// fork.c
int			handle_single_fork(t_data *data, t_philo *philo, int fork);
int			acquire_first_fork(t_data *data, t_philo *philo, int first_fork);
int			acquire_second_fork(t_data *data, t_philo *philo, int first_fork,
				int second_fork);

// init_helpers.c
int			free_forks_philos(t_data *data);
int			init_philosophers_loop(t_data *data);
void		destroy_mutexes(t_data *data, int initialized_forks);
void		init_philosopher(t_data *data, int index);

// init.c
int			init_general_mutexes(t_data *data);
int			allocate_data_arrays(t_data *data, int philo_count);
int			init_data(t_data *data, const t_config *config);

// main.c
void		free_data(t_data *data);
void		join_philosophers(t_data *data);

// monitor.c
int			are_all_philosophers_full(t_data *data);
void		set_dead(t_data *data);
void		check_philosopher_death(t_data *data, int index);
int			is_dead(t_data *data);
void		*monitor_routine(void *arg);

// parse_args.c
int			parse_arguments(int argc, char **argv, t_config *config);
void		print_error_message(void);
int			parse_required_args(char **argv, int argc,
				t_config *config);
int			parse_positive_int(const char *str, int *out);
int			is_str_positive_number(const char *str);

// thread.c
int			process_eating(t_data *data, t_philo *philo, int first_fork,
				int second_fork);
int			check_must_eat_count(t_data *data, t_philo *philo);
void		*routine(void *arg);
int			start_threads(t_data *data);

// time.c
long long	get_time(void);
long long	timestamp(t_data *data);
void		ft_usleep(t_data *data, long long milliseconds);
void		safe_print(t_data *data, long long timestamp, int id,
				const char *msg);

#endif

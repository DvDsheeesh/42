/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 13:52:55 by melshata          #+#    #+#             */
/*   Updated: 2026/06/27 13:09:18 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_config
{
	int					number_of_philosophers;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	int					must_eat_count;
}						t_config;

typedef struct s_data	t_data;

typedef struct s_philo
{
	int					id;
	int					left_fork;
	int					right_fork;
	int					meals_eaten;
	size_t				last_meal_time;
	pthread_t			thread;
	pthread_mutex_t		meal_lock;
	t_data				*data;
}						t_philo;

typedef struct s_data
{
	t_config			config;
	size_t				start_time;
	int					simulation_stop;
	pthread_mutex_t		state_lock;
	pthread_mutex_t		*forks;
	t_philo				*philos;
}						t_data;

/* parsing.c */
void					parse_args(t_data *data, int ac, char **av);

/* utils.c */
int						ft_atoi(const char *str);
int						all_numbers(const char *str);
void					ft_putstr_fd(char *str, int fd);
size_t					get_time_ms(void);
void					ft_usleep(long ms, t_philo *philo);

/* init.c */
int						init_data(t_data *data);
void					destroy_data(t_data *data);

/* routine.c */
void					*philo_routine(void *arg);

/* monitor.c */
int						check_death(t_data *data);
int						check_all_full(t_data *data);
void					*monitor_routine(void *arg);
int						is_simulation_stopped(t_data *data);
void					stop_simulation(t_data *data);

/* print.c */
void					safe_print(t_philo *philo, char *msg);

#endif

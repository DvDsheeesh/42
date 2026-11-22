/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 16:42:00 by melshata          #+#    #+#             */
/*   Updated: 2026/06/26 03:48:24 by melshata         ###   ########.fr       */
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

typedef struct s_program
{
	pthread_mutex_t		*fork;
	char				*value;
}	t_prog;

typedef struct s_config
{
	int					number_of_philosophers;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					must_eat_count;
}						t_config;

typedef struct s_philo
{
	int					id;
	int					left_fork;
	int					right_fork;
	size_t				last_meal;
}						t_philo;

/*************** utils ***************/
void		ft_putstr_fd(char *s, int fd);
int			ft_atoi(const char *nptr);
int			all_numbers(char *str);

/************* arguments *************/
t_config	parse_args(int ac, char **av);

#endif
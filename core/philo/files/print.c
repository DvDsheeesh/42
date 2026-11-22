/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 13:52:07 by melshata          #+#    #+#             */
/*   Updated: 2026/06/27 12:24:15 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	safe_print(t_philo *philo, char *msg)
{
	t_data	*data;
	size_t	timestamp;

	data = philo->data;
	pthread_mutex_lock(&data->state_lock);
	if (!data->simulation_stop)
	{
		timestamp = get_time_ms() - data->start_time;
		printf("%zu %d %s\n", timestamp, philo->id, msg);
	}
	pthread_mutex_unlock(&data->state_lock);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 13:27:55 by melshata          #+#    #+#             */
/*   Updated: 2026/06/24 14:55:04 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



typedef struct s_config
{
	int					number_of_philosophers;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					must_eat_count;
}						t_config;

int	main(int ac, char **av)
{
	int	num_of_meals;

	if (ac < 5 || ac > 6)
	{
		ft_putstr("invalid number of arguments!\n");
		exit(1);
	}
	else if (ac == 5)
		num_of_meals = -1;
	else if (ac == 6)
	{
		if 
		num_of_meals = atoi()
	}
}
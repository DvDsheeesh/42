/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 12:21:43 by melshata          #+#    #+#             */
/*   Updated: 2026/01/18 12:49:39 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ps_exit(t_pack *pack, int exit_code)
{
	free_list (pack->a);
	free_list (pack->b);
	if (exit_code)
		write (2, "Error\n", 6);
	exit(exit_code);
}

int	main(int ac, char **av)
{
	t_pack	pack;

	if (ac < 2)
		return (0);
	input_list(&pack, ac, av);
	if (list_is_sorted (pack.a))
		ps_exit (&pack, 0);
	else if (list_len (pack.a) == 2 && !list_is_sorted (pack.a))
		swap_move (&pack, 'a');
	else if (list_len (pack.a) == 3)
		sort_3 (&pack, 0);
	else if (list_len (pack.a) <= 5)
		sort_5 (&pack);
	else
		sort_all (&pack);
	ps_exit (&pack, 0);
	return (0);
}

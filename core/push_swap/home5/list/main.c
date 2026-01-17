/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 12:21:43 by melshata          #+#    #+#             */
/*   Updated: 2026/01/18 00:16:59 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_list(t_list *lst)   //////////////////////////////////
{
	ft_printf("pointer: %p\n", (void *)lst);
	while (lst != NULL)
	{
		ft_printf("data: %d\ns_ind: %d\nr_ind: %d\n\n",
			lst->data, lst->sorted_index, lst->reverse_index);
		lst = lst->next;
	}
	ft_printf("-------\n");
}

void	ps_exit(t_pack *pack, const char *msg, int exit_code)
{
	free_list (pack->a);
	free_list (pack->b);
	if (msg)
		ft_printf("%s\n", msg);
	exit(exit_code);
}

// void	radix_loop(t_pack *pack, int i, int size)
// {
// 	int	j = 0;

// 	while (j < size)
// 	{
// 		if (!((pack->a->sorted_index >> i) % 2))
// 			push_move(pack, 'b');
// 		else
// 			rotate_move(pack, 'a');
// 		j++;
// 	}
// }

// void	sort_all(t_pack *pack)
// {
// 	int		longest_bits;
// 	int		size;
// 	int		i;
// 	t_list	*p;

// 	p = pack->a;
// 	longest_bits = 0;
// 	while (!is_peak(pack->a, p, 1))
// 		p = p->next;
// 	while (p->sorted_index >> longest_bits)
// 		longest_bits++;
// 	i = 0;
// 	while (i < longest_bits)
// 	{
// 		size = list_len(pack->a);
// 		radix_loop(pack, i, size);
// 		while (pack->b)
// 			push_move(pack, 'a');
// 		i++;
// 	}
// }

int	main(int ac, char **av)
{
	t_pack	pack;

	if (ac < 2)
		return (0);
	input_list(&pack, ac, av);
	// give_complex (pack.a, 0);
	if (list_is_sorted (pack.a))
		ps_exit (&pack, NULL, 0);
	else if (list_len (pack.a) == 2 && !list_is_sorted (pack.a))
		swap_move (&pack, 'a');
	else if (list_len (pack.a) == 3)
		sort_3 (&pack, 0);
	else if (list_len (pack.a) <= 5)
		sort_5 (&pack);
	else
		sort_all (&pack);
	ps_exit (&pack, NULL, 0);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 12:21:43 by melshata          #+#    #+#             */
/*   Updated: 2026/01/17 20:54:36 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_list(t_list *lst)   //////////////////////////////////
{
	ft_printf("pointer: %p\n", (void *)lst);
	while (lst != NULL)
	{
		ft_printf("data: %d\ns_ind: %d\nr_ind: %d\ncomp: %d\n\n",
			lst->data, lst->sorted_index, lst->reverse_index, lst->complex);
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

/*void	give_complex(t_list *lst)
{
	int	i;
	t_list	*p1;

	i = 0;
	p1 = lst;
	while (lst)
	{
		lst->complex = i + (lst->sorted_index);
		lst = lst->next;
		ft_printf ("i value now: %d\n", i); ///////////////////////
		if (p1 && p1->next)
		{
			p1 = p1->next->next;
			if (!p1)
				i += 2;
			else
				i++;
		}
		else if (p1)
		{
			p1 = p1->next;
			if (!p1)
				i++;
		}
		if (!p1)
			i--;
	}
}*/

int	new_i(int i, int len)
{
	if ((float)i >= (float)len / 2)
	{
		len = 0;
		i--;
	}
	else
	{
		i++;
		if ((float)i > (float)len / 2)
		{
			len = 0;
			i--;
		}
	}
	return (i);
}

void	give_complex(t_list *lst, int type)
{
	int	i;
	int	len;

	i = 0;
	len = list_len (lst);
	while (lst)
	{
		if (type == 0)  // a
			lst->complex = i + ((lst->sorted_index) * (lst->sorted_index));
		else  // b
			lst->complex = i + ((lst->reverse_index) * (lst->reverse_index));
		lst = lst->next;
		// ft_printf ("i value now: %d\n", i); ///////////////////////
		i = new_i (i, len);
	}
}

int	is_peak(t_list *lst, t_list *node, int type)
{
	t_list	*p;
	p = lst;
	if (type == 1)  // max
	{
		while (p)
		{
			if (node->sorted_index < p->sorted_index)
				return (0);
			p = p->next;
		}
	}
	else  // min
	{
		while (p)
		{
			if (node->sorted_index > p->sorted_index)
				return (0);
			p = p->next;
		}
	}
	return (1);
}

void	sort_3(t_pack *pack, int type)
{
	if (type == 0)  // a
	{
		if (is_peak(pack->a, pack->a, 1))
			rotate_move(pack, 'a');
		else if (is_peak(pack->a, pack->a->next, 1))
			reverse_rotate_move(pack, 'a');
		if (pack->a->sorted_index > pack->a->next->sorted_index)
			swap_move(pack, 'a');
	}
	else  // b
	{
		if (is_peak(pack->b, pack->b, 0))
			rotate_move(pack, 'b');
		else if (is_peak(pack->b, pack->b->next, 0))
			reverse_rotate_move(pack, 'b');
		if (pack->b->sorted_index < pack->b->next->sorted_index)
			swap_move(pack, 'b');
	}
}

void	sort_2(t_pack *pack, int type)
{
	if (type == 0)
		if (pack->a->sorted_index > pack->a->next->sorted_index)  // a
			swap_move(pack, 'a');
	else  // b
		if (pack->b->sorted_index < pack->b->next->sorted_index)
			swap_move(pack, 'b');
}

void	get_least_complex_to_top(t_pack *pack, int type)
{
	t_list	*lst;
	t_list	*least;
	int		least_pos;
	int		pos;
	int		len;

	// ft_printf ("Getting least complex to top of %c\n",
	// 	(type == 0) ? 'a' : 'b');
	lst = (type == 0) ? pack->a : pack->b;
	least = lst;
	least_pos = 0;
	pos = 0;
	len = list_len (lst);
	while (lst)
	{
		if (lst->complex < least->complex
			|| (lst->complex == least->complex
				&& (lst->sorted_index < least->sorted_index && type == 0
					|| lst->sorted_index > least->sorted_index && type == 1)))
		{
			least = lst;
			least_pos = pos;
		}
		lst = lst->next;
		pos++;
	}
	// ft_printf ("least complex node has complex: %d at pos: %d data = %d\n",
	// 	least->complex, least_pos, least->data);
	if ((float)least_pos <= (float)len / 2)
	{
		while (least_pos-- > 0)
			rotate_move (pack, (type == 0) ? 'a' : 'b');
	}
	else
	{
		while (least_pos++ < len)
			reverse_rotate_move (pack, (type == 0) ? 'a' : 'b');
	}
}

void	sort_all(t_pack *pack)
{
	while (!list_is_sorted(pack->a))
	{
		// give_complex (pack->a, 0);
		// get the least complex node to top of a
		// push it to b
		// repeat until 3 left in a
		// sort_3 a
		// give_complex (pack->b, 1);
		// get the least complex node to top of b
		// push it to a
		// repeat until b empty
		while (list_len (pack->a) > 3)
		{
			// give_sorted_index (pack->a);
			give_complex (pack->a, 0);
			// print_list (pack->a);
			// get the least complex node to top of a
			get_least_complex_to_top (pack, 0);
			// print_list (pack->a);
			// push it to b
			push_move (pack, 'b');
		}
		// print_list (pack->a);
		sort_3 (pack, 0);
		// print_list (pack->a);
		while (list_len (pack->b) > 3)
		{
			// give_sorted_index (pack->b);
			give_complex (pack->b, 1);
			// print_list (pack->b);
			// get the least complex node to top of b
			get_least_complex_to_top (pack, 1);
			// push it to a
			push_move (pack, 'a');
		}
		sort_3 (pack, 1);
		while (pack->b)
			push_move (pack, 'a');
		give_sorted_index (pack->a);
	}
}

int	main(int ac, char **av)
{
	t_pack	pack;

	if (ac < 2)
		return (0);
	
	// ft_printf("test: %s\n", av[1]);
	input_list(&pack, ac, av);
	// print_list (pack.a);
	give_complex (pack.a, 0);
	// print_list (pack.a);
	// ft_printf ("is sorted: %d\n----\n----\n\n\n\n", list_is_sorted(pack.a));
	// push_move (&pack, 'b');
	// push_move (&pack, 'b');
	// push_move (&pack, 'b');
	// push_move (&pack, 'b');
	// push_move (&pack, 'b');
	// push_move (&pack, 'b');
	// push_move (&pack, 'b');
	// ft_printf ("\n\n################################################\n\n");
	// ft_printf ("\n\nAfter pushes:\n\n");
	// print_list (pack.a);
	// print_list (pack.b);
	// push_move (&pack, 'a');
	// push_move (&pack, 'a');
	// push_move (&pack, 'a');
	// ft_printf ("\n\n################################################\n\n");
	// ft_printf ("\n\nAfter more pushes:\n\n");
	// print_list (pack.a);
	// print_list (pack.b);
	// rotate_move (&pack, 'a');
	// rotate_move (&pack, 'a');
	// rotate_move (&pack, 'b');
	// rotate_move (&pack, 'b');
	// ft_printf ("\n\n################################################\n\n");
	// ft_printf ("\n\nAfter rotates:\n\n");
	// print_list (pack.a);
	// print_list (pack.b);
	// rotate_move (&pack, 'r');
	// rotate_move (&pack, 'r');
	// ft_printf ("\n\n################################################\n\n");
	// ft_printf ("\n\nAfter rr:\n\n");
	// print_list (pack.a);
	// print_list (pack.b);
	// reverse_rotate_move (&pack, 'a');
	// reverse_rotate_move (&pack, 'a');
	// reverse_rotate_move (&pack, 'b');
	// reverse_rotate_move (&pack, 'b');
	// ft_printf ("\n\n################################################\n\n");
	// ft_printf ("\n\nAfter rrs:\n\n");
	// print_list (pack.a);
	// print_list (pack.b);
	// reverse_rotate_move (&pack, 'r');
	// reverse_rotate_move (&pack, 'r');
	// ft_printf ("\n\n################################################\n\n");
	// ft_printf ("\n\nAfter rrr:\n\n");
	// print_list (pack.a);
	// print_list (pack.b);
	// // swap_move (&pack, 'a');
	// swap_move (&pack, 'a');
	// // swap_move (&pack, 'b');
	// swap_move (&pack, 'b');
	// ft_printf ("\n\n################################################\n\n");
	// ft_printf ("\n\nAfter swaps:\n\n");
	// print_list (pack.a);
	// print_list (pack.b);
	// // swap_move (&pack, 's');
	// swap_move (&pack, 's');
	// ft_printf ("\n\n################################################\n\n");
	// ft_printf ("\n\nAfter ss:\n\n");
	// print_list (pack.a);
	// print_list (pack.b);
	// sort_3 (&pack, 1);
	// ft_printf ("\n\n################################################\n\n");
	// ft_printf ("\n\nAfter sort_3 b:\n\n");
	// print_list (pack.a);
	// print_list (pack.b);
	sort_all (&pack);
	// ft_printf ("\n\n################################################\n\n");
	// ft_printf ("\n\nAfter sort_all:\n\n");
	// print_list (pack.a);
	// print_list (pack.b);
	ps_exit (&pack, NULL, 0);
	return (0);
}

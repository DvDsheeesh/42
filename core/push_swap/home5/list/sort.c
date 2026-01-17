/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 00:13:12 by melshata          #+#    #+#             */
/*   Updated: 2026/01/18 00:17:37 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	sort_5(t_pack *pack)
{
	while (list_len(pack->a) > 3)
	{
		if (is_peak(pack->a, pack->a, 0)
			|| is_peak(pack->a, pack->a->next, 0)
			|| is_peak(pack->a, pack->a->next->next, 0))
			while (!is_peak(pack->a, pack->a, 0))
				rotate_move(pack, 'a');
		else
			while (!is_peak(pack->a, pack->a, 0))
				reverse_rotate_move(pack, 'a');
		push_move(pack, 'b');
	}
	sort_3(pack, 0);
	while (pack->b)
		push_move(pack, 'a');
}

void	radix_loop(t_pack *pack, int i, int size)
{
	int	j = 0;

	while (j < size)
	{
		if (!((pack->a->sorted_index >> i) % 2))
			push_move(pack, 'b');
		else
			rotate_move(pack, 'a');
		j++;
	}
}

void	sort_all(t_pack *pack)
{
	int		longest_bits;
	int		size;
	int		i;
	t_list	*p;

	p = pack->a;
	longest_bits = 0;
	while (!is_peak(pack->a, p, 1))
		p = p->next;
	while (p->sorted_index >> longest_bits)
		longest_bits++;
	i = 0;
	while (i < longest_bits)
	{
		size = list_len(pack->a);
		radix_loop(pack, i, size);
		while (pack->b)
			push_move(pack, 'a');
		i++;
	}
}

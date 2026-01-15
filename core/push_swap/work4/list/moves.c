/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:02:59 by melshata          #+#    #+#             */
/*   Updated: 2026/01/15 13:07:38 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
// #include "list_new.c"

void	push_move(t_pack *pack, char type)
{
	t_list	*tmp;

	if (type == 'a' && pack->b)  // pa
	{
		tmp = pack->b;
		pack->b = pack->b->next;
		tmp->next = pack->a;
		pack->a = tmp;
	}
	if (type == 'b' && pack->a)  // pb
	{
		tmp = pack->a;
		pack->a = pack->a->next;
		tmp->next = pack->b;
		pack->b = tmp;
	}
}

void	swap_move(t_pack *pack, char type)
{
	t_list	*tmp;

	if (type != 'b')  // sa
	{
		tmp = pack->a->next;
		pack->a->next = tmp->next;
		tmp->next = pack->a;
		pack->a = tmp;
	}
	if (type != 'a')  // sb
	{
		tmp = pack->b->next;
		pack->b->next = tmp->next;
		tmp->next = pack->b;
		pack->b = tmp;
	}
}

void	rotate_move(t_pack *pack, char type)
{
	t_list	*tmp;

	if (type != 'b')  // ra
	{
		tmp = pack->a;
		pack->a = pack->a->next;
		list_last(pack->a)->next = tmp;
		tmp->next = NULL;
	}
	if (type != 'a')  // rb
	{
		tmp = pack->b;
		pack->b = pack->b->next;
		list_last(pack->b)->next = tmp;
		tmp->next = NULL;
	}
}

void	reverse_rotate_move(t_pack *pack, char type)
{
	t_list	*tmp;
	t_list	*p;

	if (type != 'b')  // rra
	{
		tmp = list_last(pack->a);
		p = pack->a;
		while (p->next != tmp)
			p = p->next;
		p->next = NULL;
		tmp->next = pack->a;
		pack->a = tmp;
	}
	if (type != 'a')  // rrb
	{
		tmp = list_last(pack->b);
		p = pack->b;
		while (p->next != tmp)
			p = p->next;
		p->next = NULL;
		tmp->next = pack->b;
		pack->b = tmp;
	}
}

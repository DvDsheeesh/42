/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 07:07:22 by melshata          #+#    #+#             */
/*   Updated: 2026/01/19 14:39:05 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_unique(t_pack *pack, t_list *node)
{
	t_list	*p;

	p = pack->a;
	while (p)
	{
		if (p->data == node->data && p != node)
			return (0);
		p = p->next;
	}
	return (1);
}

static void	append_list(t_pack *pack, long data)
{
	t_list	*aa;
	t_list	*p;

	aa = malloc(sizeof(t_list));
	if (!aa)
		ps_exit (pack, 1);
	aa->data = data;
	aa->sorted_index = 0;
	aa->next = NULL;
	if (!(pack->a))
		pack->a = aa;
	else
	{
		p = pack->a;
		while (p->next != NULL)
			p = p->next;
		p->next = aa;
		if (!is_unique (pack, aa))
			ps_exit (pack, 1);
	}
	if ((aa->data) >= ((long)1 << 31) || (aa->data) < -((long)1 << 31))
		ps_exit (pack, 1);
}

void	give_sorted_index(t_list *lst)
{
	t_list	*p1;
	t_list	*p2;

	p1 = lst;
	while (p1)
	{
		p1->sorted_index = 1;
		p2 = lst;
		while (p2)
		{
			if (p1->data > p2->data)
				p1->sorted_index++;
			p2 = p2->next;
		}
		p1 = p1->next;
	}
}

void	input_list(t_pack *pack, int ac, char **av)
{
	int		i;

	i = 1;
	pack->a = NULL;
	pack->b = NULL;
	while (i < ac)
		append_list(pack, ft_atol(av[i++], pack));
	give_sorted_index (pack->a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 07:07:22 by melshata          #+#    #+#             */
/*   Updated: 2026/01/17 22:49:01 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	append_list(t_pack *pack, t_list **lst, long data)
{
	t_list	*aa;
	t_list	*p;

	aa = malloc(sizeof(t_list));
	if (!aa)
		ps_exit(pack, "Error\nnew node malloc failed\n", 1);
	aa->data = data;
	aa->sorted_index = 0;
	// aa->complex = 0;
	aa->next = NULL;
	if (!(*lst))
		*lst = aa;
	else
	{
		p = *lst;
		while (p->next != NULL)
			p = p->next;
		p->next = aa;
	}
}

void	give_sorted_index(t_list *lst)
{
	int	i;
	t_list	*p1;
	t_list	*p2;

	p1 = lst;
	while (p1)
	{
		p1->sorted_index = 1;
        p1->reverse_index = 1;
		p2 = lst;
		while (p2)
		{
			if (p1->data > p2->data)
				p1->sorted_index++;
			if (p1->data < p2->data)
				p1->reverse_index++;
			p2 = p2->next;
		}
		p1 = p1->next;
	}
}

void	input_list(t_pack *pack, int ac, char **av)
{
	int		i;
	t_list	*head;

	i = 1;
	pack->a = NULL;
	pack->b = NULL;
	while (i < ac)
	{
		// ft_printf("\nadding: %s\n", av[i]);  //////////////////////////////
		append_list(pack, &(pack->a), ft_atol(av[i], pack));
		// print_list(pack->a);
		i++;
	}
	give_sorted_index (pack->a);
}

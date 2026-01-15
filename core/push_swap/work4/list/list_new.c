/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 12:21:43 by melshata          #+#    #+#             */
/*   Updated: 2026/01/15 16:39:48 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_list(t_list *lst)   //////////////////////////////////
{
	ft_printf("pointer: %p\n", (void *)lst);
	while (lst != NULL)
	{
		ft_printf("data: %d\ns_ind: %d\n\n", lst->data, lst->sorted_index);
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

void	append_list(t_pack *pack, t_list **lst, long data)
{
	t_list	*aa;
	t_list	*p;

	aa = malloc(sizeof(t_list));
	if (!aa)
		ps_exit(pack, "Error\nnew node malloc failed\n", 1);
	aa->data = data;
	aa->sorted_index = 0;
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

void	give_sorted_index (t_list *lst)
{
	int	i;
	t_list	*p1;
	t_list	*p2;

	p1 = lst;
	while (p1)
	{
		p1->sorted_index = 0;
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
	t_list	*head;

	i = 1;
	pack->a = NULL;
	pack->b = NULL;
	while (i < ac)
	{
		ft_printf("\nadding: %s\n", av[i]);
		append_list(pack, &(pack->a), ft_atol(av[i], pack));
		print_list(pack->a);
		i++;
	}
	give_sorted_index (pack->a);
}

int	main(int ac, char **av)
{
	t_pack	pack;

	if (ac < 2)
		return (0);
	
	// ft_printf("test: %s\n", av[1]);
	input_list(&pack, ac, av);
	print_list (pack.a);
	ft_printf ("is sorted: %d\n", a_is_sorted(pack.a));
	ps_exit (&pack, "Done", 0);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 12:21:43 by melshata          #+#    #+#             */
/*   Updated: 2026/01/14 22:27:11 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_list(t_list *lst)
{
	t_list	*p;

	p = lst;
	ft_printf("pointer: %p\n", (void *)lst);
	while (p != NULL)
	{
		ft_printf("content: %s\n", (char *)p->content);
		p = p->next;
	}
	ft_printf("\n");
}

t_list	*lst_last(t_list *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	free_list(t_list *p)
{
	if (p->next)
		free_list (p->next);
	// if (p->content)
	// 	free (p->content);
	p->next = NULL;
	p->prev = NULL;
	free (p);
}

void	ps_exit(char *msg, int exit_code)
{
	ft_printf("%s", msg);
	exit(exit_code);
}

void	append_list(t_list **lst, void *content)
{
	t_list	*aa;
	t_list	*p;

	aa = malloc(sizeof(t_list));
	if (!aa)
		ps_exit("Error\nnew node malloc failed\n", 1);
	aa->content = content;
	aa->prev = NULL;
	aa->next = NULL;
	if (!(*lst))
		*lst = aa;
	else
	{
		p = *lst;
		while (p->next != NULL)
			p = p->next;
		aa->prev = p;
		p->next = aa;
	}
}

////////////////////////////////////////////////////////////////////////////

void	push_move(t_list pack, int type)
{
	
}

////////////////////////////////////////////////////////////////////////////

t_list	*input_list(int ac, char **av)
{
	int i;
	t_list	*head;

	i = 1;
	head = NULL;
	while (i < ac)
	{
		ft_printf("\nadding: %s\n", av[i]);
		append_list(&head, av[i]);
		// print_list(head);
		i++;
	}
	return (head);
}

int	main(int ac, char **av)
{
	t_list	*a;
	if (ac < 2)
		return (0);
	// ft_printf("test: %s\n", av[1]);
	a = input_list(ac, av);
	print_list (a);
	free_list (a);
	return (0);
}
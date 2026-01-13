/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 12:21:43 by melshata          #+#    #+#             */
/*   Updated: 2026/01/13 17:45:19 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_list(t_list *lst)
{
	t_list	*p;

	p = lst;
	printf("pointer: %p\n", (void *)lst);
	while (p != NULL)
	{
		printf("content: %s\n", (char *)p->content);
		p = p->next;
	}
	printf("\n");
}

void	ps_exit(char *msg)
{
	write(2, msg, 6);
	exit(EXIT_FAILURE);
}

void	append_list(t_list **lst, void *content)
{
	t_list	*aa;
	t_list	*p;

	aa = malloc(sizeof(t_list));
	if (!aa)
		ps_exit("Error\n");
	aa->content = content;
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

t_list	*input_list(int ac, char **av)
{
	int i;
	t_list	*head;

	i = 1;
	head = NULL;
	while (i < ac)
	{
		printf("\nadding: %s\n", av[i]);
		append_list(&head, av[i]);
		print_list(head);
		i++;
	}
	return (head);
}

int	main(int ac, char **av)
{
	t_list	*a;
	if (ac < 2)
		return (0);
	// printf("test: %s\n", av[1]);
	a = input_list(ac, av);
	print_list(a);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:31:48 by melshata          #+#    #+#             */
/*   Updated: 2025/09/17 15:37:24 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// strchr
char	*schr(char *s, ssize_t t)
{
	ssize_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == '\n' && t == 0)
			return (&s[i]);
		i++;
	}
	if (t == 1)
		return (&s[i]);
	return (NULL);
}

char	*sdup(char *s1, ssize_t cs)
{
	char	*s2;
	ssize_t	i;

	i = 0;
	s2 = malloc (cs + 1);
	if (!s2)
		return (NULL);
	while (s1[i++])
		s2[i - 1] = s1[i - 1];
	s2[i] = '\0';
	return (s2);
}

// ll
ssize_t	ll(t_list *lst, int t)
{
	ssize_t	l;
	t_list	*p;

	l = 0;
	p = lst;
	while (p)
	{
		if (t)
		{
			l += p->cs;
			if (schr(p->c, 0))
				break ;
		}
		else
			l += p->cs;
		p = p->next;
	}
	return (l);
}

// lstlast
t_list	*lstl(t_list *lst)
{
	t_list	*p;

	if (!lst)
		return (NULL);
	p = lst;
	while (p->next != NULL)
		p = p->next;
	return (p);
}

// lstclear
void	lstc(t_list **lst)
{
	t_list	*p;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		p = (*lst)->next;
		free ((*lst)->c);
		free (*lst);
		*lst = p;
	}
	*lst = NULL;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:26:34 by melshata          #+#    #+#             */
/*   Updated: 2026/01/15 16:32:06 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*list_last(t_list *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	free_list(t_list *p)
{
	if (p && p->next)
		free_list (p->next);
	// ft_printf ("test: %p\n", p);
	free (p);
}

long	ft_atol(const char *nptr, t_pack *pack)
{
	int		i;
	long	neg;
	long	num;

	i = 0;
	neg = 1;
	num = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			neg = -neg;
	if (nptr[i] == '\0')
		ps_exit (pack, "Error\nwrong input format\n", 1);
	while (nptr[i] >= '0' && nptr[i] <= '9')
		num = num * 10 + (nptr[i++] - '0');
	if (nptr[i])
		ps_exit (pack, "Error\nwrong input format\n", 1);
	return (num * neg);
}

int	a_is_sorted(t_list *a)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->sorted_index != i)
			return (0);
		a = a->next;
		i++;
	}
	return (1);
}

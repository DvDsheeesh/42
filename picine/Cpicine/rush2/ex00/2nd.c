/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2nd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:08:21 by melshata          #+#    #+#             */
/*   Updated: 2025/01/18 16:09:08 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*leftpart(char *num, int n)
{
	int		i;
	int		j;
	char	*lp;

	lp = malloc(4);
	i = 0;
	while (num[i] && (num[i] <= '0' || num[i] > '9'))
		i++;
	j = 0;
	while (num[i] >= '0' && num[i] <= '9' && i < n)
	{
		lp[j] = num[i];
		i++;
		j++;
	}
	return (lp);
}

int	length(char *num)
{
	int	i;
	int	l;

	l = 0;
	i = 0;
	while (num[i] <= '0' || num[i] > '9')
	{
		if (num[i] == '-')
		{
			return (0);
		}
		i++;
	}
	while (num[i] >= '0' && num[i] <= '9')
	{
		i++;
		l++;
	}
	return (l);
}

char	*noz_num(char *num, int l)
{
	int		i;
	int		j;
	char	*nn;

	nn = malloc(l);
	i = 0;
	while (num[i] <= '0' || num[i] > '9')
		i++;
	j = 0;
	while (num[i] >= '0' && num[i] <= '9' && i < l)
	{
		nn[j] = num[i];
		i++;
		j++;
	}
	return (nn);
}

char	*trim(char *num, int n, int l)
{
	int		i;
	int		j;
	char	*tr;

	tr = malloc (l - n + 1);
	i = 0;
	while (i < n)
		i++;
	j = 0;
	while (i < l)
	{
		tr[j] = num[i];
		j++;
		i++;
	}
	return (tr);
}

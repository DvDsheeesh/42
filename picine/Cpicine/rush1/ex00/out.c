/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 12:50:08 by melshata          #+#    #+#             */
/*   Updated: 2025/01/11 12:50:09 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	shuffout(char *out, int *k);

void	outnew(int t, char *out)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		out[i] = ((i / 4) + (i % 4) + t) % 4 + '1';
		i++;
	}
}
//	int	k[8];
//
//	i = 0;
//	while (i < 4)
//	{
//		k[i] = i % 4 + 1;
//		i++;
//	}
//	while (i < 8)
//	{
//		k[i] = i % 4 + 1;
//		i++;
//	}
//	shuffout(out, k)

void	outprint(char *out)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			write (1, &out[i * 4 + j], 1);
			j++;
		}
		i++;
		write (1, "\n", 1);
	}
}

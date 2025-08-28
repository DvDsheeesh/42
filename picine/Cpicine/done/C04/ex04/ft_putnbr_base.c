/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 02:50:24 by melshata          #+#    #+#             */
/*   Updated: 2025/01/19 03:19:22 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	len(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i == 1)
		return (0);
	return (i);
}

void	printing(int nbr, int l, char *b)
{
	if (nbr >= l)
		printing (nbr / l, l, b);
	nbr = nbr % l;
	write (1, &b[nbr], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	l;

	l = len(base);
	if (l == 0)
		return ;
	if (nbr < 0)
	{
		write (1, "-", 1);
		nbr *= -1;
	}
	printing(nbr, l, base);
}
/*
int	main(void)
{
	int	x = 12;
	ft_putnbr_base(x, "0123456789ABCDEF");
}*/

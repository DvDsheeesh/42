/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 05:58:46 by melshata          #+#    #+#             */
/*   Updated: 2025/01/20 18:34:46 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	i;

	if (power < 0)
		return (0);
	i = 1;
	while (power > 0)
	{
		i *= nb;
		power--;
	}
	return (i);
}
/*
int	main(void)
{
	printf("%d", ft_iterative_power(2, 1));
	return (0);
}*/

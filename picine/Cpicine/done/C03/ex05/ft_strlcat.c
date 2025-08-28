/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:46:37 by melshata          #+#    #+#             */
/*   Updated: 2025/01/13 19:46:45 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	ss;
	unsigned int	sd;

	i = 0;
	while (dest[i])
		i++;
	sd = i;
	ss = 0;
	while (src[ss])
		ss++;
	j = 0;
	while (dest[i] && src[j] && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (size >= sd)
	{
		dest[i] = '\0';
		return (sd + ss);
	}
	return (ss + size);
}
/*
int	main(int ac, char **av)
{
	printf ("%d %s", ft_strlcat(av[ac - 2], av[ac - 1], 7), av[ac - 2]);
	printf ("\n");
	//printf ("%d", strlcat(av[ac - 2], av[ac - 1], 6));
	return (0);
}*/

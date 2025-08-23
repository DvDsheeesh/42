/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:46:37 by melshata          #+#    #+#             */
/*   Updated: 2025/08/17 22:11:27 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	ss;

	ss = ft_strlen(src) + ft_strlen(dst);
	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	i = 0;
	while (dst[i])
		i++;
	j = 0;
	while (src[j] && i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (ss);
}
/*

size_t	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < size - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

#include <stdio.h>
#include <string.h>
int	main(int ac, char **av)
{
	printf ("%d %s", ft_strlcat(av[ac - 2], av[ac - 1], 7), av[ac - 2]);
	printf ("\n");
	//printf ("%d", strlcat(av[ac - 2], av[ac - 1], 6));
	return (0);
}*/

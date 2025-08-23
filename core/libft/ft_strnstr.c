/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 20:04:57 by melshata          #+#    #+#             */
/*   Updated: 2025/08/19 17:01:55 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check(char *big, char *little, size_t i)
{
	size_t	j;

	j = 0;
	while (big[i] && little[j])
	{
		if (big[i] != little[j])
			return (0);
		i++;
		j++;
	}
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		t;

	i = 0;
	t = 0;
	if (!(char)little[0])
		return ((char *)big);
	if (len == 0 || !(char)big[0])
		return (NULL);
	if ((unsigned int)ft_strlen((char *)little) > (unsigned int)len)
		return (NULL);
	while (big[i] && i < len - ft_strlen((char *)little) + 1)
	{
		if (big[i] == little[0] && t == 0)
		{
			if (check((char *)big, (char *)little, i))
				return ((char *)&big[i]);
		}
		i++;
	}
	return (0);
}
	/*
#include <unistd.h>
#include <stdio.h>
#include <string.h>
int	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	i++;
	return (i);
	}

int	main(int ac, char **av)
{
	printf ("%d\n",(int)av[ac - 1][0] - 48);
	printf ("%s", ft_strnstr(av[ac - 3], 
	av[ac - 2], ((size_t)av[ac - 1][0] - 48)));
	printf ("\n");
	// printf ("%s", strnstr(av[ac - 2], av[ac - 1], 5));
	return (0);
}
	int	check(char *str, char *to_find, int i)
{
	int	j;

	j = 0;
	while (str[i] && to_find[j])
	{
		if (str[i] != to_find[j])
			return (0);
		i++;
		j++;
	}
	return (1);
}
char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	t;

	i = 0;
	t = 0;
	if (!to_find[0])
		return (str);
	while (str[i])
	{
		if (str[i] == to_find[0] && t == 0)
		{
			if (check(str, to_find, i))
				return (&str[i]);
		}
		i++;
	}
	return (0);
}*/
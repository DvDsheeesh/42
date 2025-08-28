/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:15:11 by melshata          #+#    #+#             */
/*   Updated: 2025/01/15 19:34:50 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	check(char *str, char *to_find, int i)
{
	int	j;

	j = 0;
	while (str[i] || to_find[j])
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
	write (1, "(null)", 7);
	return ("\0");
}

int	main(int ac, char **av)
{
	printf ("%s\n", ft_strstr(av[ac - 2], av[ac - 1]));
	printf ("%s", strstr(av[ac - 2], av[ac - 1]));
	return (0);
}

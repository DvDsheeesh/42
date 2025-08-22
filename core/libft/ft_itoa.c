/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammad <mohammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:40:34 by mohammad          #+#    #+#             */
/*   Updated: 2025/08/22 16:13:47 by mohammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	my_int_length(int n)
{
	int	i;

	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*s;

	s = (char *)malloc (my_int_length(n) + 1);
	if (!s)
		return (NULL);
	s[my_int_length(n) + 1] = '\0';
	if (n < 0)
	{
		s[0] = '-';
		n = -n;
	}
	while (n)
	{
		s[my_int_length(n) - 1] = (char)((n % 10) + 48);
		n /= 10;
	}
	return (s);
}

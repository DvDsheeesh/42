/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:52:33 by melshata          #+#    #+#             */
/*   Updated: 2025/08/14 19:31:49 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A'))
		return (1);
	else
		if (c <= '9' && c >= '0')
			return (1);
	else
		return (0);
}
/*
#include <stdio.h>
int main(int ac, char** av)
{
	printf("%d",ft_isalnum(av[1][0]));
}
*/

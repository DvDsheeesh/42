/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 21:35:45 by melshata          #+#    #+#             */
/*   Updated: 2025/08/16 11:56:29 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ss;

	i = 0;
	ss = (char *)s;
	while (i < n)
	{
		*ss = 0;
		ss++;
		i++;
	}
}
/*
#include <string.h>
#include <stdio.h>
int main(void)
{
    char arr[20] = "Hello, world!";
    size_t n = 5;

    // strcpy(arr, "Hello, world!");

	printf("String before ft_bzero: %s\n", arr);

    ft_bzero(arr, n);

    printf("String after ft_bzero: %s\n", arr);
    for (size_t i = 0; i < 20; i++)
    {
        printf("%02x ", (unsigned char)arr[i]);
    }
    printf("\n");

    return 0;
}
*/
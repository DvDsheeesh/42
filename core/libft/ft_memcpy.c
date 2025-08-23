/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 11:20:06 by melshata          #+#    #+#             */
/*   Updated: 2025/08/17 17:01:56 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dd;
	char	*ss;

	if (!dest && !src)
		return (NULL);
	i = 0;
	dd = (char *)dest;
	ss = (char *)src;
	if (n == 0)
		return (dest);
	while (i < n)
	{
		*(dd + i) = *(ss + i);
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
    char src[20] = "Hello, world!";
    char dest[20] = "--------------------";
    // Number of bytes to copy
    size_t n = 5;

    // --- Before the copy ---
    printf("Source string: %s\n", src);
    printf("Destination string: %s\n", dest);

    ft_memcpy(dest, src, n);

    printf("Source after (should be unchanged): %s\n", src);
    printf("Destination after (should be updated): %s\n", dest);
    for (size_t i = 0; i < 20; i++)
    {
        // Print each byte in hexadecimal format for clear visual inspection
        printf("%02x ", (unsigned char)dest[i]);
    }
    printf("\n");

    return 0;
}
*/
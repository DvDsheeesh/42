/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 12:12:30 by melshata          #+#    #+#             */
/*   Updated: 2025/08/17 17:09:20 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	int		rev;
	char	*dd;
	char	*ss;

	if (!dest && !src)
		return (NULL);
	if (dest < src)
		rev = 0;
	else
		rev = 1;
	dd = (char *)dest;
	ss = (char *)src;
	i = (n * rev) - rev;
	while (i != n - (n + 1) * rev)
	{
		*(dd + i) = *(ss + i);
		i += 1 - (2 * rev);
	}
	return (dest);
}
/*
#include <string.h>
#include <unistd.h>
int main(void)
{
    // --- Test 1: Non-overlapping copy ---
    char src1[30] = "A non-overlapping test.";
    char dest1[30] = "-----------------------------";
    size_t n1 = 15;

    printf("Source:      %s\n", src1);
    printf("Destination: %s\n", dest1);
    printf("Copying %zu bytes with ft_memmove...\n", n1);

    ft_memmove(dest1, src1, n1);

    printf("Result:      %s\n\n", dest1);

    // --- Test 2: Overlapping copy (dest > src) ---
    // This case requires a backward copy to avoid overwriting source data.
    char arr2[30] = "abcdefghijklmnopqrstuvwxyz";
    size_t n2 = 10;
    
    printf("--- Test 2: Overlapping Copy (dest > src) ---\n");
    printf("Original:    %s\n", arr2);
    printf("Copying 10 bytes from index 0 to 5.\n");

    ft_memmove(arr2 + 5, arr2, n2);

    printf("Result:      %s\n\n", arr2);

    // --- Test 3: Overlapping copy (dest < src) ---
    // This case requires a forward copy.
    char arr3[30] = "abcdefghijklmnopqrstuvwxyz";
    size_t n3 = 10;
    
    printf("--- Test 3: Overlapping Copy (dest < src) ---\n");
    printf("Original:    %s\n", arr3);
    printf("Copying 10 bytes from index 5 to 0.\n");

    ft_memmove(arr3, arr3 + 5, n3);

    printf("Result:      %s\n\n", arr3);

    return 0;
}
*/
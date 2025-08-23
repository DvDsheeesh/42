/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 20:06:38 by melshata          #+#    #+#             */
/*   Updated: 2025/08/16 11:55:13 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*ss;

	i = 0;
	ss = (char *)s;
	while (i < n)
	{
		*ss = c;
		ss++;
		i++;
	}
	return (s);
}
/*
#include <string.h>
#include <stdio.h>
int main()
{
    char pp[] = "cyka blyat!"; 
    void *p2 = (void *)pp;
    // memset(p2, 75, 3);
    // printf("%s\n", (char *)p2);
	ft_memset(p2, 72, 3);
    printf("%s\n", (char *)p2); 
    return (0);
}
*/
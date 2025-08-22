/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammad <mohammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:26:57 by mohammad          #+#    #+#             */
/*   Updated: 2025/08/22 14:43:10 by mohammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	my_spfree(char **nn, int i)
{
	while (i >= 0)
	{
		if (nn[i])
			free (nn[i]);
		i--;
	}
	free (nn);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**nn;

	nn = (char **)malloc (sizeof(char *) * ft_count_word (s, c) + 1);
	if (!nn)
		return (NULL);
	j = 0;
	i = 0;
	while (i < ft_strlen(s))
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			nn[j] = ft_substr (s, (unsigned int)i, (size_t)strchr(&s[i], c) - (size_t)(&s[i]));
			if (!nn[j])
				my_spfree (nn, (int)j);
			j++;
		}
		i = (size_t)strchr(&s[i], c) - (size_t)s;
	}
	return (nn);
}

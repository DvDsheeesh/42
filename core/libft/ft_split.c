/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:26:57 by mohammad          #+#    #+#             */
/*   Updated: 2025/08/23 21:19:28 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	spfree(char **nn, int i)
{
	while (i >= 0)
		if (nn[i])
			free (nn[i--]);
	free (nn);
}

static size_t	wordlen(const char *s, char c)
{
	size_t		i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static void	split_iter(char const *s, char c, char **nn)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			nn[j] = ft_substr (s, (unsigned int)i, wordlen(&s[i], c));
			if (!nn[j])
				spfree (nn, (int)(j));
			j++;
			i += wordlen(&s[i], c);
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**nn;

	if (!s)
		return (NULL);
	nn = malloc (sizeof(char *) * (ft_count_word(s, c) + 1));
	if (!nn)
		return (NULL);
	nn[ft_count_word (s, c)] = NULL;
	split_iter(s, c, nn);
	return (nn);
}

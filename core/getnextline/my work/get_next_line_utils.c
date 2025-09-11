/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:32:23 by mohammad          #+#    #+#             */
/*   Updated: 2025/09/11 15:10:12 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strchr(const char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	if (s[i] == '\n')
		i++;
	return ((char *)s + i);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	char	*sus;
	size_t	i;

	// if (len == 0)
	// 	len = (size_t)gnl_strchr(s) - (size_t)(&s[start]);
	sus = (char *)malloc (len + 1);
	if (!sus)
		return (NULL);
	i = 0;
	while (i < len && s[i])
	{
		sus[i] = s[start + i];
		i++;
	}
	sus[i] = '\0';
	return (sus);
}

char	*gnl_strlcat(char *s1, char *s2, size_t bs)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < bs)
	{
		if (s1[i] == '\n' || s1[i] == '\0')
			return (ft_substr(s1, 0, i + 1));
		i++;
	}
	while (s2[j] != '\n' && s2[j] && i == bs && j < bs)
	{
		s1[i + j] = s2[j];
		j++;
	}
	s1[i + j] = s2[j];
	return (s1);
}

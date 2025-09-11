/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammad <mohammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:32:23 by mohammad          #+#    #+#             */
/*   Updated: 2025/09/09 10:47:17 by mohammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sus;
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	if (start >= i)
	{
		sus = (char *)malloc (1);
		sus[0] = '\0';
		return (sus);
	}
	if (len > i - start)
		len = i - start;
	sus = (char *)malloc (len + 1);
	if (!sus)
		return (NULL);
	i = 0;
	while (i < len)
		sus[i] = s[start + i++];
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
		s1[i + j] = s2[j++];
	s1[i + j] = s2[j];
	return (s1);
}

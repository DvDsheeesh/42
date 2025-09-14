/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammad <mohammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:32:23 by mohammad          #+#    #+#             */
/*   Updated: 2025/09/12 17:35:10 by mohammad         ###   ########.fr       */
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
		return ((char *)s + i + 1);
	else
		return (NULL);
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

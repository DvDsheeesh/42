/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:43:40 by melshata          #+#    #+#             */
/*   Updated: 2025/09/17 20:59:06 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ll(char *s)
{
	ssize_t	l;

	if (!s)
		return (0);
	l = 0;
	while (s[l])
		l++;
	return (l);
}

char	*ft_strchr(char *s, char c)
{
	ssize_t i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ss;
	ssize_t	i;
	ssize_t	j;

	ss = malloc (ll(s1) + ll(s2) + 1);
	if (!ss)
		return (NULL);
	i = 0;
	if (s1)
		while (s1[i++])
			ss[i - 1] = s1[i - 1];
	j = 0;
	if (s2)
		while (s2[j])
			ss[i++] = s2[j++];
	ss[i] = '\0';
	return (ss);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammad <mohammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:31:08 by mohammad          #+#    #+#             */
/*   Updated: 2025/09/12 22:54:23 by mohammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ll(char *s, size_t t)
{
	size_t	l;

	l = 0;
	while (s[l])
	{
		if (t && s[l] == '\n')
			break ;
		l++;
	}
	return (l);
}

char	*gnl_reloc(char *s1, char *s2, size_t news, size_t rs)
{
	size_t	i;
	size_t	j;
	char	*tp;

	tp = gnl_substr(s1, 0, ll(s1, 0));
	free (s1);
	s1 = malloc (ll(tp, 0) + ll(s2, 0) + 1);
	i = ll(tp, 0);
	j = 0;
	while (tp[j])
		s1[i++] = tp[j++];
	free (tp);
	j = 0;
	while (j < rs && s1[i - 1] == '\n')
		s1[i++] = s2[j++];
		return (s1);
}

size_t	gnl_strcat(char *s1, int fd)
{
	size_t	rs;
	char	*buff;

	buff = malloc (BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	buff[BUFFER_SIZE] = '\0';
	rs = read (fd, buff, BUFFER_SIZE);
	gnl_reloc(s1, buff, ll(s1, 0) + BUFFER_SIZE + 1, rs);
	free (buff);
	return (rs);
}

char	*get_next_line(int fd)
{
	char			*ln;
	char			*tp;
	static size_t	rs;
	static char		*lo;

	if (!lo)
	{
		lo = malloc (BUFFER_SIZE + 1);
		if (!lo)
			return (NULL);
		lo[BUFFER_SIZE] = '\0';
		rs = read (fd, lo, BUFFER_SIZE);
	}
	while (!gnl_strchr(lo) && rs == BUFFER_SIZE)
		rs = gnl_strcat(lo, fd);
	ln = gnl_substr(lo, 0, ll(lo, 1));
	tp = gnl_substr(lo, ll(ln, 0), ll(lo, 0) - ll(ln, 0));
	free (lo);
	lo = gnl_substr(tp, 0, ll(tp, 0));
	return (ln);
}

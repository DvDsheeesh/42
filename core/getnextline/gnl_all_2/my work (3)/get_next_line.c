/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:43:50 by melshata          #+#    #+#             */
/*   Updated: 2025/09/17 21:18:49 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// ssize_t	ll(char *s)
// {
// 	ssize_t	l;

// 	if (!s)
// 		return (0);
// 	l = 0;
// 	while (s[l])
// 		l++;
// 	return (l);
// }

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	char	*ss;
// 	ssize_t	i;
// 	ssize_t	j;

// 	ss = malloc (ll(s1) + ll(s2) + 1);
// 	if (!ss)
// 		return (NULL);
// 	i = 0;
// 	if (s1)
// 		while (s1[i++])
// 			ss[i - 1] = s1[i - 1];
// 	j = 0;
// 	if (s2)
// 		while (s2[j])
// 			ss[i++] = s2[j++];
// 	ss[i] = '\0';
// 	return (ss);
// }

char	*extract_line(char *temp)
{
	char	*line;
	ssize_t	i;

	line = malloc (ll(temp) - ll(ft_strchr(temp, '\n')) + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (temp[i])
	{
		line[i] = temp[i];
		if (temp[i] == '\n')
			break ;
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*update_leftover(char *temp)
{
	char	*left;

	if (!ft_strchr(temp, '\n') || !temp || !*temp)
		return (NULL);
	// left = malloc (ll(ft_strchr(temp, '\n')) + 1);
	left = ft_strjoin(left, ft_strchr(temp, '\n'));
	if (!left)
		return (NULL);
	left[ll(ft_strchr(temp, '\n'))] = '\0';
	return (left);
}

void	subfun(int fd, char *temp)
{
	ssize_t	rs;
	char	*buff;
	char	*tt;

	rs = 1;
	while (!ft_strchr(temp, '\n') && rs != 0)
	{
		buff = malloc (BUFFER_SIZE + 1);
		if (!buff)
			temp = NULL;
		printf("Before read\n");//////////////////////
		rs = read(fd, buff, BUFFER_SIZE);
		printf("After %s read\n", temp);//////////////////////
		if (rs == -1)
		{
			free (buff);
			temp = NULL;
		}
		buff[rs] = '\0';
		tt = ft_strjoin(temp, buff);
		free (temp);
		temp = tt;
	}
	free (buff);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*temp;
	static char	*left;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	printf("fd is %d\n", fd);//////////////////////
	temp = ft_strjoin(left, temp);
	subfun(fd, temp);
	if (!temp)
		return (NULL);
	line = extract_line(temp);
	free (left);
	if (!line || !*line)
	{
		free (line);
		return (NULL);
	}
	left = update_leftover(temp);
	if (!*left)
	{
		free (left);
		left = NULL;
	}
	free(temp);
	return (line);
}

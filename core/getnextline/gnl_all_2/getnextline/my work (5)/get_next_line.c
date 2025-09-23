/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:43:50 by melshata          #+#    #+#             */
/*   Updated: 2025/09/20 21:27:01 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *temp)
{
	char	*line;
	ssize_t	i;

	if (schr(temp, '\n'))
		line = malloc (ll(temp) - ll(schr(temp, '\n')) + 2);
	else
		line = malloc (ll(temp) + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (temp[i])
	{
		line[i] = temp[i];
		if (temp[i++] == '\n')
			break ;
	}
	line[i] = '\0';
	return (line);
}

char	*update_leftover(char *temp)
{
	char	*left;

	if (!schr(temp, '\n') || !temp || !*temp || !ll(schr(temp, '\n') + 1))
		return (NULL);
	left = ft_strjoin(NULL, schr(temp, '\n') + 1);
	if (!left)
		return (NULL);
	return (left);
}

void	subfun(int fd, char **temp)
{
	ssize_t	rs;
	char	*buff;
	char	*tt;

	rs = 1;
	buff = malloc (BUFFER_SIZE + 1);
	if (!buff)
		*temp = NULL;
	while (!schr(*temp, '\n') && rs != 0)
	{
		rs = read(fd, buff, BUFFER_SIZE);
		if (rs == -1)
		{
			free (buff);
			*temp = NULL;
		}
		buff[rs] = '\0';
		tt = ft_strjoin(*temp, buff);
		free (*temp);
		*temp = tt;
	}
	free (buff);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*temp;
	static char	*left = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = ft_strjoin(left, NULL);
	subfun(fd, &temp);
	line = extract_line(temp);
	if (!*line)
		return (NULL);
	if (left)
		free(left);
	left = update_leftover(temp);
	if (!left)
	{
		free (left);
		left = NULL;
	}
	if (temp)
		free(temp);
	return (line);
}

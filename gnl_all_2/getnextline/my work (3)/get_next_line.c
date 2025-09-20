/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:43:50 by melshata          #+#    #+#             */
/*   Updated: 2025/09/20 16:57:38 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *temp)
{
	char	*line;
	ssize_t	i;

	if (ft_strchr(temp, '\n'))
		line = malloc (ll(temp) - ll(ft_strchr(temp, '\n')) + 2);
	else
		line = malloc (ll(temp) + 1);
	if (!line)
		return (NULL);
	printf("extract malloc %p.\n", line);//////////////////////
	i = 0;
	while (temp[i])
	{
		// printf("%c-", temp[i]);
		line[i] = temp[i];
		if (temp[i++] == '\n')
			break ;
	}
	line[i] = '\0';
	// free (temp);/////////////////////////
	return (line);
}

char	*update_leftover(char *temp)
{
	char	*left;

	if (!ft_strchr(temp, '\n') || !temp || !*temp)
		return (NULL);
	left = ft_strjoin(NULL, ft_strchr(temp, '\n') + 1);
	if (!left)
		return (NULL);
	// printf("aaaaaa%saaaaaa", left);/////////////////////
	left[ll(ft_strchr(temp, '\n'))] = '\0';
	// free (temp);/////////////////////////
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
	printf("subfun malloc %p.\n", buff);//////////////////////
	while (!ft_strchr(*temp, '\n') && rs != 0)
	{
		// printf("Before read\n");//////////////////////
		rs = read(fd, buff, BUFFER_SIZE);
		// printf("After %d read\n", rs);//////////////////////
		if (rs == -1)
		{
			free (buff);
			*temp = NULL;
		}
		buff[rs] = '\0';
		tt = ft_strjoin(*temp, buff);
		free (*temp);
		*temp = tt;
		// printf("temp is :%s --\n", *temp);//////////////////////
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
	// printf("fd is %d\n", fd);//////////////////////
	subfun(fd, &temp);
	line = extract_line(temp);
	if (!*line)
	{
		free (line);
		return ("");
	}
	if (left)
		free(left);
	// printf("temp main is :(%s) --\n", temp);//////////////////////
	left = update_leftover(temp);
	// printf("left main is :(%s) --\n", left);//////////////////////
	if (!left)
	{
		free (left);
		left = NULL;
	}
	free(temp);
	return (line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aaaaaaaaaa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:32:03 by melshata          #+#    #+#             */
/*   Updated: 2025/09/20 20:49:34 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 20
#endif

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

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

char	*schr(char *s, char c)
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
	// printf("join malloc %p.\n", ss);//////////////////////
	if (!ss)
		return (NULL);
	i = 0;
	if (s1)
		while (s1[i])
		{
			ss[i] = s1[i];
			i++;
		}
	j = 0;
	if (s2)
		while (s2[j])
			ss[i++] = s2[j++];
	ss[i] = '\0';
	return (ss);
}

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
	// printf("extract malloc %p.\n", line);//////////////////////
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

	if (!schr(temp, '\n') || !temp || !*temp || !ll(schr(temp, '\n') + 1))
		return (NULL);
	left = ft_strjoin(NULL, schr(temp, '\n') + 1);
	if (!left)
		return (NULL);
	// printf("aaaaaa%saaaaaa", left);/////////////////////
	// left[ll(schr(temp, '\n'))] = '\0';
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
	// printf("subfun malloc %p.\n", buff);//////////////////////
	while (!schr(*temp, '\n') && rs != 0)
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
	// if (!*line)
	// {
	// 	free (line);
	// 	return ("");
	// }
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

int main()
{
	int i = 0;
	char	*cc;
	// printf ("abccc\rde");
	int	fd = open("testfile copy 3.txt", O_RDONLY);
	while (i++ < 10)
	{
		cc = get_next_line(fd);
		printf("%s##################################\n", cc);
		if (cc)	
			free(cc);
	}
	return 0;
}
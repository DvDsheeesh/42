/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aaaaaaaaaa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammad <mohammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:32:03 by melshata          #+#    #+#             */
/*   Updated: 2025/09/21 17:25:06 by mohammad         ###   ########.fr       */
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
		free (*temp);
	while (!schr(*temp, '\n') && rs != 0)
	{
		rs = read(fd, buff, BUFFER_SIZE);
		if (rs == -1)
		{
			free (buff);
			free (*temp);
		}
		else
		{
			buff[rs] = '\0';
			tt = ft_strjoin(*temp, buff);
			free (*temp);
			*temp = tt;
		}
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
	if (!line || !*line)
	{
		free(temp);
		free (line);
		return (NULL);
	}
	if (left)
		free(left);
	left = update_leftover(temp);
	// if (!left)
	// {
	// 	// free (left);
	// 	left = NULL;
	// }
	if (temp)
		free(temp);
	return (line);
}

int main()
{
	char	*cc;
	int		i = 0;
	int	fd = open("testfile copy 3.txt", O_RDONLY);
	while (i < 10)
	{
		cc = get_next_line(fd);
		printf("%s##################################\n", cc);
		free(cc);
		i++;
	}
	return 0;
}
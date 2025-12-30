
#include <stdio.h> //
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"

// char	*get_next_line(int fd);
// char	*my_strjoin(char *s1, char *s2);
void	*nfree(char **s1, char **s2, char **s3);
ssize_t	ll(char *s);

/*char	*update_text(char *line)
{
	int		l;
	char	*tmp;

	if (!line)
		return (NULL);
	while (line[l] && line[l] != '\n')
		l++;
	tmp = malloc (l + 1);
	l = 0;
	while (line[l++])
		if (line[l - 1] != '\n')
			tmp[l - 1] = line[l - 1];
	tmp[l] = '\0';
	return (tmp);
}

char	**read_text(char **text, int fd)
{
	char	*line;
	char	*str;
	char	*tmp;
	
	line = get_next_line(fd);  // malloc
	str = my_strjoin(NULL, NULL);  // malloc
	while (line)
	{
		tmp = my_strjoin(str, line);  // malloc
		free(str);
		str = tmp;
		printf("%s", str);//////////////
		free(line);
		line = get_next_line(fd);
	}
	nfree(&line, &str, NULL);
	return (text);
	while (line && line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	while (line && line[0] != '\n')
	{
		//extend_text
		text = my_strjoin();
		printf("%s", line);///////
		free(line);
		line = get_next_line(fd);
	}
	while (line && line[1] == '\0')
	{
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		nfree(line, NULL, NULL);
}*/

char	*extend_str(char *s1, char *s2)
{
	char	*ss;
	ssize_t	i;
	ssize_t	j;

	ss = malloc(ll(s1) + ll(s2) + 1);
	if (!ss)
		return (NULL);
	i = 0;
	if (s1)
	{
		while (s1[i])
		{
			ss[i] = s1[i];
			i++;
		}
	}
	free(s1);
	j = 0;
	if (s2)
		while (s2[j])
			ss[i++] = s2[j++];
	//free(s2);
	ss[i] = '\0';
	return (ss);
}

char	*read_file(char **text, int fd)
{
	char	*line;
	char	*str;

	str = NULL;
	line = get_next_line(fd);  // malloc
	while (line)
	{
		str = extend_str(str, line);  // malloc
		free(line);
		line = get_next_line(fd);  // malloc
	}
	nfree(&line, NULL, NULL);
	return (str);
}

// char	**mapcpy(char **map)
// {

// }

int	isvalid(char *c, int *Ccount, int *Pcount, int *Ecount)
{
	if (*c == '0' || *c == '1' ||
		*c == 'C' || *c == 'P' || *c == 'E' ||
		(*(c) == '\n' && *(c + 1) != '\n' && *(c - 1) != '\n'))
	{
		if (*c == 'C')
			(*Ccount)++;
		if (*c == 'P')
			(*Pcount)++;
		if (*c == 'E')
			(*Ecount)++;
		return (1);
	}
	return (0);
}

int		phasing(char **text)
{
	int		i;
	int		Ccount;
	int		Pcount;
	int		Ecount;

	Ccount = 0;
	Pcount = 0;
	Ecount = 0;
	i = 0;
	while((*text)[i] && (*text)[i] == '\n')
		i++;
	while((*text)[i] && isvalid(&((*text)[i]), &Ccount, &Pcount, &Ecount))
		i++;
	while((*text)[i] && (*text)[i] == '\n')
		i++;
	printf("C=%d\nP=%d\nE=%d\n", Ccount, Pcount, Ecount);///////////
	if (text[i] || Pcount != 1 || Ecount != 1 || Ccount <= 0)
		return (0);
	return (1);
}

char	**read_and_check_nums(char *path)
{
	int		fd;
	int		Ccount;
	char	*text;
	char	**map;

	Ccount = 0;
	text = NULL;
	fd = open(path, O_RDONLY);  // check (not malloc)


	text = read_file(&text, fd);  // malloc


	Ccount = phasing(&text);  // check (not malloc)
	map = ft_split(text, '\n');  // malloc
	// check for both past lines
	free(text);

	return (map);
}

int	map_walls_check(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[0][i]&& map[0][i] == '1')
		i++;
	if (map[0][i] != '\0')
		return (0);
	j = 0;
	while (map[j] && map[j][0] == '1' && map[j][i - 1] == '1')
		j++;
	i = 0;
	while (map[j - 1][i] && map[j - 1][i] == '1')
		i++;
	if (map[j - 1][i] != '\0')
		return (0);
	return (1);
}

int		check_rect(char **map)
{
	int	i;
	int	l;
	int	old_l;

	i = 0;
	old_l = 0;
	while (map[i])
	{
		l = 0;
		while (map[i][l])
			l++;
		if (old_l != 0 && old_l != l)
		{
			printf("not a rectangle map");
			return (0);
		}
		old_l = l;
		i++;
	}
	return (1);
}

char	**map_manager(char *path)
{
	char	**map;

	map = read_and_check_nums(path);  // malloc
	printf("check walls : %dwwww\n", map_walls_check(map));///////

	printf("check rectangle : %d\n", check_rect(map));///////


	return (map);
}

int main(int ac, char **av)
{
	int		i;///////////
	// char	*path = "maplib/map.ber";//////////
	char	**map;

	if (ac != 2)
	{
		write (1, "must take path as argument\n", 27);
		return (0);
	}
	map = read_and_check_nums(av[1]);
	printf("check walls : %d\n", map_walls_check(map));///////
	i = 0;////////////
	while(map[i])////////////
	{
		printf("%s\n", map[i]);//////////
		free(map[i++]);//////////
	}
	printf("%d\n", i);///////////
	free(map);///////////
    return (0);
}

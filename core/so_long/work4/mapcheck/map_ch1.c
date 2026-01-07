/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_ch1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 09:57:35 by melshata          #+#    #+#             */
/*   Updated: 2026/01/07 11:10:37 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h> //
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "../so_long.h"
#include "get_next_line.h"

// char	*get_next_line(int fd);
// char	*my_strjoin(char *s1, char *s2);

// void	*nfree(char **s1, char **s2, char **s3);
// ssize_t	ll(char *s);

char	**freemap(char **map, char **str)
{
	int	i;

	// to print map
	i = 0;
	while (map && map[i])
		printf("%s\n", map[i++]);
	printf("%d\n", i);
	i = 0;
	while(map && map[i])
		free(map[i++]);
	if (map)
		free(map);
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}

char	*extend_str(char *s1, char *s2)
{
	char	*ss;
	ssize_t	i;
	ssize_t	j;

	ss = malloc(ll(s1) + ll(s2) + 1);  // malloc
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
	free(s2);
	ss[i] = '\0';
	return (ss);
}

char	*read_file(int fd)
{
	char	*line;
	char	*str;

	str = NULL;
	line = get_next_line(fd);  // malloc
	while (line)
	{
		str = extend_str(str, line);  // malloc
		// free(line);
		line = get_next_line(fd);  // malloc
	}
	if (line)
		free(line);
	// nfree(&line, NULL, NULL);
	return (str);
}

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
	// printf("C=%d\nP=%d\nE=%d\ntext[i]=%d\n", Ccount, Pcount, Ecount, (*text)[i]);///////////
	if ((*text)[i])
		// printf("invalid character or map shape\n");
		write (1, "Error\ninvalid character or map shape\n", 37);
	else if (Pcount != 1 || Ecount != 1 || Ccount < 1)
		// printf("wrong number of P, E, C\n");
		write (1, "Error\nwrong number of P, E, C\n", 30);
	else
		return (1);
	return (0);
}

int		empty_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

char	**read_and_check_nums(char *path)
{
	int		fd;
	char	*text;
	char	**map;
	// int		Ccount;

	// Ccount = 0;
	text = NULL;
	fd = open(path, O_RDONLY);  // check (not malloc) (done)
	if (fd < 0)
		return (NULL);
	text = read_file(fd);  // malloc (done)
	close(fd);
	if (!text)
		return (NULL);
	map = ft_split(text, '\n');  // malloc (done)
	if (phasing(&text) == 0 || !map)
		return (freemap(map, &text));

	// printf("phasing passed\n");////////
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

int		collect_num(char **map)
{
	int C_num;
	int	x;
	int	y;

	C_num = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				C_num++;
			x++;
		}
		y++;
	}
	return (C_num);
}

/*int		get_xymap(char **map, int xyflag)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
		y++;
	x = 0;
	while (map[0][x])
		x++;
	if (xyflag)
		return (y);
	return(x);
}*/

int		reach(char **map, t_point xy, char to_count, int firstcall)
{
	int counter;

	counter = 0;
	// printf("(%d, %d), %c\n", xy.x, xy.y, map[xy.y][xy.x]);/////////
	if (map[xy.y][xy.x] == to_count)
		counter++;
	map[xy.y][xy.x] = 'F';
	if (map[xy.y][xy.x + 1] != '1' && map[xy.y][xy.x + 1] != 'F')
		counter += reach(map, (t_point){xy.x + 1, xy.y}, to_count, 0);
	if (map[xy.y][xy.x - 1] != '1' && map[xy.y][xy.x - 1] != 'F')
		counter += reach(map, (t_point){xy.x - 1, xy.y}, to_count, 0);
	if (map[xy.y + 1][xy.x] != '1' && map[xy.y + 1][xy.x] != 'F')
		counter += reach(map, (t_point){xy.x, xy.y + 1}, to_count, 0);
	if (map[xy.y - 1][xy.x] != '1' && map[xy.y - 1][xy.x] != 'F')
		counter += reach(map, (t_point){xy.x, xy.y - 1}, to_count, 0);
	// printf("counter=%d\n", counter);/////////
	if (firstcall)
		freemap(map, NULL);
	return (counter);
}

t_point	xy_p(char **map)
{
	// int	x;
	// int	y;
	int	found;
	t_point	xy_point;

	found = 0;
	xy_point.y = 0;
	while (map[xy_point.y])
	{
		xy_point.x = 0;
		while (map[xy_point.y][xy_point.x])
		{
			if (map[xy_point.y][xy_point.x] == 'P')
			{
				found = 1;
				break;
			}
			xy_point.x++;
		}
		if (found)
			break;
		xy_point.y++;
	}
	return (xy_point);
}

char	**cpymap(char **map)
{
	int		i;
	int		j;
	char	**cmap;

	i = 0;
	while (map[i])
		i++;
	j = 0;
	while (map[0][j])
		j++;
	cmap = malloc(sizeof(char *) * (i + 1));
	cmap[i] = NULL;
	i = 0;
	while (map[i])
	{
		cmap[i] = malloc(j + 1);
		if (!cmap[i])
			return (freemap(cmap, NULL));
		j = 0;
		while (map[i][j++])
			cmap[i][j - 1] = map[i][j - 1];
		cmap[i][j - 1] = '\0';
		i++;
	}
	return (cmap);
}

int		map_check_rect(char **map)
{
	int	i;
	int	l;
	int	old_l;
	int	C_num;

	i = 0;
	old_l = 0;
	while (map[i])
	{
		l = 0;
		while (map[i][l])
			l++;
		if (old_l != 0 && old_l != l)
		{
			// printf("not a rectangle map\n");
			write (1, "ERROR\nnot a rectangle map\n", 26);
			return (0);
		}
		old_l = l;
		i++;
	}
	/*C_num = collect_num(map);
	if (reach(map, l, i, xy_p(map, 0), xy_p(map, 1)) == C_num)
		return (1);
	return (0);*/
	return (1);
}

int		check_extention(char *path, char const *ber)
{
	int	i;
	int	num_match;

	i = 0;
	while (path[i])
		i++;
	i -= 4;
	num_match = 0;
	while (path[i])
	{
		if (path[i] == ber[num_match])
			num_match++;
		i++;
	}
	if (num_match != 4)
		return (0);
	return (1);
}

char	**map_manager(char *path)
{
	char	**map;
	int		C_num;

	map = read_and_check_nums(path);  // malloc
	if (!map)
	// {
		// printf("bad\n");
		return (NULL);
	// }
	// C_num = collect_num(map);
	// printf("check walls : %d\n", map_walls_check(map));

	//printf("check rect : %d\n", map_check_rect(map));
	if (map_walls_check(map) == 0 || map_check_rect(map) == 0)
		// printf("check walls or check rectangle wrong\n");
		write (1, "Error\ncheck walls or check rectangle wrong\n", 43);
	else if (	reach(cpymap(map), xy_p(map), 'E', 1) != 1 ||
				reach(cpymap(map), xy_p(map), 'C', 1) != collect_num(map))
		// printf("couldn't reach all C and E\n");
		write (1, "Error\ncouldn't reach all C and E\n", 33);
	else
		return (map);
	freemap(map, NULL);
	return (NULL);
}

int main(int ac, char **av)
{
	int		i;///////////
	// char	*path = "maplib/map.ber";//////////
	char	**map;

	if (ac != 2 || check_extention(av[1], ".ber") == 0)
	{
		printf("bad extention\n");
		write (1, "Error\nmust take path as argument\n", 33);
		return (0);
	}
	map = map_manager(av[1]);
	// map = read_and_check_nums(av[1]);
	// printf("check walls : %d\n", map_walls_check(map));///////
	if (map)
		freemap(map, NULL);
    return (0);
}


#include <stdio.h>
#include "flood_fill.h"

int  flood_fill(char **tab, t_point size, t_point begin)
{
	int counter = 0;

	printf("(%d, %d), %c\n", begin.x, begin.y, tab[begin.y][begin.x]);
	if (tab[begin.y][begin.x] == 'C')
		counter++;
	tab[begin.y][begin.x] = 'F';

	if (begin.x + 1 < size.x && tab[begin.y][begin.x + 1] != '1' && tab[begin.y][begin.x + 1] != 'F')
		counter += flood_fill(tab, size, (t_point){begin.x + 1, begin.y});
	if (begin.x - 1 >= 0 	 && tab[begin.y][begin.x - 1] != '1' && tab[begin.y][begin.x - 1] != 'F')
		counter += flood_fill(tab, size, (t_point){begin.x - 1, begin.y});

	if (begin.y + 1 < size.y && tab[begin.y + 1][begin.x] != '1' && tab[begin.y + 1][begin.x] != 'F')
		counter += flood_fill(tab, size, (t_point){begin.x, begin.y + 1});
	if (begin.y - 1 >= 0 	 && tab[begin.y - 1][begin.x] != '1' && tab[begin.y - 1][begin.x] != 'F')
		counter += flood_fill(tab, size, (t_point){begin.x, begin.y- 1});

	return (counter);

	// printf("%s, (%d,%d), (%d,%d)\n\n", tab[0], size.x, size.y, begin.x, begin.y);////////////////
	// while ()
}

char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}

char	**mapcpy(char **map)
{
	char	**map2;
	int		lines;
	int		len;
	int		i;

	lines = 0;
	len = 0;
	if (map && map[0])
	{
		while (map[lines])
			lines++;
		while (map[0][len])
			len++;
	}
	map2 = malloc(sizeof(char **) * (lines + 1));
	map2[lines] = NULL;
	while (lines)
	{
		map2[lines - 1] = malloc(len + 1);
		map2[lines - 1][len] = '\0';
		i = 0;
		while (i < len)
		{
			///////////////////////////////////////////////////////
			i++;
		}
	}
}

int main(void)
{
	t_point size = {8, 5};
	char *zone[] = {
		"11111111",
		"10C01C01",
		"10010C01",
		"1011EP01",
		"11100001",
	};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	t_point begin = {5, 3};
	//mapcpy
	
	printf("%d\n", flood_fill(area, size, begin));
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}
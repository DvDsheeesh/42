
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

char	**new_text(char **text, char *line)
{
	int	l;
	int	ll;

	l = 0;
	while (text && text[l])
		l++;
	ll = 0;
	while (text && text[0] && text[0][ll])
		ll++;

}

char	**read_text(char **text, int fd)
{
	char	*line;
	
	line = get_next_line(fd);
	while (line)
	{
		//extend_text
		free(line);
		line = get_next_line(fd);
	}
}

int main(int ac, char **av)
{
	int		fd;
	char	**text;
	char	*path = "/home/melshata/Desktop/github_folder/42/core/so_long/textlib/text.ber";

	fd = open(path, O_RDONLY);
	text = read_text(text, fd);
    return (0);
}
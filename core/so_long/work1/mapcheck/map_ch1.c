
#include <stdio.h> //
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char	*get_next_line(int fd);
char	*my_strjoin(char *s1, char *s2);
void	*nfree(char **s1, char **s2, char **s3);

char	*update_text(char *line)
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
	
	line = get_next_line(fd);
	str = my_strjoin(NULL, NULL);
	while (line)
	{
		tmp = my_strjoin(str, line);
		free(str);
		str = tmp;
		printf("%s", str);
		free(line);
		line = get_next_line(fd);
	}
	nfree(&line, &str, NULL);
	/*
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
	*/
	return (text);
}

int main(int ac, char **av)
{
	int		fd;
	char	**text = NULL;
	char	*path = "maplib/map.ber";

	fd = open(path, O_RDONLY);
	//printf("%d", fd);
	text = read_text(text, fd);
	//printf("%p", text);
    return (0);
}
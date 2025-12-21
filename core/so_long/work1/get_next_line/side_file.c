// char	*subfun(int fd, char *left)
// {
// 	char	*buffer;
// 	ssize_t	bytes_read;
// 	char	*temp;

// 	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
// 	if (!buffer)
// 		return (NULL);
// 	bytes_read = 1;
// 	while (bytes_read > 0 && !ft_strchr(left, '\n'))
// 	{
// 		bytes_read = read(fd, buffer, BUFFER_SIZE);
// 		if (bytes_read == -1)
// 		{
// 			free(buffer);
// 			return (NULL);
// 		}
// 		buffer[bytes_read] = '\0';
// 		temp = ft_strjoin(left, buffer);
// 		free(left);
// 		left = temp;
// 	}
// 	free(buffer);
// 	return (left);
// }

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		i;
	char	*cc;
	char	*name;
	int		fd;

	i = 0;
	name = "txt";
	fd = open(name, O_RDONLY);
	cc = get_next_line(fd);
	printf("%d: %s\n", ++i, cc);
	free(cc);
	cc = get_next_line(fd);
	printf("%d: %s\n", ++i, cc);
	free(cc);
	close(fd);
	cc = get_next_line(fd);
	printf("%d: %s\n", ++i, cc);
	free(cc);
	fd = open(name, O_RDONLY);
	cc = get_next_line(fd);
	printf("%d: %s\n", ++i, cc);
	free(cc);
	cc = get_next_line(fd);
	printf("%d: %s\n", ++i, cc);
	free(cc);
	cc = get_next_line(fd);
	printf("%d: %s\n", ++i, cc);
	free(cc);
	cc = get_next_line(fd);
	printf("%d: %s\n", ++i, cc);
	free(cc);
	cc = get_next_line(fd);
	printf("%d: %s\n", ++i, cc);
	free(cc);
}

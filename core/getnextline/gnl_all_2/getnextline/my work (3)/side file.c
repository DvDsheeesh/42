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

int main()
{
	int i = 0;
	char	*cc;
	// printf ("abccc\rde");
	int	fd = open("testfile copy 3.txt", O_RDONLY);
	while (i++ < 10)
	{
		cc = get_next_line(fd);
		printf("%s", cc);	
		free(cc);
	}
	return 0;
}
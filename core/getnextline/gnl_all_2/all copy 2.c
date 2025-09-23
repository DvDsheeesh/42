

#define BUFFER_SIZE 11

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

char	*gnl_strchr(const char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	if (s[i] == '\n')
		return ((char *)s + i + 1);
	return (NULL);
}

char	*gnl_strdup(char const *s, size_t len)
{
	char	*sus;
	size_t	i;

	sus = malloc (len + 1);
	if (!sus)
		return (NULL);
	i = 0;
	while (i < len && s[i])
	{
		sus[i] = s[i];
		i++;
	}
	sus[i] = '\0';
	return (sus);
}

size_t	ll(char *s, size_t t)
{
	size_t	l;

	l = 0;
	while (s[l])
	{
		if (t && s[l] == '\n')
			break ;
		l++;
	}
	return (l);
}

char	*gnl_reloc(char *s1, char *s2, size_t news, size_t rs)
{
	size_t	i;
	size_t	j;
	char	*tp;

	tp = malloc (news + 1);
	if (!tp)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		tp[i++] = s1[j++];
	j = 1;
	while (j < rs && s2[j - 1] != '\n')
		tp[i++] = s2[j++ - 1];
	tp[news] = '\0';
	return (tp);
}

size_t	gnl_strcat(char **s1, int fd)
{
	size_t	rs;
	char	*buff;
	char	*tp;

	buff = malloc (BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	rs = read (fd, buff, BUFFER_SIZE);
	buff[rs] = '\0';
	tp = gnl_reloc(*s1, buff, ll(*s1, 0) + BUFFER_SIZE, rs);
	free (*s1);
	*s1 = gnl_strdup(tp, ll(tp, 0));
	free (buff);
	free (tp);
	return (rs);
}

char	*get_next_line(int fd)
{
	char			*ln;
	char			*tp;
	static ssize_t	rs;
	static char		*lo;

	if (!lo)
	{
		lo = malloc (BUFFER_SIZE + 1);
		if (!lo)
			return (NULL);
		rs = read (fd, lo, BUFFER_SIZE);
		lo[rs] = '\0';
	}
	while (!gnl_strchr(lo) && rs == BUFFER_SIZE)
	{
		rs = gnl_strcat(&lo, fd);
		printf("%zd ", rs);
	}
	ln = gnl_strdup(lo, ll(lo, 1));
	tp = gnl_strdup(gnl_strchr(lo), ll(lo, 0) - ll(ln, 0));
	if (!tp|| !ln)
		return (NULL);
	free (lo);
	lo = gnl_strdup(tp, ll(tp, 0));
	free (tp);
	return (ln);
}

int main()
{
    int     fd;
    char    *line;
    // int     line_count = 1;

    // Open the test file
    fd = open("testfile.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }
	line = get_next_line(fd);
	printf("%s", line);
	// line = get_next_line(fd);

	// free (line); // Free the memory allocated by get_next_line

    // Close the file descriptor
    close(fd);

    return (0);
}

/*
the file opend have this content:

hi my brother
i am your uncle
you are my son
*/




// int	main()
// {
// 	int fd = open("testfile.txt", O_RDONLY);
// 	char	*imp;

// 	imp = malloc (BUFFER_SIZE + 1);
// 	if (!imp)
// 		return (0);
// 	imp[BUFFER_SIZE] = '\0';
// 	// printf("%ld", read (fd, imp, BUFFER_SIZE));
// 	// printf("%s\n", imp);
// 	// printf("%ld", read (fd, imp, BUFFER_SIZE));
// 	// printf("%s", imp);
// 	// printf("%ld", read (fd, imp, BUFFER_SIZE));
// 	// printf("%s", imp);
// 	// printf("%ld", read (fd, imp, BUFFER_SIZE));
// 	// printf("%s", imp);
// 	// printf("%ld", read (fd, imp, BUFFER_SIZE));
// 	// printf("%s", imp);
// 	imp = get_next_line(fd);
// 	write (1, imp, BUFFER_SIZE);
// 	// imp = get_next_line(fd);
// 	// write (1, imp, BUFFER_SIZE);
// 	// imp = get_next_line(fd);
// 	// write (1, imp, BUFFER_SIZE);
// 	free (imp);
// 	close (fd);
// }
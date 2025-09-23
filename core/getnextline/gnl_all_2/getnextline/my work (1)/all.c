

#define BUFFER_SIZE 5

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
	else
		return (NULL);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	char	*sus;
	size_t	i;

	// if (len == 0)
	// 	len = (size_t)gnl_strchr(s) - (size_t)(&s[start]);
	sus = (char *)malloc (len + 1);
	if (!sus)
		return (NULL);
	i = 0;
	while (i < len && s[i])
	{
		sus[i] = s[start + i];
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

char	*gnl_reloc(char **s1, char *s2, size_t news, size_t rs)
{
	size_t	i;
	size_t	j;
	char	*tp;

	tp = gnl_substr(*s1, 0, ll(*s1, 0));
	free (*s1);
	*s1 = malloc (ll(tp, 0) + ll(s2, 0) + 1);
	i = ll(tp, 0);
	j = 0;
	while (tp[j])
		(*s1)[i++] = tp[j++];
	free (tp);
	j = 0;
	while (j < rs && (*s1)[i - 1] != '\n')
		(*s1)[i++] = s2[j++];
	return (*s1);
}

size_t	gnl_strcat(char **s1, int fd)
{
	size_t	rs;
	char	*buff;

	buff = malloc (BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	buff[BUFFER_SIZE] = '\0';
	rs = read (fd, buff, BUFFER_SIZE);
	*s1 = gnl_reloc(s1, buff, ll(*s1, 0) + BUFFER_SIZE + 1, rs);
	free (buff);
	return (rs);
}

char	*get_next_line(int fd)
{
	char			*ln;
	char			*tp;
	static size_t	rs;
	static char		*lo;

	if (!lo)
	{
		lo = malloc (BUFFER_SIZE + 1);
		if (!lo)
			return (NULL);
		lo[BUFFER_SIZE] = '\0';
		rs = read (fd, lo, BUFFER_SIZE);
	}
	while (!gnl_strchr(lo) && rs == BUFFER_SIZE)
		rs = gnl_strcat(&lo, fd);
	ln = gnl_substr(lo, 0, ll(lo, 1));
	tp = gnl_substr(lo, ll(ln, 0), ll(lo, 0) - ll(ln, 0));
	free (lo);
	lo = gnl_substr(tp, 0, ll(tp, 0));
	return (ln);
}




int	main()
{
	int fd = open("testfile.txt", O_RDONLY);
	char	*imp;

	imp = malloc (BUFFER_SIZE + 1);
	if (!imp)
		return (0);
	imp[BUFFER_SIZE] = '\0';
	// printf("%ld", read (fd, imp, BUFFER_SIZE));
	// printf("%s\n", imp);
	// printf("%ld", read (fd, imp, BUFFER_SIZE));
	// printf("%s", imp);
	// printf("%ld", read (fd, imp, BUFFER_SIZE));
	// printf("%s", imp);
	// printf("%ld", read (fd, imp, BUFFER_SIZE));
	// printf("%s", imp);
	// printf("%ld", read (fd, imp, BUFFER_SIZE));
	// printf("%s", imp);
	imp = get_next_line(fd);
	write (1, imp, BUFFER_SIZE);
	imp = get_next_line(fd);
	write (1, imp, BUFFER_SIZE);
	imp = get_next_line(fd);
	write (1, imp, BUFFER_SIZE);
	free (imp);
	close (fd);
}

/*
the file opend have this content:

hi my brother
i am your uncle
you are my son
*/
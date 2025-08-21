#include <unistd.h>

void	ft_putstr(char *str)
{
	int	l;

	l = 0;
	while (str[l])
		l++;
	write (1, str, l);
}

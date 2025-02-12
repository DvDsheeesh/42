#include <unistd.h>
#include <stdlib.h>

int	lenn (char *str)
{
	int	l;
	
	l = 0;
	while (str[l])
		l++;
	return (l);
}

void	aaa(char *str, int n)
{
	int		l;
	char	c;

	l = lenn (str);
	if (l == n)
	{
		if (str[l - 1] > ('0' + l - 1))
			write (1, ", ", 2);
		write (1, str, n);
	}
	else
	{
		if (!l)
			c = '0';
		else
			c = str[l - 1] + 1;
		while (c <= ('9' - n + l + 1))
		{
			str[l] = c;
			str[l + 1] = 0;
			aaa(str, n);
			c++;
		}
	}
}

void	ft_print_combn(int n)
{
	char*	str;

	str = malloc (n + 1);
	aaa(str, n);
}
/*
int	main(int ac, char** av)
{
	if (ac != 2)
	{
		write (1, "invalid input!", 14);
		return (0);
	}
	ft_print_combn (av[1][0] - '0');
}*/

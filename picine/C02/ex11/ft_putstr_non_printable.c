#include <unistd.h>

void	prihex(char c)
{
	char	t;

	write (1, "\\", 1);
	t = c / 16 + '0';
	write (1, &t, 1);
	t = c % 16;
	if (t < 10)
		t += '0';
	else
		t += ('a' - 10);
	write (1, &t, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] < 32 || str[i] > 126))
			write (1, &str[i], 1);
		else
			prihex(str[i]);
		i++;
	}
}

#include <unistd.h>

void	ft_print_comb2(void)
{
	int	x;
	int	y;
	int	p[4];

	x = 0;
	while (x < 100)
	{
		y = x + 1;
		while (y < 100)
		{
			p[0] = x / 10 + 48;
			p[1] = x % 10 + 48;
			p[2] = y / 10 + 48;
			p[3] = y % 10 + 48;
			write(1, &p[0], 1);
			write(1, &p[1], 1);
			write (1, " ", 1);
			write(1, &p[2], 1);
			write(1, &p[3], 1);
			if (! (x == 98 && y == 99))
				write (1, ", ", 2);
			y++;
		}
		x++;
	}
}

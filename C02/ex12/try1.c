#include <unistd.h>
#include <stdio.h>

void	ft_putstr(char *str, int n, int lim)
{
	char	c;
	int		i;

	i = 0;
	while (i < lim)
	{
		if (str[i + n * 16] >= 32 && str[i + n * 16] <= 126)
			write (1, &str[i + n * 16], 1);
		else
			write (1, ".", 1);
		i++;
	}
}

void	hexaddr(unsigned long long nb, int i)
{
	if (i < 15)
		hexaddr(nb / 16, i + 1);
	nb = nb % 16;
	if (nb < 10)
		nb += '0';
	else
		nb += ('a' - 10);
	write (1, &nb, 1);
}

void	hexdata(char *str, int n, int lim)
{
	int		i;
	char	c;

	i = 0;
	while (i < 16)
	{
		if (i < lim)
		{
			c = str[i + n * 16] / 16 + '0';
			write (1, &c, 1);
			c = str[i + n * 16] % 16;
			if (c < 10)
				c += '0';
			else
				c += ('a' - 10);
			write (1, &c, 1);
		}
		else
			write (1, "  ", 2);
		if (i % 2)
			write (1, " ", 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned long long	address;
	unsigned int		i;
	unsigned int		t;

	i = 0;
	while (i < (size - 1) / 16 + 1)
	{
		t = size - (i * 16);
		address = ((unsigned long long)addr) + (i * 16);
		hexaddr (address, 0);
		write (1, ": ", 2);
		hexdata (*(char**)addr, i, t * (t < 16) + 16 * (t >= 16));
		ft_putstr (*(char**)addr, i, t * (t < 16) + 16 * (t >= 16));
		write (1, "\n", 1);
		i++;
	}
	return (addr);
}
/*
int main()
{
    char*	x = "hi my brother :)aa  bb  cc  dd \tg"; //6869 206D 7920 6272 6F74 6865 7220 3A29
    									  //6162 6364 6566
    char**	y;
    //unsigned long t, c;
    void*	addr;

    //x = 5;
    //y = &x;
    addr = &x;
	ft_print_memory (addr, 34);
	//printf ("\n%ld\n", sizeof (unsigned int));
	//hexdata (x);
	//write (1, &x[0 + 16], 4);
	//write (1, "\n", 1);
}*/

#include <unistd.h>
#include <stdio.h>

void	ft_putstr(void *addr)
{
	char *str;

	str = *(char**)addr;
	write (1, str, 16);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write (1, "-", 1);
		nb *= -1;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	nb = nb % 10 + '0';
	write (1, &nb, 1);
}

void	ft_puthex(unsigned long long nb, int i, int b)
{
	if (i < b * 2 - 1)
		ft_puthex(nb / 16, i + 1, b);
	nb = nb % 16;
	if (nb < 10)
		nb += '0';
	else
		nb += ('a' - 10);
	write (1, &nb, 1);
}

void	hexcon(void *addr, int n)
{
	int	i;
	unsigned long long	c;

	c = **(unsigned long long**)addr;
	i = 1;
	while (i < n)
	{
		c = c / 0x100;
		i++;
	}
	ft_puthex(c, 0, 1);
	if (n != 16 && n % 2 == 0)
		write (1, " ", 1);
	if (n < 16)
		hexcon(addr, n + 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned long long	address;
	unsigned long long	c;

	address = (unsigned long long)addr;
	ft_puthex(address, 0, 8);
	write (1, ": ", 2);
	hexcon (addr, 1);
	c = **(unsigned long long**)addr;
	write (1, " ", 1);
	ft_putstr (addr);       /////////////////////
	return (addr);
}

int main()
{
    char*	x = "hi my brother :)abcdef"; //6869 206D 7920 6272 6F74 6865 7220 3A29
    unsigned long long*	y;
    //unsigned long t, c;
    void*	addr;

    //x = 5;
    //y = &x;
    addr = &x;
	ft_print_memory (addr, 1);
	//printf ("\n%ld\n", sizeof (unsigned int));
/*
    t = (unsigned long) addr;
    ft_puthex(t, 0, 8);
    
    c = **(unsigned long**)addr;
    //c = *(unsigned long*)c;
    printf("\n   %ld\n", c);
    
    addr += 16;
    t = (unsigned long) addr;
    //t = 574200121902233591;
    
	printf ("\n");
	ft_puthex(t, 0, 2);
	printf ("\n%ld\n", t);
	
	//write (1, &t, 1);
    //printf("Address of x = %p, value of x = %d\n", &x, x);
    //printf("Address of y = %p, value of y = %p, value of *y = %d\n", &y, y, *y);
    */
    return (0);
}

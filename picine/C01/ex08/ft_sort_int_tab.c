void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	t;
	int	p;

	i = 0;
	while (i < size)
	{
		p = 0;
		while (p < size - 1)
		{
			if (tab[p] > tab[p + 1])
			{
				t = tab[p];
				tab[p] = tab[p + 1];
				tab[p + 1] = t;
			}
			p++;
		}
		i++;
	}
}
/*
#include <stdio.h>
int	main(void)
{
	int	tab[] = {4, 5, 2, 5, 8, 3, 6, 1};
	ft_sort_int_tab(tab, 8);
	for (int i = 0; i < 8; i++)
	{
		printf ("%d ", tab[i]);
	}
	return (0);
}*/

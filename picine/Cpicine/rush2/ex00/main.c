/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:54:55 by melshata          #+#    #+#             */
/*   Updated: 2025/01/17 17:28:36 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int		length(char *num);
char	*leftpart(char *num, int n);
char	*noz_num(char *num, int l);
char	*trim(char *num, int n, int l);
void	print_digits(char *str);

void	loop(char *num, int l)
{
	int		n;
	char	*lp;
	char	*temp1;
	char	*temp2;

	n = 0;
	temp2 = malloc(l + 1);
	temp2 = num;
	while (l > 0)
	{
		n = (l - 1) % 3 + 1;
		lp = malloc (n + 1);
		lp = leftpart (temp2, n);
		write(1, lp, n);
		//print_digits (lp);
		if (l <= 3)
			break ;
		temp1 = malloc (l - n + 1);
		temp1 = trim (temp2, n, l);
		l = length (temp1);
		free(temp2);
		temp2 = malloc(l + 1);
		temp2 = noz_num(temp1, l);
		free(temp1);
		free (lp);
	}
}

int	main(int ac, char **av)
{
	int		l;
	char	*num;
	
	if (av[1][0] == '0' && av[1][1] == '\0')
	{
		write (1, "zero", 4);
		return (0);
	}

	l = length (av[ac - 1]);
	if (l == 0)
	{
		write (1, "Error\n", 5);
		return (0);
	}
	num = malloc(l);
	num = noz_num(av[ac - 1], l);
	loop (num, l);
	return (0);
}

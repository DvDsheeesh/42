/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 12:50:02 by melshata          #+#    #+#             */
/*   Updated: 2025/01/11 12:50:03 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
// cc base.c check.c main.c out.c -Wall -Wextra -Werror

int		checkall(int *in, char *out);
void	outnew(int t, char *out);
void	outprint(char *out);

int	insplit(int *in, char *av)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		in[i] = av[i * 2] - '0';
		if (in[i] > 4 || in[i] < 1)
		{
			write (1, "Error", 5);
			return (1);
		}
		i++;
	}
	return (0);
}

int	main(int ac, char *av[])
{
	int		in[16];
	char	out[16];

	if (ac != 2)
	{
		write (1, "Error", 1);
		return (0);
	}
	if (insplit(in, av[1]))
		return (0);
	outnew (0, out);
	if (checkall(in, out))
		outprint (out);
	return (0);
}

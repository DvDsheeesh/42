/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:53:14 by melshata          #+#    #+#             */
/*   Updated: 2025/01/03 20:53:45 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	xx;
	int	yy;

	yy = 1;
	while (yy <= y)
	{
		xx = 1;
		while (xx <= x)
		{
			if (xx == 1 && (yy == 1 || yy == y))
				ft_putchar('A');
			else if (xx == x && (yy == 1 || yy == y))
				ft_putchar('C');
			else if (xx == 1 || xx == x || yy == 1 || yy == y)
				ft_putchar('B');
			else
				ft_putchar(' ');
			xx++;
		}
		ft_putchar('\n');
		yy++;
	}
}

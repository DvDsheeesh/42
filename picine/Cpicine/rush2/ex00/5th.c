/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5th.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:52:08 by melshata          #+#    #+#             */
/*   Updated: 2025/01/18 21:53:04 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*noz_num(char *num, int l);

int		ft_strlen(char *str);
void	print_tens(char *str, int i);
void	print_ones(char *str, int i);
void	print_tens2(int i, char *str);

void	ft_write_digits(char *str)
{
	int	i;

	i = 0;
	print_ones(str, 0);
	if (str[i] > '0')
		write(1, "hundred ", 8);
	i++;
	print_tens2(i, str);
	i++;
	print_ones(str, i);
}

void	print_digits(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (i == 2)
		ft_write_digits(str);
	else if (i == 1)
		print_tens2(i - 1, str);
	else
		print_ones(str, i);
}

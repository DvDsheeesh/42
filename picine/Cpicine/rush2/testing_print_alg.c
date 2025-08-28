/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_print_alg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialausud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:29:02 by ialausud          #+#    #+#             */
/*   Updated: 2025/01/18 21:39:13 by ialausud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i -1);
}

void	print_tens(char *str, int i)
{
	if (str[i] == '9')
		write(1, "nineteen ", 9);
	else if (str[i] == '8')
		write(1, "eighteen ", 9);
	else if (str[i] == '7')
		write(1, "seventeen ", 10);
	else if (str[i] == '6')
		write(1, "sexteen ", 8);
	else if (str[i] == '5')
		write(1, "fifteen ", 8);
	else if (str[i] == '4')
		write(1, "fourteen ", 9);
	else if (str[i] == '3')
		write(1, "thurteen ", 9);
	else if (str[i] == '2')
		write(1, "twelve ", 7);
	else if (str[i] == '1')
		write(1, "eleven ", 7);
}

void	print_ones(char *str, int i)
{
	if (str[i] == '9')
		write(1, "nine ", 5);
	else if (str[i] == '8')
		write(1, "eight ", 6);
	else if (str[i] == '7')
		write(1, "seven ", 6);
	else if (str[i] == '6')
		write(1, "sex ", 4);
	else if (str[i] == '5')
		write(1, "five ", 5);
	else if (str[i] == '4')
		write(1, "four ", 5);
	else if (str[i] == '3')
		write(1, "three ", 6);
	else if (str[i] == '2')
		write(1, "two ", 4);
	else if (str[i] == '1')
		write(1, "one ", 4);
}

void	print_tens2(int i, char *str)
{
	if (str[i] == '9')
		write(1, "ninety ", 7);
	else if (str[i] == '8')
		write(1, "eighty ", 7);
	else if (str[i] == '7')
		write(1, "seventy ", 8);
	else if (str[i] == '6')
		write(1, "sexty ", 6);
	else if (str[i] == '5')
		write(1, "fifty ", 6);
	else if (str[i] == '4')
		write(1, "forty ", 6);
	else if (str[i] == '3')
		write(1, "thirty ", 7);
	else if (str[i] == '2')
		write(1, "twenty ", 7);
	print_ones(str, i + 1);
	return ;
}

void	ft_write_digits(char *str, int index)
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
		ft_write_digits(str, i);
	else if (i == 1)
		print_tens2(i - 1, str);
	else if (i == 0)
		print_ones(str, i);
}

int	main(void)
{
	char	*h;

	h = "995";
	print_digits(h);
}

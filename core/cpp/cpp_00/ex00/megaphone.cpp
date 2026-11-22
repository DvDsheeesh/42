/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 20:27:52 by melshata          #+#    #+#             */
/*   Updated: 2026/11/22 20:27:53 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	ft_toupper(int c)
{
	if (c <= 'z' && c >= 'a')
		c -= 32;
	return (c);
}

int main(int ac, char **av)
{
	std::string str;
	if (ac == 1)
		str = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		str = av[1];
	for (int i = 0; str[i] != '\0'; i++)
	{
		std::cout << char(ft_toupper(str[i]));
	}
	std::cout << "\n";
	return 0;
}
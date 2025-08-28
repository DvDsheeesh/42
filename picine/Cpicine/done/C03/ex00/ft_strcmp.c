/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:16:52 by melshata          #+#    #+#             */
/*   Updated: 2025/01/13 16:33:35 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}
//
//void	ft_putnbr(int nb)
//{
//	if (nb == -2147483648)
//	{
//		write (1, "-2147483648", 11);
//		return;
//	}
//	if (nb < 0)
//	{
//		write (1, "-", 1);
//		nb *= -1;
//	}
//	if (nb > 9)
//		ft_putnbr(nb / 10);
//	nb = nb % 10;
//	nb += '0';
//	write (1, &nb, 1);
//}
//
//int	main(void)
//{
//	char	*s1 = "hi bro1";
//	char	*s2 = "hi bro5";
//	ft_putnbr(ft_strcmp(s1, s2));
//	return (0);
//}

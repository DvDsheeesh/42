/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:10:25 by melshata          #+#    #+#             */
/*   Updated: 2025/01/11 14:10:27 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*passing(int *temp, char *out, int *k);

void	shuffout(char *out, int *k)
{
	int	i;
	int	j;
	int	temp[16];

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			temp[i * 4 + j] = out[i * 4 + (k[j] - 1)];
			j++;
		}
		i++;
	}
	out = passing(temp, out, k);
}

char	*passing(int *temp, char *out, int *k)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			out[i * 4 + j] = temp[k[i + 4] - 1 * 4 + j];
			j++;
		}
		i++;
	}
	return (out);
}
//
//void	keygen(int *k)
//{
//	
//}
//
//void	arr6(int t)
//{
//
//}

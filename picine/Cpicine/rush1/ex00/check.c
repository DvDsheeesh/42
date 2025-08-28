/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 12:49:56 by melshata          #+#    #+#             */
/*   Updated: 2025/01/11 12:49:58 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	zero(int *max, int *count)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		max[i] = 0;
		count[i] = 0;
		i++;
	}
}

int	checkupdown(int d, int *in, char *out)
{
	int	i;
	int	max[4];
	int	count[4];

	zero(max, count);
	i = 15 * d;
	while (i != (16 - d * 17))
	{
		if (max[i % 4] < out[i])
		{
			max[i % 4] = out[i];
			count[i % 4]++;
		}
		i += (d * -2) + 1;
	}
	i = 0;
	while (i < 4)
	{
		if (count[i] != in[d * 4 + i])
			return (0);
		i++;
	}
	return (1);
}

int	checkleftright(int d, int *in, char *out)
{
	int	i;
	int	max[4];
	int	count[4];

	zero(max, count);
	i = 15 * d;
	while (i != (16 - d * 17))
	{
		if (max[i / 4] < out[i])
		{
			max[i / 4] = out[i];
			count[i / 4]++;
		}
		i += (d * -2) + 1;
	}
	i = 0;
	while (i < 4)
	{
		if (count[i] != in[d * 4 + i + 8])
			return (0);
		i++;
	}
	return (1);
}

int	checkall(int *in, char *out)
{
	int	ch;

	ch = checkupdown(0, in, out);
	ch *= checkupdown(1, in, out);
	ch *= checkleftright(0, in, out);
	ch *= checkleftright(1, in, out);
	return (ch);
}

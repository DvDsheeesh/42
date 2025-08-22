/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammad <mohammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 16:16:39 by mohammad          #+#    #+#             */
/*   Updated: 2025/08/22 16:31:24 by mohammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*cc;

	cc = ft_strdup(s);
	if (!cc)
		return (NULL);
	i = 0;
	while (s[i])
	{
		cc[i] = f (i, s[i]);
		i++;
	}
	return (cc);
}
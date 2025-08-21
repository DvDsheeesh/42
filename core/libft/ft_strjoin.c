/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammad <mohammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:46:19 by mohammad          #+#    #+#             */
/*   Updated: 2025/08/21 13:55:45 by mohammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*c;

	c = (char *)malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!c)
		return (NULL);
	bzero ((void *)c, ft_strlen(s1) + ft_strlen(s2) + 1);
	strcpy (c, s1);
	strcat (c, s2);
	return (c);
}
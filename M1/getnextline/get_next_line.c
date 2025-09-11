/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammad <mohammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:31:08 by mohammad          #+#    #+#             */
/*   Updated: 2025/09/09 11:21:18 by mohammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*leftover;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// leftover = malloc (BUFFER_SIZE + 1);
	// if (!leftover)
	// 	return (NULL);
	// leftover[BUFFER_SIZE] = '\0';
	
	read (fd, leftover, BUFFER_SIZE);
	return (line);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:31:08 by mohammad          #+#    #+#             */
/*   Updated: 2025/09/11 15:13:17 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*leftover;

	if (!leftover)
		read (fd, leftover, BUFFER_SIZE);
	
		
	read (fd, leftover, BUFFER_SIZE);
	// return (line);
}


// if (fd < 0 || BUFFER_SIZE <= 0)
// 	return (NULL);
// leftover = malloc (BUFFER_SIZE + 1);
// if (!leftover)
// 	return (NULL);
// leftover[BUFFER_SIZE] = '\0';
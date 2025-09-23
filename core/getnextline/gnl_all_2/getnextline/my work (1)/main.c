/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 21:42:15 by mohammad          #+#    #+#             */
/*   Updated: 2025/09/17 15:55:29 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>



int	main()
{
	int fd = open("testfile.txt", O_RDONLY);

	printf("line = %s", get_next_line(fd));
	printf("line = %s", get_next_line(fd));
	// printf("line = %s", get_next_line(fd));
	// printf("line = %s", get_next_line(fd));
	// char	*imp;

	// imp = malloc (BUFFER_SIZE + 1);
	// if (!imp)
	// 	return (0);
	// imp[BUFFER_SIZE] = '\0';
	// printf("%ld", read (fd, imp, BUFFER_SIZE));
	// printf("%s\n", imp);
	// printf("%ld", read (fd, imp, BUFFER_SIZE));
	// printf("%s", imp);
	// printf("%ld", read (fd, imp, BUFFER_SIZE));
	// printf("%s", imp);
	// printf("%ld", read (fd, imp, BUFFER_SIZE));
	// printf("%s", imp);
	// printf("%ld", read (fd, imp, BUFFER_SIZE));
	// // printf("%s", imp);
	// imp = get_next_line(fd);
	// write (1, imp, BUFFER_SIZE);
	// imp = get_next_line(fd);
	// write (1, imp, BUFFER_SIZE);
	// imp = get_next_line(fd);
	// write (1, imp, BUFFER_SIZE);
	close (fd);
}
// write (1, "\nhi im sheesh", 10);s
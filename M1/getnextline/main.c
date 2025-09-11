/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammad <mohammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 21:42:15 by mohammad          #+#    #+#             */
/*   Updated: 2025/09/09 11:26:27 by mohammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>



int	main()
{
	int fd = open("fkfile.txt", O_RDONLY);
	char	*imp;

	imp = malloc (BUFFER_SIZE + 1);
	if (!imp)
		return (0);
	printf("%ld", read (0, imp, BUFFER_SIZE));
	// imp = get_next_line(fd);
	// write (1, imp, 10);
	// imp = get_next_line(fd);
	// write (1, imp, 10);
	// imp = get_next_line(fd);
	// write (1, imp, 10);
}
// write (1, "\nhi im sheesh", 10);
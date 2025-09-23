/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:43:11 by melshata          #+#    #+#             */
/*   Updated: 2025/09/17 16:01:47 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("testfile.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

	
	printf("line = %s", get_next_line(fd));
	printf("line = %s", get_next_line(fd));
	printf("line = %s", get_next_line(fd));
	printf("line = %s", get_next_line(fd));
    // char *line;
	// line = get_next_line(fd);
	// printf("%s \n", line);
    // free(line);
	// line = get_next_line(fd);
	// printf("%s \n", line);
    // free(line);
	// line = get_next_line(fd);
	// printf("%s \n", line);
    // free(line);
	// line = get_next_line(fd);
	// printf("%s \n", line);
    // free(line);
    // while ((line = get_next_line(fd)) && line[0] != '\0')
    // {
    //     printf("%s", line);
    //     free(line);
    // }
    close(fd);
    return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3rd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:37:45 by melshata          #+#    #+#             */
/*   Updated: 2025/01/18 17:37:51 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char	*read_specific_line(const char* filename, int line_number)
{
	int		fd;
	int		i;
	int		current_line;
	int		bytes_read;
	int		line_index;
	int		found;
	char	*buffer;
	char	*line;

	buffer = malloc(1024);
	line = malloc(100);
	line_index = 0;
	found = 0;
	current_line = 1;
	fd = open(filename, O_RDONLY);
	if (buffer == NULL) 
	{
		close(fd);
		return NULL;
	}
	if (line == NULL) 
	{
		free(buffer);
		close(fd);
		return NULL;
	}
	while ((bytes_read = read(fd, buffer, 1024)) > 0)
	{
		i = 0;
		while (i < bytes_read) 
		{
			if (buffer[i] == '\n') 
			{
				if (current_line == line_number) 
				{
					line[line_index] = '\0'; // Null-terminate the line
					found = 1;
					break;
				}
				current_line++;
		        	line_index = 0; // Reset for the next line
			} 
			else 
			{
				if (current_line == line_number) 
				{
					if (line_index < 99) 
					{ // Ensure we don't overflow the line buffer
				                line[line_index++] = buffer[i];
					}
				}
			}
			i++;
		}
		if (found) break;
	}
	free(buffer);
	close(fd);
	if (!found)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

int main() {
    int line_number = 5; // Example: Read the 5th line
    char* line = read_specific_line("numbers.dict", line_number);
    if (line != NULL) {
        printf("Line %d: %s\n", line_number, line);
        free(line);
    } else {
        printf("Line %d not found.\n", line_number);
    }
    return 0;
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:32:03 by melshata          #+#    #+#             */
/*   Updated: 2025/09/20 18:07:26 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 14
#endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

ssize_t	ll(char *s);
char	*ft_strchr(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*extract_line(char *temp);
char	*update_leftover(char *temp);
void	subfun(int fd, char **left);
char	*get_next_line(int fd);

#endif
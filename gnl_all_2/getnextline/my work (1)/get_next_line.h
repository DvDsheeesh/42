/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammad <mohammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:32:15 by mohammad          #+#    #+#             */
/*   Updated: 2025/09/12 22:56:15 by mohammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

# include <unistd.h>
# include <stdlib.h>

char	*gnl_strchr(const char *s);
char	*gnl_substr(char const *s, unsigned int start, size_t len);
size_t	gnl_strcat(char *s1, int fd);
char	*get_next_line(int fd);

#endif
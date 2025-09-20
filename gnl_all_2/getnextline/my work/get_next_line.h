/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:32:15 by mohammad          #+#    #+#             */
/*   Updated: 2025/09/11 15:14:28 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

# include <unistd.h>
# include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*gnl_strlcat(char *s1, char *s2, size_t bs);
char	*get_next_line(int fd);

#endif
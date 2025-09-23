/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:32:03 by melshata          #+#    #+#             */
/*   Updated: 2025/09/17 16:06:33 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

// linked list structure
typedef struct s_list
{
	char			*c;
	ssize_t			cs;
	ssize_t			eof;
	struct s_list	*next;
}					t_list;

char	*schr(char *s, ssize_t t);
char	*sdup(char *s1, ssize_t cs);
ssize_t	ll(t_list *lst, int t);
t_list	*lstl(t_list *lst);
void	lstc(t_list **lst);
int		lstadd(t_list **lst, char *buff, ssize_t rs);
char	*subfun(t_list **lst, int fd);
void	fill_line(t_list **lst, char *ln);
void	remainder_save(t_list **lst);
char	*get_next_line(int fd);

#endif
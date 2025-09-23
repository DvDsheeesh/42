/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:31:55 by melshata          #+#    #+#             */
/*   Updated: 2025/09/17 16:42:57 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// lstadd_back_new
int	lstadd(t_list **lst, char *buff, ssize_t rs)
{
    t_list	*new;

    if (!lst)
        return (0);
    new = malloc(sizeof(t_list));
    if (!new)
        return (0);
    new->c = buff;
    new->cs = rs;
	if (rs == BUFFER_SIZE)
    	new->eof = 0;
	else
		new->eof = 1;
    new->next = NULL;
    if (!*lst)
        *lst = new;
    else
		lstl(*lst)->next = new;
    return (1);
}

t_list	*subfun(int fd)
{
	ssize_t	rs;
	char	*buff;

	buff = malloc (BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while(1)
	{
		rs = read(fd, buff, BUFFER_SIZE);
		// if(rs == -1)
		if(rs == 0)
			break;
		
	}
}

void	fill_line(t_list **lst, char *ln)
{
	t_list	*p;
	ssize_t	i;
	ssize_t	j;

	p = *lst;
	i = 0;
	while (p)
	{
		j = 0;
		while (j < p->cs)
		{
			ln[i++] = p->c[j];
			if (p->c[j++] == '\n')
			{
				ln[i] = '\0';
				break ;
			}
		}
		p = p->next;
	}
	ln[i] = '\0';
}

void	remainder_save(t_list **lst)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->cs = schr(lstl(*lst)->c, 1) - schr(lstl(*lst)->c, 0);
	new->c = sdup(schr(lstl(*lst)->c, 0) + 1, new->cs);
	new->eof = lstl(*lst)->eof;
	printf("%ld\n", new->eof);
	new->next = NULL;
	// printf("aaaaa %s aa ", schr(lstl(*lst)->c, 0));
	lstc(lst);
	if (new->cs != 0)
		*lst = new;
}

char	*get_next_line(int fd)
{
	char			*ln;
	t_list			*tp;
	static t_list	*lst;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// buff = malloc (BUFFER_SIZE + 1);
	// if (!buff)
	// 	return (NULL);
	// if (!lst)
	// {
	// 	rs = read (fd, buff, BUFFER_SIZE);
	// 	buff[rs] = '\0';
	// 	if (!lstadd(&lst, buff, rs) || rs == -1)
	// 		return (NULL);
	// }
	tp = subfun(fd);
	ln = malloc (ll(lst, 1) + 1);
	if (!ln)
		return (NULL);
	ln[0] = '\0';
	fill_line(&lst, ln);
	remainder_save(&lst);
	return (ln);
}
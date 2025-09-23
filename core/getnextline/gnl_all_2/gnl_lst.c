/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammad <mohammad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:59:59 by mohammad          #+#    #+#             */
/*   Updated: 2025/09/17 00:29:03 by mohammad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFFER_SIZE 8

// linked list structure
typedef struct s_list
{
	char			*c;// content
	ssize_t			cs;// content size
	struct s_list	*next;
}					t_list;

// // for testing
// #include <stdio.h>
// void	print_list(t_list *lst)
// {
// 	t_list	*aa;

// 	aa = lst;
// 	while (aa)
// 	{
// 		printf("%s", aa->c);
// 		aa = aa->next;
// 	}
// }

// void	*lstcpy(t_list *dst, t_list *src)
// {
// 	t_list	*p;
// 	t_list	*q;

// 	if (!src)
// 		return (NULL);
// 	p = src;
// 	q = dst;
// 	while (p)
// 	{
// 		q->c = p->c;
// 		q->cs = p->cs;
// 		p = p->next;
// 		if (p)
// 		{
// 			q->next = malloc(sizeof(t_list));
// 			if (!q->next)
// 				return (NULL);
// 			q = q->next;
// 		}
// 	}
// 	q->next = NULL;
// 	return (dst);
// }

// strchr
char	*schr(char *s, ssize_t t)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == '\n' && t == 0)
			return (s);
		s++;
	}
	if (t == 1)
		return (s);
	return (NULL);
}

// ll
ssize_t	ll(t_list *lst, int t)
{
	ssize_t	l;
	t_list	*p;

	l = 0;
	p = lst;
	while (p)
	{
		if (t)
		{
			l += p->cs;
			if (schr(p->c, 0))
				break ;
		}
		else
			l += p->cs;
		p = p->next;
	}
	return (l);
}

// lstlast
t_list	*lstl(t_list *lst)
{
	t_list	*p;

	if (!lst)
		return (NULL);
	p = lst;
	while (p->next != NULL)
		p = p->next;
	return (p);
}

// lstclear
void	lstc(t_list **lst)
{
	t_list	*p;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		p = (*lst)->next;
		free ((*lst)->c);
		free (*lst);
		*lst = p;
	}
	*lst = NULL;
}

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
    new->next = NULL;
    if (!*lst)
        *lst = new;
    else
		lstl(*lst)->next = new;
    return (1);
}
// {
// 	t_list	*aa;

// 	if (!lst)
// 		return (0);
// 	if (!lst[0])
// 	{
// 		aa = malloc(sizeof(t_list));
// 		if (!aa)
// 			return (0);
// 		lst[0] = aa;
// 	}
// 	else 
// 	{
// 		aa = lstl(lst[0]);
// 		aa->next = malloc(sizeof(t_list));
// 		if (!aa->next)
// 			return (0);
// 	}
// 	aa->next->c = buff;
// 	aa->next->next = NULL;
// 	aa->next->cs = rs;
// 	return (1);
// }

void	subfun(t_list **lst, int fd)
{
	ssize_t	rs;
	char	*buff;

	while (lstl(*lst)->cs == BUFFER_SIZE && !schr(lstl(*lst)->c, 0))
	{
		buff = malloc (BUFFER_SIZE + 1);
		if (!buff)
			return ;
		rs = read (fd, buff, BUFFER_SIZE);
		if (rs == -1)
		{
			lstc(lst);
			free (buff);
			return ;
		}
		buff[rs] = '\0';
		if (!lstadd(lst, buff, rs))
		{
			free (buff);
			return ;
		}
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
    new->c = schr(lstl(*lst)->c, 0);
    new->cs = schr(lstl(*lst)->c, 1) - schr(lstl(*lst)->c, 0);
    new->next = NULL;
	lstc(lst);
	if (new->cs != 0)
		*lst = new;
}

char	*get_next_line(int fd)
{
	char			*buff;
	char			*ln;
	ssize_t			rs;
	static t_list	*lst;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc (BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	if (!lst)
	{
		rs = read (fd, buff, BUFFER_SIZE);
		buff[rs] = '\0';
		if (!lstadd(&lst, buff, rs) || rs == -1)
			return (NULL);
	}
	subfun(&lst, fd);
	ln = malloc (ll(lst, 1) + 1);
	if (!ln)
		return (NULL);
	ln[0] = '\0';
	fill_line(&lst, ln);
	return (ln);
}

int main(void)
{
    int fd = open("testfile.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    char *line;
	line = get_next_line(fd);
	printf("%s \n", line);
	line = get_next_line(fd);
	printf("%s \n", line);
	line = get_next_line(fd);
	printf("%s \n", line);
    // while ((line = get_next_line(fd)) && line[0] != '\0')
    // {
    //     printf("%s", line);
    //     free(line);
    // }
    free(line);
    close(fd);
    return 0;
}

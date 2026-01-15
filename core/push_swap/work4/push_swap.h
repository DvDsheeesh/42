/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 10:52:54 by melshata          #+#    #+#             */
/*   Updated: 2026/01/15 16:37:24 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include "ft_printf.h"

typedef struct s_list
{
	long			data;
	long			sorted_index;
	struct s_list	*next;
}					t_list;

typedef struct s_pack
{
	struct s_list	*a;
	struct s_list	*b;
}					t_pack;

void	print_list(t_list *lst);   //////////////////////////////////

void	push_move(t_pack *pack, char type);
void	swap_move(t_pack *pack, char type);
void	rotate_move(t_pack *pack, char type);
void	reverse_rotate_move(t_pack *pack, char type);

t_list	*list_last(t_list *lst);
void	free_list(t_list *p);
void	ps_exit(t_pack *pack, const char *msg, int exit_code);
void	append_list(t_pack *pack, t_list **lst, long data);
void	give_sorted_index (t_list *lst);
long	ft_atol(const char *nptr, t_pack *pack);
int		a_is_sorted(t_list *a);
void	input_list(t_pack *pack, int ac, char **av);

#endif
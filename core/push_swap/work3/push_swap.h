/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 10:52:54 by melshata          #+#    #+#             */
/*   Updated: 2026/01/14 21:14:57 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// # include "libft.h"
# include "ft_printf.h"

typedef struct s_pack
{
	struct s_list	*a;
	struct s_list	*b;
}					t_pack;

typedef struct s_list
{
	void			*content;
	long			address;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

#endif
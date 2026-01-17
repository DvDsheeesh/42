#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
typedef struct s_list
{
	long			data;
	long			sorted_index;
	long			reverse_index;
	long			complex;
	struct s_list	*next;
}					t_list;
typedef struct s_pack
{
	struct s_list	*a;
	struct s_list	*b;
}					t_pack;
int	list_len(t_list *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}
t_list	*list_last(t_list *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}
void	free_list(t_list *p)
{
	if (p && p->next)
		free_list (p->next);
	free (p);
}
long	ft_atol(const char *nptr, t_pack *pack)
{
	int		i;
	long	neg;
	long	num;

	i = 0;
	neg = 1;
	num = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			neg = -neg;
	if (nptr[i] == '\0')
		ps_exit (pack, "Error\nwrong input format\n", 1);
	while (nptr[i] >= '0' && nptr[i] <= '9')
		num = num * 10 + (nptr[i++] - '0');
	if (nptr[i])
		ps_exit (pack, "Error\nwrong input format\n", 1);
	return (num * neg);
}

int	list_is_sorted(t_list *a)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->sorted_index != i)
			return (0);
		a = a->next;
		i++;
	}
	return (1);
}

void	push_move(t_pack *pack, char type)
{
	t_list	*tmp;

	{
		tmp = pack->b;
		pack->b = pack->b->next;
		tmp->next = pack->a;
		pack->a = tmp;
	}
	{
		tmp = pack->a;
		pack->a = pack->a->next;
		tmp->next = pack->b;
		pack->b = tmp;
	}
}

void	swap_move(t_pack *pack, char type)
{
	t_list	*tmp;

	{
		tmp = pack->a->next;
		pack->a->next = tmp->next;
		tmp->next = pack->a;
		pack->a = tmp;
	}
	{
		tmp = pack->b->next;
		pack->b->next = tmp->next;
		tmp->next = pack->b;
		pack->b = tmp;
	}
	ft_printf ("s%c\n", type);
}

void	rotate_move(t_pack *pack, char type)
{
	t_list	*tmp;

	{
		tmp = pack->a;
		pack->a = pack->a->next;
		list_last(pack->a)->next = tmp;
		tmp->next = NULL;
	}
	{
		tmp = pack->b;
		pack->b = pack->b->next;
		list_last(pack->b)->next = tmp;
		tmp->next = NULL;
	}
}

void	reverse_rotate_move(t_pack *pack, char type)
{
	t_list	*tmp;
	t_list	*p;

	{
		tmp = list_last(pack->a);
		p = pack->a;
		while (p->next != tmp)
			p = p->next;
		p->next = NULL;
		tmp->next = pack->a;
		pack->a = tmp;
	}
	{
		tmp = list_last(pack->b);
		p = pack->b;
		while (p->next != tmp)
			p = p->next;
		p->next = NULL;
		tmp->next = pack->b;
		pack->b = tmp;
	}
}

static void	append_list(t_pack *pack, t_list **lst, long data)
{
	t_list	*aa;
	t_list	*p;

	aa = malloc(sizeof(t_list));
	if (!aa)
		ps_exit(pack, "Error\nnew node malloc failed\n", 1);
	aa->data = data;
	aa->sorted_index = 0;
	aa->complex = 0;
	aa->next = NULL;
	if (!(*lst))
		*lst = aa;
	else
	{
		p = *lst;
		while (p->next != NULL)
			p = p->next;
		p->next = aa;
	}
}

void	give_sorted_index(t_list *lst)
{
	int	i;
	t_list	*p1;
	t_list	*p2;

	p1 = lst;
	while (p1)
	{
		p1->sorted_index = 0;
        p1->reverse_index = 0;
		p2 = lst;
		while (p2)
		{
			if (p1->data > p2->data)
				p1->sorted_index++;
			if (p1->data < p2->data)
				p1->reverse_index++;
			p2 = p2->next;
		}
		p1 = p1->next;
	}
}

void	input_list(t_pack *pack, int ac, char **av)
{
	int		i;
	t_list	*head;

	i = 1;
	pack->a = NULL;
	pack->b = NULL;
	while (i < ac)
	{
		append_list(pack, &(pack->a), ft_atol(av[i], pack));
		i++;
	}
	give_sorted_index (pack->a);
}

void	ps_exit(t_pack *pack, const char *msg, int exit_code)
{
	free_list (pack->a);
	free_list (pack->b);
	exit(exit_code);
}

int	new_i(int i, int len)
{
	if ((float)i >= (float)len / 2)
	{
		len = 0;
		i--;
	}
	else
	{
		i++;
		if ((float)i > (float)len / 2)
		{
			len = 0;
			i--;
		}
	}
	return (i);
}

void	give_complex(t_list *lst, int type)
{
	int	i;
	int	len;

	i = 0;
	len = list_len (lst);
	while (lst)
	{
			lst->complex = i + (lst->sorted_index);
			lst->complex = i + (lst->reverse_index);
		lst = lst->next;
		i = new_i (i, len);
	}
}

int	is_peak(t_list *lst, t_list *node, int type)
{
	t_list	*p;
	p = lst;
	{
		while (p)
		{
			if (node->sorted_index < p->sorted_index)
				return (0);
			p = p->next;
		}
	}
	{
		while (p)
		{
			if (node->sorted_index > p->sorted_index)
				return (0);
			p = p->next;
		}
	}
	return (1);
}

void	sort_3(t_pack *pack, int type)
{
	{
		if (is_peak(pack->a, pack->a, 1))
			rotate_move(pack, 'a');
		else if (is_peak(pack->a, pack->a->next, 1))
			reverse_rotate_move(pack, 'a');
		if (pack->a->sorted_index > pack->a->next->sorted_index)
			swap_move(pack, 'a');
	}
	{
		if (is_peak(pack->b, pack->b, 0))
			rotate_move(pack, 'b');
		else if (is_peak(pack->b, pack->b->next, 0))
			reverse_rotate_move(pack, 'b');
		if (pack->b->sorted_index < pack->b->next->sorted_index)
			swap_move(pack, 'b');
	}
}

void	sort_2(t_pack *pack, int type)
{
	if (type == 0)
			swap_move(pack, 'a');
		if (pack->b->sorted_index < pack->b->next->sorted_index)
			swap_move(pack, 'b');
}

void	get_least_complex_to_top(t_pack *pack, int type)
{
	t_list	*lst;
	t_list	*least;
	int		least_pos;
	int		pos;
	int		len;

	lst = (type == 0) ? pack->a : pack->b;
	least = lst;
	least_pos = 0;
	pos = 0;
	len = list_len (lst);
	while (lst)
	{
		if (lst->complex < least->complex
			|| (lst->complex == least->complex
				&& (lst->sorted_index < least->sorted_index && type == 0
					|| lst->sorted_index > least->sorted_index && type == 1)))
		{
			least = lst;
			least_pos = pos;
		}
		lst = lst->next;
		pos++;
	}
	if ((float)least_pos <= (float)len / 2)
	{
		while (least_pos-- > 0)
			rotate_move (pack, (type == 0) ? 'a' : 'b');
	}
	else
	{
		while (least_pos++ < len)
			reverse_rotate_move (pack, (type == 0) ? 'a' : 'b');
	}
}

void	sort_all(t_pack *pack)
{
	while (!list_is_sorted(pack->a))
	{
		while (list_len (pack->a) > 3)
		{
			give_sorted_index (pack->a);
			give_complex (pack->a, 0);
			get_least_complex_to_top (pack, 0);
			push_move (pack, 'b');
		}
		sort_3 (pack, 0);
		while (pack->b)
		{
			give_sorted_index (pack->b);
			give_complex (pack->b, 1);
			get_least_complex_to_top (pack, 1);
			push_move (pack, 'a');
		}
		give_sorted_index (pack->a);
	}
}

int	main(int ac, char **av)
{
	t_pack	pack;

	if (ac < 2)
		return (0);
	
	input_list(&pack, ac, av);
	give_complex (pack.a, 0);
	sort_all (&pack);
	ps_exit (&pack, "Done", 0);
	return (0);
}

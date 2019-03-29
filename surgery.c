#include "push_swap.h"

void	swap(t_list_nb *list)
{
	int		tmp;

	tmp = list->nb;
	list->nb = list->next->nb;
	list->next->nb = tmp;
}

void	ss(t_list_nb *list_a, t_list_nb *list_b)
{
	swap(list_a);
	swap(list_b);
}

void	push(t_list_nb **list_1, t_list_nb **list_2)
{
	t_list_nb	*tmp;

	tmp = *list_2;
	if (!*list_1)
		*list_1 = tmp;	
	if (*list_2 != (*list_2)->next)
	{
		(*list_2)->next->prev = (*list_2)->prev;
		(*list_2)->prev->next = (*list_2)->next;
		*list_2 = (*list_2)->next;
	}
	else
		*list_2 = NULL;
	if (*list_1)
		*list_1 = tmp;
	if (tmp)
	{
		tmp->next = (*list_1);
		tmp->prev = (*list_1)->prev;
		(*list_1)->prev = tmp;
	}
}

void	rotate(t_list_nb **list)
{
	*list = (*list)->prev;
}

void	rr(t_list_nb **list_1, t_list_nb **list_2)
{
	rotate(list_1);
	rotate(list_2);
}

void	reverse_rotate(t_list_nb **list)
{
	*list = (*list)->next;
}

void	rrr(t_list_nb **list_1, t_list_nb **list_2)
{
	reverse_rotate(list_1);
	reverse_rotate(list_2);
}

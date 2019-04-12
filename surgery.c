#include "push_swap.h"

// void	new_surgery(t_stack *stack, char *str)
// {
// 	t_surgery	*new;

// 	if (!(new = ft_memalloc(sizeof(t_surgery))))
// 		put_error();
// 	if (!(new->str = ft_strdup(str)))
// 		put_error();
// 	if (!stack->surgery)
// 	{	
// 		new->prev = new;
// 		new->next = new;
// 		stack->surgery = new;
// 	}
// 	else
// 	{
// 		new->prev = stack->surgery->prev;
// 		new->next = stack->surgery;
// 		stack->surgery->prev->next = new;
// 		stack->surgery->prev = new;
// 	}
// }

// void	check_surgery(t_surgery *surgery, int size)
// {

// }

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

void	push(t_list_nb **dst, t_list_nb **src, int *size_src, int *size_dst)
{
	t_list_nb	*tmp;
	t_list_nb	*tmp2;

	tmp = *src;
	tmp2 = *dst;
	if (!*src)
		return ;
	if ((*src)->next == *src)
		*src = NULL;
	else
	{
		(*src)->next->prev = (*src)->prev;
		(*src)->prev->next = (*src)->next;
		*src = (*src)->next;
	}
	*dst = tmp;
	if (tmp2)
	{
		tmp->next = tmp2;
		tmp->prev = tmp2->prev;
		tmp2->prev->next = tmp;
		tmp2->prev = tmp;
	}
	else
	{
		tmp->prev = tmp;
		tmp->next = tmp;
	}
	(*size_src)--;
	(*size_dst)++;
}

void	rotate(t_list_nb **list)
{
	if (!*list)
		return ;
	*list = (*list)->next;
}

void	rr(t_list_nb **list_1, t_list_nb **list_2)
{
	rotate(list_1);
	rotate(list_2);
}

void	reverse_rotate(t_list_nb **list)
{
	if (!*list)
		return ;
	*list = (*list)->prev;
}

void	rrr(t_list_nb **list_1, t_list_nb **list_2)
{
	reverse_rotate(list_1);
	reverse_rotate(list_2);
}

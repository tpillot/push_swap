#include "push_swap.h"

static	void	set_push(t_list_nb **src)
{
	if ((*src)->next == *src)
		*src = NULL;
	else
	{
		(*src)->next->prev = (*src)->prev;
		(*src)->prev->next = (*src)->next;
		*src = (*src)->next;
	}
}

void			push_b(t_stack *stack)
{
	t_list_nb	*tmp;
	t_list_nb	*tmp2;

	tmp = stack->list_a;
	tmp2 = stack->list_b;
	if (!tmp)
		return ;
	set_push(&stack->list_a);
	stack->list_b = tmp;
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
	stack->size_a--;
	stack->size_b++;
	new_surgery(&stack->surgery, "pb");
	stack->pb++;
}

void			push_a(t_stack *stack)
{
	t_list_nb	*tmp;
	t_list_nb	*tmp2;

	tmp = stack->list_b;
	tmp2 = stack->list_a;
	if (!tmp)
		return ;
	set_push(&stack->list_b);
	stack->list_a = tmp;
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
	stack->size_b--;
	stack->size_a++;
	new_surgery(&stack->surgery, "pa");
	stack->pa++;
}

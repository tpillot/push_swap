#include "push_swap.h"

static	int			put_a_to_b(t_stack *stack, int size)
{
	int			med;
	t_list_nb	*tmp;
	t_list_nb	*tmp2;
	int			sent;

	tmp = stack->list_a;
	sent = 0;
	med = get_median(stack->list_a, size, stack);
	if (size == 2)
	{
		swap(stack, 'a');
		return (0);
	}
	else if (size == 3)
		return (size_3(stack));
	while ((tmp2 = there_is_lower(stack->list_a, med, size--)))
	{
		best_way(stack, tmp2, 'a');
		if (stack->list_a == tmp)
			tmp = stack->list_a->next;
		push_b(stack);
		sent++;
	}
	best_way(stack, tmp, 'a');
	return (sent);
}

static	int			put_b_to_a(t_stack *stack, int size)
{
	int			med;
	t_list_nb	*tmp;
	t_list_nb	*tmp2;
	int			sent;

	sent = 0;
	tmp = stack->list_b;
	med = get_median(stack->list_b, size, stack);
	if (size == 1)
	{
		push_a(stack);
		return (1);
	}
	else if (size == 2)
		return (size_2(stack));
	while ((tmp2 = there_is_uper(stack->list_b, med, size--)))
	{
		best_way(stack, tmp2, 'b');
		if (stack->list_b == tmp)
			tmp = stack->list_b->next;
		push_a(stack);
		sent++;
	}
	best_way(stack, tmp, 'b');
	return (sent);
}

static	void		quick_sort_b(t_stack *stack, int size)
{
	int			sent;

	if (size <= 0)
		return ;
	if (stack->size_b <= 40)
	{
		while (stack->list_b)
		{
			best_way(stack, biggest(stack->list_b), 'b');
			push_a(stack);
		}
		return ;
	}
	sent = put_b_to_a(stack, size);
	quick_sort_a(stack, sent);
	quick_sort_b(stack, size - sent);
}

void				quick_sort_a(t_stack *stack, int size)
{
	int			sent;

	if (size <= 1 || is_sort(stack->list_a, size))
		return ;
	sent = put_a_to_b(stack, size);
	quick_sort_a(stack, size - sent);
	quick_sort_b(stack, sent);
}

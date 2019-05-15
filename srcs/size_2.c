#include "push_swap.h"

int		size_2(t_stack	*stack)
{
	if (stack->list_b->nb < stack->list_b->next->nb)
	{
		swap(stack, 'b');
		push_a(stack);
		push_a(stack);
	}
	else
	{
		push_a(stack);
		push_a(stack);
	}
	return (2);
}
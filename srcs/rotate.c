#include "push_swap.h"

void	rotate(t_stack *stack, char c)
{
	if (c == 'a')
	{
		if (!stack->list_a)
			return ;
		stack->list_a = stack->list_a->next;
		new_surgery(&stack->surgery, "ra");
		stack->ra++;
	}
	else
	{
		if (!stack->list_b)
			return ;
		stack->list_b = stack->list_b->next;
		new_surgery(&stack->surgery, "rb");
		stack->rb++;
	}
}

void	rr(t_stack *stack)
{
	rotate(stack, 'a');
	rotate(stack, 'b');
	new_surgery(&stack->surgery, "rr");
	stack->rr++;
}

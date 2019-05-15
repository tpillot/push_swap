#include "push_swap.h"

void	reverse_rotate(t_stack *stack, char c)
{
	if (c == 'a')
	{
		if (!stack->list_a)
			return ;
		stack->list_a = stack->list_a->prev;
		new_surgery(&stack->surgery, "rra");
		stack->rra++;
	}
	else
	{
		if (!stack->list_b)
			return ;
		stack->list_b = stack->list_b->prev;
		new_surgery(&stack->surgery, "rrb");
		stack->rrb++;
	}
}

void	rrr(t_stack *stack)
{
	reverse_rotate(stack, 'a');
	reverse_rotate(stack, 'b');
	new_surgery(&stack->surgery, "rrr");
	stack->rrr++;
}

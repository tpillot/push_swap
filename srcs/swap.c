#include "push_swap.h"

void	swap(t_stack *stack, char c)
{
	int		tmp;

	if (c == 'a' && stack->list_a && stack->list_a->next != stack->list_a)
	{
		tmp = stack->list_a->nb;
		stack->list_a->nb = stack->list_a->next->nb;
		stack->list_a->next->nb = tmp;
		new_surgery(&stack->surgery, "sa");
		stack->sa++;
	}
	else if (stack->list_b && stack->list_b->next != stack->list_b)
	{
		tmp = stack->list_b->nb;
		stack->list_b->nb = stack->list_b->next->nb;
		stack->list_b->next->nb = tmp;
		new_surgery(&stack->surgery, "sb");
		stack->sb++;
	}
}

void	ss(t_stack *stack)
{
	swap(stack, 'a');
	swap(stack, 'b');
	new_surgery(&stack->surgery, "ss");
	stack->ss++;
}

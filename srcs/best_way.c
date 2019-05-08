#include "push_swap.h"

static void	list_go_to(t_stack *stack, t_list_nb *target, int i, char c)
{
	if (c == 'a')
	{
		while (stack->list_a != target)
		{
			(i < 0 ? rotate(&(stack->list_a)) : reverse_rotate(&(stack->list_a)));
			(i < 0 ? new_surgery(&stack->surgery, "ra") : new_surgery(&stack->surgery, "rra"));
		}
	}
	else
	{
		while (stack->list_b != target)
		{
			(i < 0 ? rotate(&(stack->list_b)) : reverse_rotate(&(stack->list_b)));
			(i < 0 ? new_surgery(&stack->surgery, "rb") : new_surgery(&stack->surgery, "rrb"));
		}
	}
}

void	best_way(t_stack *stack, t_list_nb *target, char c)
{
	t_list_nb	*tmp;
	t_list_nb	*list;
	int		i;

	list = c == 'a' ? stack->list_a : stack->list_b;
	tmp = list;
	i = 0;
	while (list != target)
	{
		list = list->next;
		i++;
	}
	while(list != tmp)
	{
		list = list->next;
		i--;
	}
	list_go_to(stack, target, i, c);
}

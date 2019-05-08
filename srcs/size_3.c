#include "push_swap.h"

void	size_3(t_stack	*stack)
{
	t_list_nb		*tmp;

	tmp = stack->list_a;
	if (tmp->nb < tmp->next->nb && tmp->nb < tmp->next->next->nb)
	{
		if (stack->size_a == 3)
		{
			reverse_rotate(&(stack->list_a));
			new_surgery(&stack->surgery, "rra");
			swap(stack->list_a);
			new_surgery(&stack->surgery, "sa");
		}
		else
		{
			rotate(&(stack->list_a));
			new_surgery(&stack->surgery, "ra");
			swap(stack->list_a);
			new_surgery(&stack->surgery, "sa");
			reverse_rotate(&(stack->list_a));
			new_surgery(&stack->surgery, "rra");
	}
	}
	else if (tmp->nb > tmp->next->nb && tmp->nb < tmp->next->next->nb)
	{
		swap(stack->list_a);
		new_surgery(&stack->surgery, "sa");
	}
	else if (tmp->nb < tmp->next->nb && tmp->nb > tmp->next->next->nb)
	{
		if (stack->size_a == 3)
		{
			reverse_rotate(&(stack->list_a));
			new_surgery(&stack->surgery, "rra");
		}
		else
		{
			rotate(&(stack->list_a));
			new_surgery(&stack->surgery, "ra");
			swap(stack->list_a);
			new_surgery(&stack->surgery, "sa");
			reverse_rotate(&(stack->list_a));
			new_surgery(&stack->surgery, "rra");
			swap(stack->list_a);
			new_surgery(&stack->surgery, "sa");
		}
	}
	else if (tmp->nb > tmp->next->nb && tmp->next->nb < tmp->next->next->nb)
	{
		if (stack->size_a == 3)
		{
			rotate(&(stack->list_a));
			new_surgery(&stack->surgery, "ra");
		}
		else
		{
			swap(stack->list_a);
			new_surgery(&stack->surgery, "sa");
			rotate(&(stack->list_a));
			new_surgery(&stack->surgery, "ra");
			swap(stack->list_a);
			new_surgery(&stack->surgery, "sa");
			reverse_rotate(&(stack->list_a));
			new_surgery(&stack->surgery, "rra");
		}
	}
	else
	{
		if (stack->size_a == 3)
		{
			swap(stack->list_a);
			new_surgery(&stack->surgery, "sa");
			reverse_rotate(&(stack->list_a));
			new_surgery(&stack->surgery, "rra");
		}
		else
		{
			swap(stack->list_a);
			new_surgery(&stack->surgery, "sa");
			rotate(&(stack->list_a));
			new_surgery(&stack->surgery, "ra");
			swap(stack->list_a);
			new_surgery(&stack->surgery, "sa");
			reverse_rotate(&(stack->list_a));
			new_surgery(&stack->surgery, "rra");
			swap(stack->list_a);
			new_surgery(&stack->surgery, "sa");
		}
	}
}
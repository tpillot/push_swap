#include "push_swap.h"

static	void	case_1(t_stack *stack)
{
	if (stack->size_a == 3)
	{
		reverse_rotate(stack, 'a');
		swap(stack, 'a');
	}
	else
	{
		rotate(stack, 'a');
		swap(stack, 'a');
		reverse_rotate(stack, 'a');
	}
}

static	void	case_2(t_stack *stack)
{
	if (stack->size_a == 3)
		reverse_rotate(stack, 'a');
	else
	{
		rotate(stack, 'a');
		swap(stack, 'a');
		reverse_rotate(stack, 'a');
		swap(stack, 'a');
	}
}

static	void	case_3(t_stack *stack)
{
	if (stack->size_a == 3)
		rotate(stack, 'a');
	else
	{
		swap(stack, 'a');
		rotate(stack, 'a');
		swap(stack, 'a');
		reverse_rotate(stack, 'a');
	}
}

static	void	case_4(t_stack *stack)
{
	if (stack->size_a == 3)
	{
		swap(stack, 'a');
		reverse_rotate(stack, 'a');
	}
	else
	{
		swap(stack, 'a');
		rotate(stack, 'a');
		swap(stack, 'a');
		reverse_rotate(stack, 'a');
		swap(stack, 'a');
	}
}

int				size_3(t_stack *stack)
{
	t_list_nb		*tmp;

	tmp = stack->list_a;
	if (tmp->nb < tmp->next->nb && tmp->nb < tmp->next->next->nb)
		case_1(stack);
	else if (tmp->nb > tmp->next->nb && tmp->nb < tmp->next->next->nb)
		swap(stack, 'a');
	else if (tmp->nb < tmp->next->nb && tmp->nb > tmp->next->next->nb)
		case_2(stack);
	else if (tmp->nb > tmp->next->nb && tmp->next->nb < tmp->next->next->nb)
		case_3(stack);
	else
		case_4(stack);
	return (0);
}

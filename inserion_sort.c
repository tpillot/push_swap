#include "push_swap.h"

int		best_way2(t_list_nb *list, int nb)
{
	t_list_nb	*tmp;
	int		i;

	tmp = list;
	i = 0;
	while (list->nb != nb)
	{
		list = list->next;
		i++;
	}
	while(list != tmp)
	{
		list = list->next;
		i--;
	}
	return(i);
}

int		biggest2(t_list_nb *list)
{
	int		biggest;
	t_list_nb	*tmp;

	tmp = list->next;
	biggest = list->nb;
	while (tmp != list)
	{
		if (tmp->nb > biggest)
			biggest = tmp->nb;
		tmp = tmp->next;
	}
	return (biggest);
}

int		smallest(t_list_nb *list)
{
	int		smallest;
	t_list_nb	*tmp;

	tmp = list->next;
	smallest = list->nb;
	while (tmp != list)
	{
		if (tmp->nb < smallest)
			smallest = tmp->nb;
		tmp = tmp->next;
	}
	return (smallest);
}

t_list_nb	*find_elem(t_list_nb *list, int size)
{
	int		i;

	i = 0;
	while (i < size - 1)
	{
		if (list->nb > list->next->nb){
			//printf("%d\n", list->next->nb);
			return (list->next);
		}
		list = list->next;
		i++;
	}
	return (NULL);
}

int		find_position(t_list_nb *list, int nb)
{
	while (42)
	{
		if (list->nb > nb)
			return (list->nb);
		list = list->next;
	}
}

void	insertion_sort(t_stack *stack, int size)
{
	t_list_nb	*tmp;
	t_list_nb	*begin = stack->list_a;
	int		i;
	int		pos;

	while((tmp = find_elem(begin, stack->size_a)))
	{
		i = best_way2(stack->list_a, tmp->nb);
		while (stack->list_a->nb != tmp->nb)
		{
			(i < 0 ? rotate(&(stack->list_a)) : reverse_rotate(&(stack->list_a)));
			(i < 0 ? new_surgery(&stack->surgery, "ra") : new_surgery(&stack->surgery, "rra"));
		}
		push(&(stack->list_b), &(stack->list_a), &(stack->size_a), &(stack->size_b));
		new_surgery(&stack->surgery, "pb");
	}
	print_list(stack->list_a, 0);
	i = best_way2(stack->list_a, begin->nb);
	while (stack->list_a->nb != begin->nb)
	{
		(i < 0 ? rotate(&(stack->list_a)) : reverse_rotate(&(stack->list_a)));
		(i < 0 ? new_surgery(&stack->surgery, "ra") : new_surgery(&stack->surgery, "rra"));
	}
	while (stack->list_b)
	{
		pos = find_position(begin, stack->list_b->nb);
		i = best_way2(stack->list_a, pos);
		while (stack->list_a->nb != pos)
		{
			(i < 0 ? rotate(&(stack->list_a)) : reverse_rotate(&(stack->list_a)));
			(i < 0 ? new_surgery(&stack->surgery, "ra") : new_surgery(&stack->surgery, "rra"));
		}
		push(&(stack->list_a), &(stack->list_b), &(stack->size_b), &(stack->size_a));
		new_surgery(&stack->surgery, "pa");
		if (pos == begin->nb)
			begin = stack->list_a;
	}
	i = best_way2(stack->list_a, smallest(stack->list_a));
	while (stack->list_a->nb != smallest(stack->list_a))
	{
		(i < 0 ? rotate(&(stack->list_a)) : reverse_rotate(&(stack->list_a)));
		(i < 0 ? new_surgery(&stack->surgery, "ra") : new_surgery(&stack->surgery, "rra"));
	}
}























#include "push_swap.h"

void	sort_tab(int *tab, int size)
{
	int 	i;
	int		j;
	int		tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int		get_median(t_list_nb *list, int size, t_stack *stack)
{
	int			i;

	if (!(stack->tab = ft_memalloc(sizeof(int) * size)))
		return (0);
	i = 0;
	while (i < size)
	{
		stack->tab[i] = list->nb;
		list = list->next;
		i++;
	}
	sort_tab(stack->tab, size);
	i = stack->tab[size / 2];
	free(stack->tab);
	return (i);
}

int		is_sort(t_list_nb *list , int size)
{
	int i;

	i = 0;
	while (i++ < size - 1)
	{
		if (list->nb > list->next->nb)
			return (0);
		list = list->next;
	}
	return (1);
}

int		biggest(t_list_nb *list)
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

void		quick_sort(t_stack	*stack, int size)
{
	int			i;
	int			size_2;
	int			sent = 0;
	int			med;

	if (is_sort(stack->list_a, size))
	 	return ;
	med = get_median(stack->list_a, size, stack);
	i = -1;
	while (++i < size && sent < size / 2 + size % 2)
	{
		if (stack->list_a->nb >= med)
		{
			push(&(stack->list_b), &(stack->list_a), &(stack->size_a), &(stack->size_b));
			new_surgery(&stack->surgery, "pb");
			sent++;
		}
		else
		{
			rotate(&(stack->list_a));
			new_surgery(&stack->surgery, "ra");
		}
	}
	size_2 = stack->size_b;
	i = best_way(stack->list_b, med);
	if (size_2 <= 48)
	{
		while (stack->list_b)
		{
			i = best_way(stack->list_b, biggest(stack->list_b));
			while (stack->list_b->nb != biggest(stack->list_b))
			{
				(i < 0 ? rotate(&(stack->list_b)) : reverse_rotate(&(stack->list_b)));
				(i < 0 ? new_surgery(&stack->surgery, "rb") : new_surgery(&stack->surgery, "rrb"));
			}
			push(&(stack->list_a), &(stack->list_b), &(stack->size_b), &(stack->size_a));
			new_surgery(&stack->surgery, "pa");
		}
	}
	else
	{
		while (stack->size_b != 1)
		{
			if (stack->list_b->nb == med)
			{
				rotate(&(stack->list_b));
				new_surgery(&stack->surgery, "rb");
			}
			push(&(stack->list_a), &(stack->list_b), &(stack->size_b), &(stack->size_a));
			new_surgery(&stack->surgery, "pa");
		}
	}
	push(&(stack->list_a), &(stack->list_b), &(stack->size_b), &(stack->size_a));
	new_surgery(&stack->surgery, "pa");
	rotate(&(stack->list_a));
	new_surgery(&stack->surgery, "ra");
	quick_sort(stack, size_2 - 1);
	i = -1;
	while (++i < size - size_2 + 1)
	{
		reverse_rotate(&(stack->list_a));
		new_surgery(&stack->surgery, "rra");
	}
	quick_sort(stack, size - size_2);
}






















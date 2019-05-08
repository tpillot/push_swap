#include "push_swap.h"

int		there_is_lower(t_list_nb *list, int med, int size)
{
	int		i;

	i = -1;
	while (++i < size)
	{
		if (list->nb <= med)
			return (1);
		list = list->next;
	}
	return (0);
}

t_list_nb	*there_is_lower2(t_list_nb *list, int med, int size)
{
	int		i;

	i = -1;
	while (++i < size)
	{
		if (list->nb <= med)
			return (list);
		list = list->next;
	}
	return (NULL);
}

int		there_is_uper(t_list_nb *list, int med, int size)
{
	int		i;

	i = -1;
	while (++i < size)
	{
		if (list->nb > med)
			return (1);
		list = list->next;
	}
	return (0);
}

t_list_nb	*there_is_uper2(t_list_nb *list, int med, int size)
{
	int		i;

	i = -1;
	while (++i < size)
	{
		if (list->nb > med)
			return (list);
		list = list->next;
	}
	return (NULL);
}

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
	i = stack->tab[size / 2 - 1];
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

int		sent_max_func(t_list_nb *list, int size, int med)
{
	int		i;
	int		sent_max;

	i = -1;
	sent_max = 0;
	while(++i < size)
	{
		if (list->nb <= med)
			sent_max++;
		list = list->next;
	}
	return (sent_max);
}

int		put_a_to_b(t_stack	*stack, int size)
{
	int			i;
	int			med;
	t_list_nb	*tmp;
	t_list_nb	*tmp2;
	int			sent;

	tmp = stack->list_a;
	sent = 0;
	med = get_median(stack->list_a, size, stack);
	i = -1;
	if (size == 2)
	{
		swap(stack->list_a);
		new_surgery(&stack->surgery, "sa");
		return (0);
	}
	else if (size == 3)
	{
		size_3(stack);
		return (0);
	}
	while (++i < size)
	{
	 	if (!(tmp2 = there_is_lower2(stack->list_a, med, size - i)))
	 		break ;
		// if (stack->list_a->nb <= med)
		// {
		// 	if (stack->list_a == tmp)
		// 		tmp = stack->list_a->next;
		// 	push(&(stack->list_b), &(stack->list_a), &(stack->size_a), &(stack->size_b));
		// 	new_surgery(&stack->surgery, "pb");
		// 	sent++;
		// }
		// else
		// {
		// 	rotate(&(stack->list_a));
		// 	new_surgery(&stack->surgery, "ra");
		// }
		best_way(stack, tmp2, 'a');
		if (stack->list_a == tmp)
				tmp = stack->list_a->next;
		push(&(stack->list_b), &(stack->list_a), &(stack->size_a), &(stack->size_b));
		new_surgery(&stack->surgery, "pb");
		sent++;
	}
	//printf("%s\n", "yo");
	best_way(stack, tmp, 'a');
	return (sent);
}

int		put_b_to_a(t_stack	*stack, int size)
{
	int			i;
	int			med;
	t_list_nb	*tmp;
	t_list_nb	*tmp2;
	int			sent;

	sent = 0;
	tmp = stack->list_b;
	med = get_median(stack->list_b, size, stack);
	i = -1;
	if (size == 1)
	{
		push(&(stack->list_a), &(stack->list_b), &(stack->size_b), &(stack->size_a));
		new_surgery(&stack->surgery, "pa");
		return (1);
	}
	else if (size == 2)
	{
		if (tmp->nb < tmp->next->nb)
		{
			swap(stack->list_b);
			new_surgery(&stack->surgery, "sb");
			push(&(stack->list_a), &(stack->list_b), &(stack->size_b), &(stack->size_a));
			new_surgery(&stack->surgery, "pa");
			push(&(stack->list_a), &(stack->list_b), &(stack->size_b), &(stack->size_a));
			new_surgery(&stack->surgery, "pa");
		}
		else
		{
			push(&(stack->list_a), &(stack->list_b), &(stack->size_b), &(stack->size_a));
			new_surgery(&stack->surgery, "pa");
			push(&(stack->list_a), &(stack->list_b), &(stack->size_b), &(stack->size_a));
			new_surgery(&stack->surgery, "pa");
		}
		return (2);
	}
	//printf("med : %d\n", med);
	while (++i < size)
	{
		if (!(tmp2 = there_is_uper2(stack->list_b, med, size - i)))
			break ;
		// if (stack->list_b->nb > med)
		// {
		// 	if (stack->list_b == tmp)
		// 		tmp = stack->list_b->next;
		// 	push(&(stack->list_a), &(stack->list_b), &(stack->size_b), &(stack->size_a));
		// 	new_surgery(&stack->surgery, "pa");
		// 	sent++;
		// }
		// else
		// {
		// 	rotate(&(stack->list_b));
		// 	new_surgery(&stack->surgery, "rb");

		// }
		best_way(stack, tmp2, 'b');
		if (stack->list_b == tmp)
				tmp = stack->list_b->next;
		push(&(stack->list_a), &(stack->list_b), &(stack->size_b), &(stack->size_a));
		new_surgery(&stack->surgery, "pa");
		sent++;
	}	
	best_way(stack, tmp, 'b');
	return (sent);
}

void		quick_sort_b(t_stack *stack, int size)
{
	int			sent;

	if (size <= 0)
		return ;
	if (stack->size_b <= 40)
	{
		while (stack->list_b)
		{
			best_way(stack, biggest(stack->list_b), 'b');
			push(&(stack->list_a), &(stack->list_b), &(stack->size_b), &(stack->size_a));
			new_surgery(&stack->surgery, "pa");
		}
		return ;
	}	
	sent = put_b_to_a(stack, size);
	quick_sort_a(stack, sent);
	quick_sort_b(stack, size - sent);
}

void		quick_sort_a(t_stack *stack, int size)
{
	int			sent;

	if (is_sort(stack->list_a, size))
	 	return ;
	sent = put_a_to_b(stack, size);
	quick_sort_a(stack, size - sent);
	quick_sort_b(stack, sent);
}









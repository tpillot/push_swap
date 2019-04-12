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

int 	there_is_lower(t_list_nb *list, int nb , int size)
{
	int			i;

	i = -1;
	while (++i < size)
	{
		if (list->nb <= nb)
			return (1);
		list = list->next;
	}
	return (0);
}

int		best_way(t_list_nb *list, int nb)
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

int		get_median(t_list_nb *list, int size)
{
	int			i;
	int			*tab;

	if (!(tab = ft_memalloc(sizeof(int) * size)))
		return (0);
	i = 0;
	while (i < size)
	{
		tab[i] = list->nb;
		list = list->next;
		i++;
	}
	sort_tab(tab, size);
	return (tab[size / 2]);
}

int		is_sort(t_list_nb *list , int size)
{
	while (size--)
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

int		smaller(t_list_nb *list, int size)
{
	int		smaller;
	int		i;
	t_list_nb	*tmp;

	tmp = list->next;
	smaller = list->nb;
	while (++i < size)
	{
		if (tmp->nb < smaller)
			smaller = tmp->nb;
		tmp = tmp->next;
	}
	return (smaller);
}

void		quick_sort(t_stack	*stack, int size)
{
	t_list_nb	*tmp;
	int			i;
	int			size_2;
	int			med;
	int			way;

	if (is_sort(stack->list_a, size))
	 	return ;

	med = get_median(stack->list_a, size);

	i = -1;
	tmp = stack->list_a;

	if (size <= 100)
	{
		while (stack->list_b->nb < med)
		{
			way = best_way(stack->list_a, smaller(stack->list_b, size));
			while (stack->list_a->nb != smaller(stack->list_b, size))
			{
				(i < 0 ? rotate(&(stack->list_b)) : reverse_rotate(&(stack->list_b)));
				stack->total++;
			}
			push(&(stack->list_b), &(stack->list_a), &(stack->size_a), &(stack->size_b));
			stack->total++;
		}
		size_2 = stack->size_b;
		while (stack->list_b)
		{
			push(&(stack->list_a), &(stack->list_b), &(stack->size_b), &(stack->size_a));
			stack->total++;
		}
	}
	else
	{
		while (++i < size)
		{
			if (stack->list_a->nb <= med)
			{
				push(&(stack->list_b), &(stack->list_a), &(stack->size_a), &(stack->size_b));
				stack->total++;
				if (stack->list_b == tmp)
					tmp = stack->list_a;
			}
			else
			{
				if (there_is_lower(stack->list_a, med, size - i))
				{
					rotate(&(stack->list_a));
					stack->total++;
				}
				else
					break ;
			}

		}
		size_2 = stack->size_b;

		way = best_way(stack->list_a, tmp->nb);
		i = best_way(stack->list_b, med);

		while (stack->list_a->nb != tmp->nb)
		{
			(way < 0 ? rotate(&(stack->list_a)) : reverse_rotate(&(stack->list_a)));
			stack->total++;
		}
		// if (size_2 <= 48)
		// {
		// 	while (stack->list_b)
		// 	{
		// 		i = best_way(stack->list_b, biggest(stack->list_b));
		// 		while (stack->list_b->nb != biggest(stack->list_b))
		// 		{
		// 			(i < 0 ? rotate(&(stack->list_b)) : reverse_rotate(&(stack->list_b)));
		// 			stack->total++;
		// 		}
		// 		push(&(stack->list_a), &(stack->list_b), &(stack->size_b), &(stack->size_a));
		// 		stack->total++;
		// 	}
		// }
		// else
		// {
		while (stack->list_b->nb != med)
		{
			(i < 0 ? rotate(&(stack->list_b)) : reverse_rotate(&(stack->list_b)));
			stack->total++;
		}
		while (stack->list_b)
		{
			push(&(stack->list_a), &(stack->list_b), &(stack->size_b), &(stack->size_a));
			stack->total++;
		}
	}
	// }

	quick_sort(stack, size_2 - 1);

	way = best_way(stack->list_a, med);

	while (stack->list_a->nb != med)
	{
		(way < 0 ? rotate(&(stack->list_a)) : reverse_rotate(&(stack->list_a)));
		stack->total++;
	}
	rotate(&(stack->list_a));
	stack->total++;

	quick_sort(stack, size - size_2);
}























#include "push_swap.h"

static	void	sort_tab(int *tab, int size)
{
	int		i;
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

int				get_median(t_list_nb *list, int size, t_stack *stack)
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
	if (size == 1)
		i = stack->tab[0];
	else
		i = stack->tab[size / 2 - 1];
	ft_memdel((void**)(&stack->tab));
	return (i);
}

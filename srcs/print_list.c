#include "push_swap.h"

void print_list(t_list_nb *first, int way)
{
	t_list_nb *tmp;

	tmp = first;
	if (!first)
		return ;
	while (42)
	{
		ft_putnbr(tmp->nb);
		ft_putchar('\n');
		tmp = (way == 0 ? tmp->next : tmp->prev);
		if (tmp == first)
			break ;
	}
	ft_putchar('\n');
}

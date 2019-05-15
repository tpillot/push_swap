#include "push_swap.h"

void	print_list(t_list_nb *first, int way, char c)
{
	t_list_nb *tmp;

	tmp = first;
	if (c == 'a')
		ft_putstr("list_a :");
	else
		ft_putstr("list_b :");
	if (!first)
	{
		ft_putendl(" empty");
		return ;
	}
	while (42)
	{
		ft_putchar(' ');
		ft_putnbr(tmp->nb);
		tmp = (way == 0 ? tmp->next : tmp->prev);
		if (tmp == first)
			break ;
	}
	ft_putchar('\n');
}

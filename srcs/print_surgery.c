#include "push_swap.h"

void	print_surgery(t_stack stack)
{
	t_surgery	*tmp;
	int			i;

	tmp = stack.surgery;
	i = 0;
	while (tmp)
	{
		ft_putstr(tmp->str);
		ft_putchar('\n');
		i++;
		tmp = tmp->next;
	}
}

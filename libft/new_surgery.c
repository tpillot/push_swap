#include "push_swap.h"

void	new_surgery(t_stack *stack, char *str)
{
	t_surgery	*new;

	if (!(new = ft_memalloc(sizeof(t_surgery))))
		put_error();
	if (!(new->str = ft_strdup(str)))
		put_error();
	if (!stack->surgery)
	{	
		new->prev = new;
		new->next = new;
		stack->surgery = new;
	}
	else
	{
		new->prev = stack->surgery->prev;
		new->next = stack->surgery;
		stack->surgery->prev->next = new;
		stack->surgery->prev = new;
	}
}

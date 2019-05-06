#include "push_swap.h"

void	add_nb_to_list(t_stack *stack, char **str)
{
	t_list_nb	*new;

	if (!(new = ft_memalloc(sizeof(t_list_nb))))
			put_error();
	new->nb = ft_atoi(*str);
	if (!stack->list_a)
	{	
		new->prev = new;
		new->next = new;
		stack->list_a = new;
	}
	else
	{
		new->prev = stack->list_a->prev;
		new->next = stack->list_a;
		stack->list_a->prev->next = new;
		stack->list_a->prev = new;
	}
	stack->size_a++;
}

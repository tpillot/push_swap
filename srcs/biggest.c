#include "push_swap.h"

t_list_nb *biggest(t_list_nb *list)
{
	t_list_nb	*biggest;
	t_list_nb	*tmp;

	tmp = list->next;
	biggest = list;
	while (tmp != list)
	{
		if (tmp->nb > biggest->nb)
			biggest = tmp;
		tmp = tmp->next;
	}
	return (biggest);
}
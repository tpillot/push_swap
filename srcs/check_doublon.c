#include "push_swap.h"

void	check_doublon(t_list_nb *first)
{
	t_list_nb	*tmp;
	t_list_nb	*tmp2;

	tmp2 = first;
	while (1)
	{
		tmp = first->next;
		while (tmp != tmp2)
		{
			if (first->nb == tmp->nb)
				put_error(1);
			tmp = tmp->next;
		}
		first = first->next;
		if (first == tmp2)
			break ;
	}
}

#include "push_swap.h"

int		best_way(t_list_nb *list, int nb)
{
	t_list_nb	*tmp;
	int		i;

	tmp = list;
	i = 0;
	if (!list)
		return (0);
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

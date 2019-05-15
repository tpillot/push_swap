#include "push_swap.h"

int		is_sort(t_list_nb *list, int size)
{
	int i;

	i = 0;
	while (i++ < size - 1)
	{
		if (list->nb > list->next->nb)
			return (0);
		list = list->next;
	}
	return (1);
}

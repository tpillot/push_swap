#include "push_swap.h"

void	bubble_sort(t_list_nb *list)
{
	t_list_nb	*first;
	int			i;

	first = list;
	i = 0;
	while (42)
	{
		if (list->nb > list->next->nb)
		{
			swap(list);
			printf("sa\n");
			i++;
		}
		list = list->next;
		printf("ra\n");
		if (list->next == first)
		{
			if (i == 0)
				break ;
			i = 0;
			list = list->next;
			printf("ra\n");
		}
	}
}

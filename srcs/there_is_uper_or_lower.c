#include "push_swap.h"

t_list_nb	*there_is_lower(t_list_nb *list, int med, int size)
{
	int		i;

	i = -1;
	while (++i < size)
	{
		if (list->nb <= med)
			return (list);
		list = list->next;
	}
	return (NULL);
}

t_list_nb	*there_is_uper(t_list_nb *list, int med, int size)
{
	int		i;

	i = -1;
	while (++i < size)
	{
		if (list->nb > med)
			return (list);
		list = list->next;
	}
	return (NULL);
}

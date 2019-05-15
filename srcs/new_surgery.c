#include "push_swap.h"

static	int		check_surgery(char *str1, char *str2)
{
	if (!ft_strcmp(str1, "ra") && !ft_strcmp(str2, "rra"))
		return (1);
	if (!ft_strcmp(str1, "rra") && !ft_strcmp(str2, "ra"))
		return (1);
	if (!ft_strcmp(str1, "rb") && !ft_strcmp(str2, "rrb"))
		return (1);
	if (!ft_strcmp(str1, "rrb") && !ft_strcmp(str2, "rb"))
		return (1);
	if (!ft_strcmp(str1, "pa") && !ft_strcmp(str2, "pb"))
		return (1);
	if (!ft_strcmp(str1, "pb") && !ft_strcmp(str2, "pa"))
		return (1);
	return (0);
}

void			new_surgery(t_surgery **list, char *str)
{
	t_surgery	*new;
	t_surgery	*tmp;
	t_surgery	*tmp_prev;

	if (!(new = ft_memalloc(sizeof(t_surgery))))
		put_error(1);
	ft_strncpy(new->str, str, 3);
	if (!*list)
		*list = new;
	else
	{
		tmp = *list;
		while (tmp->next)
		{
			tmp_prev = tmp;
			tmp = tmp->next;
		}
		if (!check_surgery(tmp->str, str))
			tmp->next = new;
		else
		{
			tmp_prev->next = NULL;
			free(tmp);
		}
	}
}

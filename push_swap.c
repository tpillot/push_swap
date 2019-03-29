#include "push_swap.h"


void	put_error(void)
{
	write(2, "error\n", 6);
	exit(1);
}

void	check_doublon(t_list_nb *first)
{
	t_list_nb 	*tmp;

	while (!first->last)
	{
		tmp = first->next;
		while (!tmp->first)
		{
			if (first->nb == tmp->nb)
				put_error();
			tmp = tmp->next;
		}
		first = first->next;
	}
}

void	check_doublon2(t_list_nb *first)
{
	t_list_nb 	*tmp;
	t_list_nb 	*tmp2;

	tmp2 = first;
	while (1)
	{
		tmp = first->next;
		while (tmp != tmp2)
		{
			if (first->nb == tmp->nb)
				put_error();
			tmp = tmp->next;
		}
		first = first->next;
		if (first == tmp2)
			break;
	}
}

void	check_number(char *str)
{
	intmax_t	x;

	x = ft_atoi(str);
	if (x > 2147483647 || x < -2147483648)
		put_error();
	if (*str == '-')
		str++;
	while (*str <= '9' && *str >= '0')
		str++;
	if (*str != '\0' && *str != ' ')
		put_error();
	if (*(str++) == ' ' && *str > '9' && *str < '0' && *str != '\0')
		put_error();
}

void	go_to_next_digit(char **str)
{
	if (**str == '-')
		(*str)++;
	while (**str <= '9' && **str >= '0')
		(*str)++;
	if (**str == ' ')
		(*str)++;
}

void	add_nb_to_list(t_list_nb **first, char **str)
{
	t_list_nb	*new;
	t_list_nb	*tmp;

	if (!(new = ft_memalloc(sizeof(t_list_nb))))
			put_error();
	new->nb = ft_atoi(*str);
	if (!*first)
	{	
		new->prev = new;
		new->next = new;
		*first = new;
	}
	else
	{
		new->prev = (*first)->prev;
		new->next = *first;
		(*first)->prev->next = new;
		(*first)->prev = new;
	}
}

void print_list(t_list_nb *first, int way)
{
	t_list_nb *tmp;

	tmp = first;
	while (42)
	{
		printf("%d\n", tmp->nb);
		tmp = (way == 0 ? tmp->next : tmp->prev);
		if (tmp == first)
			break ;
	}
}

int		main(int ac, char **av)
{
	t_list_nb	*list_a;
	t_list_nb	*list_b;

	list_a = NULL;
	list_b = NULL;
	if (ac == 1)
		put_error();
	while (*(++av))
	{
		while(**av)
		{
			check_number(*av);
			add_nb_to_list(&list_a, av);
			go_to_next_digit(av);
		}
	}
	print_list(list_b, 1);
	printf("\n");
	return (0);
}



















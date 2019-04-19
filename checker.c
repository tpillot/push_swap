#include "push_swap.h"

void	put_error(void)
{
	write(2, "error\n", 6);
	exit(1);
}

static void print_list(t_list_nb *first, int way)
{
	t_list_nb *tmp;

	tmp = first;
	if (!first)
		return ;
	while (42)
	{
		ft_putnbr(tmp->nb);
		ft_putchar('\n');
		tmp = (way == 0 ? tmp->next : tmp->prev);
		if (tmp == first)
			break ;
	}
	ft_putchar('\n');
}

void	check_doublon(t_list_nb *first)
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


void print_list2(t_list_nb *first, int way)
{
	t_list_nb *tmp;

	tmp = first;
	if (!first)
		return ;
	while (42)
	{
		ft_putnbr(tmp->nb);
		ft_putchar('\n');
		tmp = (way == 0 ? tmp->next : tmp->prev);
		if (tmp == first)
			break ;
	}
	ft_putchar('\n');
}

void	check_surgery(char *str)
{
	if (ft_strcmp(str, "pa") && ft_strcmp(str, "pb") && ft_strcmp(str, "ra") && ft_strcmp(str, "rb") && ft_strcmp(str, "sa") && ft_strcmp(str, "ss") && ft_strcmp(str, "sb") && ft_strcmp(str, "rra") && ft_strcmp(str, "rrb") && ft_strcmp(str, "rr") && ft_strcmp(str, "rrr"))
		put_error();
}

void	exect_surgery(char *str, t_stack *stack)
{
	if (!ft_strcmp(str, "pa"))
		push(&(stack->list_a), &(stack->list_b), &(stack->size_b), &(stack->size_a));
	else if (!ft_strcmp(str, "pb"))
		push(&(stack->list_b), &(stack->list_a), &(stack->size_a), &(stack->size_b));
	else if (!ft_strcmp(str, "ra"))
		rotate(&(stack->list_a));
	else if (!ft_strcmp(str, "rb"))
		rotate(&(stack->list_b));
	else if (!ft_strcmp(str, "rr"))
		rr(&(stack->list_a), &(stack->list_b));
	else if (!ft_strcmp(str, "sa"))
		swap(stack->list_a);
	else if (!ft_strcmp(str, "sb"))
		swap(stack->list_b);
	else if (!ft_strcmp(str, "ss"))
		ss(stack->list_a, stack->list_b);
	else if (!ft_strcmp(str, "rra"))
		reverse_rotate(&(stack->list_a));
	else if (!ft_strcmp(str, "rrb"))
		reverse_rotate(&(stack->list_b));
	else if (!ft_strcmp(str, "rrr"))
		rrr(&(stack->list_a), &(stack->list_b));
}

int		is_sort(t_list_nb *list , int size)
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

int 	read_line(char str[4])
{
	char buf;
	int i;

	i = 0;
	while ((read(0, &buf, 1)))
	{
		if (i > 3)
			put_error();
		if (buf == '\n')
			return (1);
		str[i++] = buf;
	}
	if (i != 0)
		put_error();
	return (0);
}


int		main(int ac, char **av)
{
	t_stack		stack;
	int			i;
	char		buf;
	char		str[4];
	//int			ret;

	ft_bzero(&stack, sizeof(t_stack));
	ft_bzero(str, 4);
	if (ac == 1)
		put_error();
	while (*(++av))
	{
		while(**av)
		{
			check_number(*av);
			add_nb_to_list(&stack, av);
			go_to_next_digit(av);
		}
	}
	i = 0;
	//print_list2(stack.list_a, 0);
	while ((read_line(str)))
	{
		// str[++i] = buf;
		// if (buf == '\n')
		// {
		// 	check_surgery(str);
		// 	exect_surgery(str, &stack);
		// 	i = 0;
		// 	ft_bzero(str, 4);
		// }
		check_surgery(str);
		exect_surgery(str, &stack);
		ft_bzero(str, sizeof(char) * 4);
		i++;

	}

	print_list2(stack.list_a, 0);
	print_list2(stack.list_b, 0);
	//printf("%s\n", str);
	ft_putnbr(i);
	ft_putchar('\n');
	if (is_sort(stack.list_a, stack.size_a) && !stack.list_b)
		write(1, "OK\n", 3);
	else 
		write(1, "KO\n", 3);
}











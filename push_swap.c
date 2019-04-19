#include "push_swap.h"

void insertion_sort(t_stack	*stack, int size)
{
	while (stack->list_a)
		
}

void	put_error(void)
{
	write(2, "error\n", 6);
	exit(1);
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


void print_list(t_list_nb *first, int way)
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

int		main(int ac, char **av)
{
	t_stack		stack;

	ft_bzero(&stack, sizeof(t_stack));
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
	check_doublon(stack.list_a);
	//print_list(stack.list_a, 0);
	//printf("%d\n", stack.size_a);
	if (stack.size_a < 50)
		insertion_sort(&stack);
	else
		quick_sort(&stack, stack.size_a);
	//print_list(stack.list_a, 0);
	print_surgery(stack);
	return (0);
}

















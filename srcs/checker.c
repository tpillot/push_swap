#include "push_swap.h"

static	void	create_list(t_stack *stack, char **av)
{
	if (!av[0])
		put_error(1);
	while (*(av))
	{
		while (**av)
		{
			check_number(*av);
			add_nb_to_list(stack, av);
			go_to_next_digit(av);
		}
		av++;
	}
	check_doublon(stack->list_a);
}

static	int		register_option(char *str, t_stack *stack)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == 'v')
			stack->v = 1;
		else if (str[i] == 'c')
			stack->c = 1;
		else if (str[i] == 'n')
			stack->n = 1;
		else if (str[i] == 'd')
			stack->d = 1;
		else if (str[i] == 'a')
			stack->a = 1;
		else
			return (0);
	}
	return (1);
}

static	int		parsing_option(char **av, t_stack *stack)
{
	int		i;

	i = 1;
	while (av[i] && av[i][0] == '-')
	{
		if (!av[i][1] || ft_isdigit(av[i][1]))
			return (i);
		if (!(register_option(av[i] + 1, stack)))
			put_error(2);
		i++;
	}
	return (i);
}

int				main(int ac, char **av)
{
	t_stack		stack;
	char		str[4];
	int			fd;
	int			i;

	ft_bzero(&stack, sizeof(t_stack));
	ft_bzero(str, 4);
	fd = 0;
	(void)ac;
	i = parsing_option(av, &stack);
	av += i;
	if (stack.d)
	{
		if ((fd = open(av[0], O_RDONLY)) < 0)
			put_error(3);
		av++;
	}
	create_list(&stack, av);
	read_and_exect(str, &stack, fd);
	if (is_sort(stack.list_a, stack.size_a) && !stack.list_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

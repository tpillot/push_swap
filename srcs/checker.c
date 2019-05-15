#include "push_swap.h"

static	void	create_list(t_stack *stack, char **av)
{
	while (*(++av))
	{
		while (**av)
		{
			check_number(*av);
			add_nb_to_list(stack, av);
			go_to_next_digit(av);
		}
	}
}

static	int		parsing_option(char *str, t_stack *stack, int ac)
{
	int		i;

	i = -1;
	if (!str[0])
		put_error();
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
			return (1);
	}
	if (ac == 2)
		put_error();
	return (0);
}

int				main(int ac, char **av)
{
	t_stack		stack;
	char		str[4];
	int			fd;

	ft_bzero(&stack, sizeof(t_stack));
	ft_bzero(str, 4);
	fd = 0;
	if (ac == 1)
		put_error();
	if (av[1][0] == '-' && !parsing_option(av[1] + 1, &stack, ac))
		av++;
	if (stack.d)
	{
		if ((fd = open(av[1], O_RDONLY)) < 0)
			put_error();
		av++;
	}
	create_list(&stack, av);
	read_and_exect(str, &stack, fd);
	if (is_sort(stack.list_a, stack.size_a) && !stack.list_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

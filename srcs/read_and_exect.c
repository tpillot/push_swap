#include "push_swap.h"

static void	check_surgery(char *str)
{
	if (ft_strcmp(str, "pa") && ft_strcmp(str, "pb") &&
	ft_strcmp(str, "ra") && ft_strcmp(str, "rb") && ft_strcmp(str, "sa") &&
	ft_strcmp(str, "ss") && ft_strcmp(str, "sb") && ft_strcmp(str, "rra") &&
	ft_strcmp(str, "rrb") && ft_strcmp(str, "rr") && ft_strcmp(str, "rrr"))
		put_error(1);
}

void	exect_surgery(char *str, t_stack *stack)
{
	if (!ft_strcmp(str, "pa"))
		push_a(stack);
	else if (!ft_strcmp(str, "pb"))
		push_b(stack);
	else if (!ft_strcmp(str, "ra"))
		rotate(stack, 'a');
	else if (!ft_strcmp(str, "rb"))
		rotate(stack, 'b');
	else if (!ft_strcmp(str, "rr"))
		rr(stack);
	else if (!ft_strcmp(str, "sa"))
		swap(stack, 'a');
	else if (!ft_strcmp(str, "sb"))
		swap(stack, 'b');
	else if (!ft_strcmp(str, "ss"))
		ss(stack);
	else if (!ft_strcmp(str, "rra"))
		reverse_rotate(stack, 'a');
	else if (!ft_strcmp(str, "rrb"))
		reverse_rotate(stack, 'b');
	else if (!ft_strcmp(str, "rrr"))
		rrr(stack);
}

int 	read_line(char str[4], int fd)
{
	char buf;
	int i;

	i = 0;
	while ((read(fd, &buf, 1)))
	{
		if (i > 3)
			put_error(1);
		if (buf == '\n')
			return (1);
		str[i++] = buf;
	}
	if (i != 0)
		put_error(1);
	return (0);
}

void	read_and_exect(char *str, t_stack *stack, int fd)
{
	int		i;

	i = 0;
	while ((read_line(str, fd)))
	{
		check_surgery(str);
		exect_surgery(str, stack);
		if (stack->v == 1)
			exect_option(stack, str, i);
		ft_bzero(str, sizeof(char) * 4);
		i++;
	}
	exect_option(stack, NULL, i);	
}

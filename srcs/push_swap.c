#include "push_swap.h"

int		is_sort2(t_list_nb *list , int size)
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
	// if (stack.size_a < 50)
		//insertion_sort(&stack, stack.size_a);
	// else
	quick_sort_a(&stack, stack.size_a);
	//print_list(stack.list_a, 0);
	if (is_sort2(stack.list_a, stack.size_a))
		ft_putstr("ok\n");
	print_surgery(stack);
	return (0);
}

















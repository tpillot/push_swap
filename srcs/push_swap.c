#include "push_swap.h"

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
	print_surgery(stack);
	return (0);
}

















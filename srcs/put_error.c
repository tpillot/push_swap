#include "push_swap.h"

void	put_error(int code)
{
	if (code == 1)
		ft_putendl_fd("error", 2);
	if (code == 2)
		ft_putendl_fd("error -option", 2);
	if (code == 3)
		ft_putendl_fd("error -file", 2);
	exit(1);
}

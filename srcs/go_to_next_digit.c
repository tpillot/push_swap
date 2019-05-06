#include "push_swap.h"

void	go_to_next_digit(char **str)
{
	if (**str == '-')
		(*str)++;
	while (**str <= '9' && **str >= '0')
		(*str)++;
	if (**str == ' ')
		(*str)++;
}

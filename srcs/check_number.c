#include "push_swap.h"

void	check_number(char *str)
{
	intmax_t	x;

	x = ft_atoi(str);
	if (x > 2147483647 || x < -2147483648)
		put_error(1);
	if (*str == '-')
		str++;
	if (!*str)
		put_error(1);
	while (*str <= '9' && *str >= '0')
		str++;
	if (*str != '\0' && *str != ' ')
		put_error(1);
	if (*(str++) == ' ' && *str > '9' && *str < '0' && *str != '\0')
		put_error(1);
}

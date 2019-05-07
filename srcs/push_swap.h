#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

typedef struct		s_surgery
{
	char				str[4];
	struct s_surgery	*next;
	struct s_surgery	*prev;
}					t_surgery;

typedef struct		s_stack
{
	int					size_a;
	int					size_b;
	int					*tab;
	struct s_list_nb	*list_a;
	struct s_list_nb	*list_b;
	struct s_surgery	*surgery;
}					t_stack;

typedef struct		s_list_nb
{
	int					nb;
	struct s_list_nb	*next;
	struct s_list_nb	*prev;
}					t_list_nb;

void	put_error(void);
void	check_doublon(t_list_nb *first);
int		best_way(t_list_nb *list, int nb);
void	add_nb_to_list(t_stack *stack, char **str);
void	check_number(char *str);
void	go_to_next_digit(char **str);
void	quick_sort_a(t_stack *stack, int size);
void	swap(t_list_nb *list);
void	ss(t_list_nb *list_a, t_list_nb *list_b);
void	push(t_list_nb **dst, t_list_nb **src, int *size_src, int *size_dst);
void	rotate(t_list_nb **list);
void	rr(t_list_nb **list_1, t_list_nb **list_2);
void	reverse_rotate(t_list_nb **list);
void	rrr(t_list_nb **list_1, t_list_nb **list_2);
void	bubble_sort(t_list_nb *list);
void	quick_sort(t_stack	*stack, int size);
void	new_surgery(t_surgery **list, char *str);
void	print_surgery(t_stack stack);
void	insertion_sort(t_stack *stack, int size);
void	size_3(t_stack	*stack , int size);



#endif
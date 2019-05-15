#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include "libft.h"

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
	int					sa;
	int					sb;
	int					ss;
	int					ra;
	int					rb;
	int					rr;
	int					rra;
	int					rrb;
	int					rrr;
	int					pa;
	int					pb;
	char				c;
	char				v;
	char				n;
	char				d;
	char				a;
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

void					put_error(int code);
void					check_doublon(t_list_nb *first);
void					best_way(t_stack *stack, t_list_nb *target, char c);
void					add_nb_to_list(t_stack *stack, char **str);
void					check_number(char *str);
void					go_to_next_digit(char **str);
void					quick_sort_a(t_stack *stack, int size);
void					swap(t_stack *stack, char c);
void					ss(t_stack *stack);
void					push_a(t_stack *stack);
void					push_b(t_stack *stack);
void					rotate(t_stack *stack, char c);
void					rr(t_stack*stack);
void					reverse_rotate(t_stack *stack, char c);
void					rrr(t_stack *stack);
void					bubble_sort(t_list_nb *list);
void					quick_sort(t_stack	*stack, int size);
void					new_surgery(t_surgery **list, char *str);
void					print_surgery(t_stack stack);
void					insertion_sort(t_stack *stack, int size);
void 					print_list(t_list_nb *first, int way, char c);
void					exect_option(t_stack *stack, char *str, int i);
void					read_and_exect(char *str, t_stack *stack, int fd);
int						size_3(t_stack	*stack);
int						size_2(t_stack	*stack);
int						is_sort(t_list_nb *list , int size);
int						get_median(t_list_nb *list, int size, t_stack *stack);
t_list_nb				*there_is_lower(t_list_nb *list, int med, int size);
t_list_nb				*there_is_uper(t_list_nb *list, int med, int size);
t_list_nb 				*biggest(t_list_nb *list);

#endif
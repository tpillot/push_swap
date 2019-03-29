#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

typedef struct		s_list_nb
{
	int					nb;
	struct s_list_nb	*next;
	struct s_list_nb	*prev;
}					t_list_nb;

void	put_error(void);
void	swap(t_list_nb *list);
void	ss(t_list_nb *list_a, t_list_nb *list_b);
void	push(t_list_nb **list_1, t_list_nb **list_2);
void	rotate(t_list_nb **list);
void	rr(t_list_nb **list_1, t_list_nb **list_2);
void	reverse_rotate(t_list_nb **list);
void	rrr(t_list_nb **list_1, t_list_nb **list_2);

#endif
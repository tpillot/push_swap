NAME1 = push_swap
NAME2 = checker
INCLUDE = includes/
FLAGS = -Wall -Wextra -Werror
SRCS1 = push_swap.c\
		put_error.c\
		check_number.c\
		add_nb_to_list.c\
		go_to_next_digit.c\
		check_doublon.c\
		surgery.c\
		new_surgery.c\
		quick_sort.c\
		insertion_sort.c\


SRCS2 = checker.c\
		put_error.c\
		check_number.c\
		add_nb_to_list.c\
		go_to_next_digit.c\
		check_doublon.c\

SRCS_PATH = srcs/
OBJS_PATH = objs/
SRCO = $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJS_PATH), $(SRCO))

all : $(NAME1) : $(NAME2)

$(NAME1) : $(OBJS)
	@echo "\033[31mmaking $(NAME)...\033[0m"
	@gcc $(FLAGS) -I $(INCLUDE) $(OBJS) -o $(NAME)
	@echo "\033[32mDONE !\033[0m"

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p objs/
	@echo "\033[33mmaking $@\033[0m"
	@gcc -c $(FLAGS) -I $(INCLUDE) $< -o $@

clean :
	@echo "\033[31mcleaning objects...\033[0m"
	@rm -rf $(OBJS_PATH)
	@echo "\033[32mDONE !\033[0m"

fclean : clean
	@echo "\033[31mcleaning $(NAME)...\033[0m"
	@rm -f $(NAME)
	@echo "\033[32mDONE !\033[0m"

re : fclean all

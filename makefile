NAME1 = push_swap
NAME2 = checker
INCLUDE = includes/
FLAGS = -Wall -Wextra -Werror
SRCS = 	put_error.c\
		check_number.c\
		add_nb_to_list.c\
		go_to_next_digit.c\
		check_doublon.c\
		push.c\
		rotate.c\
		reverse_rotate.c\
		swap.c\
		new_surgery.c\
		quick_sort.c\
		best_way.c\
		biggest.c\
		size_3.c\
		print_surgery.c\
		size_2.c\
		is_sort.c\
		get_median.c\
		there_is_uper_or_lower.c\
		print_list.c\
		exect_option.c\
		read_and_exect.c

MAIN1 = push_swap.c\

MAIN1_OBJ = $(addprefix $(OBJS_PATH), $(MAIN1:.c=.o))

MAIN2 = checker.c\

MAIN2_OBJ = $(addprefix $(OBJS_PATH), $(MAIN2:.c=.o))

SRCS_PATH = srcs/
OBJS_PATH = objs/
SRCO = $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJS_PATH), $(SRCO))
LIB_NAME = libft.a
LIB_PATH = libft/

LIB = $(addprefix $(LIB_PATH), $(LIB_NAME))

all : $(NAME1) $(NAME2)

$(LIB) :
	@make -C $(LIB_PATH)

$(NAME1) : $(LIB) $(OBJS) $(MAIN1_OBJ)
	@echo "\033[31mmaking $(NAME1)...\033[0m"
	@gcc $(FLAGS) -o $(NAME1) -I $(INCLUDE) $(OBJS) $(MAIN1_OBJ) -L $(LIB_PATH) -lft
	@echo "\033[32mDONE !\033[0m"

$(NAME2) : $(LIB) $(OBJS) $(MAIN2_OBJ)
	@echo "\033[31mmaking $(NAME2)...\033[0m"
	@gcc $(FLAGS) -I $(INCLUDE) $(OBJS) $(MAIN2_OBJ) -o $(NAME2) -L $(LIB_PATH) -lft
	@echo "\033[32mDONE !\033[0m"

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p objs/
	@echo "\033[33mmaking $@\033[0m"
	@gcc -c $(FLAGS) -I $(INCLUDE) $< -o $@

clean :
	@make clean -C $(LIB_PATH)
	@echo "\033[31mcleaning objects...\033[0m"
	@rm -rf $(OBJS_PATH) $(MAIN1_OBJ) $(MAIN2_OBJ)
	@echo "\033[32mDONE !\033[0m"

fclean : clean
	@make fclean -C $(LIB_PATH)
	@echo "\033[31mcleaning $(NAME1) $(NAME2)...\033[0m"
	@rm -f $(NAME1) $(NAME2)
	@echo "\033[32mDONE !\033[0m"

re : fclean all

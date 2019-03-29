NAME = libft.a
INCLUDE = includes/
FLAGS = -Wall -Wextra -Werror
SRCS = ft_atoi.c\
		ft_bzero.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_itoa.c\
		ft_memalloc.c\
		ft_memccpy.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memdel.c\
		ft_memmove.c\
		ft_memset.c\
		ft_memswap.c\
		ft_putchar.c\
		ft_putchar_fd.c\
		ft_putendl.c\
		ft_putendl_fd.c\
		ft_putnbr.c\
		ft_putnbr_fd.c\
		ft_putstr.c\
		ft_putstr_fd.c\
		ft_strcat.c\
		ft_strchr.c\
		ft_strclr.c\
		ft_strcmp.c\
		ft_strcpy.c\
		ft_strdel.c\
		ft_strdup.c\
		ft_strequ.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strjoin.c\
		ft_strlcat.c\
		ft_strlen.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strncat.c\
		ft_strncmp.c\
		ft_strncpy.c\
		ft_strnequ.c\
		ft_strnew.c\
		ft_strrchr.c\
		ft_strsplit.c\
		ft_strstr.c\
		ft_strnstr.c\
		ft_strsub.c\
		ft_strtrim.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_lstnew.c\
		ft_lstdelone.c\
		ft_lstdel.c\
		ft_lstadd.c\
		ft_lstiter.c\
		ft_lstmap.c\

SRCS_PATH = srcs/

OBJS_PATH = objs/

SRCO = $(SRCS:.c=.o)

OBJS = $(addprefix $(OBJS_PATH), $(SRCO))

all : $(NAME)

MAKE_OBJ :
	@echo "\033[31mmaking objects...\033[0m"

SUCCESS : $(OBJS)
	@echo "\033[32mDONE !\033[0m"

$(NAME) : MAKE_OBJ SUCCESS
	@echo "\033[31mmaking $(NAME)...\033[0m"
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
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

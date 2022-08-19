NAME	= push_swap
LIBFT_A	= libft.a

SRCS_FILES	= 	${shell find ./src -name "*.c"}	\

SRCS		= 	$(SRCS_FILES)
OBJS		=	$(patsubst %.c,%.o,$(SRCS))

LIB_DIR		=	./inc/libft
INC			=	-I./libft

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

all:		$(NAME)

%.o:		%.c ./inc/push_swap.h
			$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME):	$(OBJS)
			@make -C $(LIB_DIR)
			@$(CC) $(CFLAGS) $(INC) ./inc/libft/libft.a $(OBJS) -o $(NAME)
			@clear

clean:
			@make clean -C $(LIB_DIR)
			$(RM) $(OBJS)

fclean:		clean
			@make fclean -C $(LIB_DIR)
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re


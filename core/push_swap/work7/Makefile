NAME = push_swap

CC = cc
CFLAGS = -g -Werror -Wall -Wextra
INCLUDES = -I./ -Ift_printf

FT_PRINTF_DIR = ./ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

SRC =	list/main.c \
		list/input.c \
		list/utils.c \
		list/sort.c \
		list/moves.c

OBJ = $(SRC:.c=.o)

INC		= -I$(FT_PRINTF_DIR) -Ilist

all: $(NAME)

$(FT_PRINTF):
	@make -C $(FT_PRINTF_DIR)

$(NAME): $(OBJ) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(FT_PRINTF) -o $(NAME)

clean:
	rm -f $(OBJ)
	@make -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make fclean -C $(FT_PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re
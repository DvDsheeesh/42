NAME = so_long

CC = cc
CFLAGS = -g -Werror #-Wall -Wextra
INCLUDES = -I./ -I./libft -I

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC =	list/list_new.c

OBJ = $(SRC:.c=.o)

INC		= -I$(LIBFT_DIR) -Ilist

all: $(NAME)


$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJ)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re


NAME    = so_long
CC      = cc
CFLAGS  = -Werror -g #-Wall -Wextra

# Path to your libft directory
LIBFT_DIR = ./libft
LIBFT     = $(LIBFT_DIR)/libft.a

# Your new project files
SRC     = get_next_line/get_next_line.c \
          get_next_line/get_next_line_utils.c \
          mapcheck/map_ch1.c

OBJ     = $(SRC:.c=.o)

INC     = -I. -I$(LIBFT_DIR) -Iget_next_line -Imapcheck

all: $(NAME)

run_val: all
	valgrind --leak-check=full -s ./so_long maplib/map.ber

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJ)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re

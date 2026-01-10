NAME = so_long

CC = cc
CFLAGS = -g -Werror -Wall -Wextra
INCLUDES = -I./ -I./libft -I./get_next_line -I./minilibx-linux

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC =	get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		mapcheck/map_ch1.c \
		render/render2.c

OBJ = $(SRC:.c=.o)

INC		= -I$(LIBFT_DIR) -Iso_long_inc -Iget_next_line -Iminilibx-linux -Imapcheck -Irender

all: $(MLX_LIB) $(NAME)

$(MLX_LIB):
	@make -C $(MLX_DIR)


$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJ)
	@make -C $(MLX_DIR) clean
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
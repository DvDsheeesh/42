NAME = so_long
SRC = main.c

CC = gcc
CCFLAGS = -Werror # -Wextra -Wall
LINUX_FLAGS = -lXext -lX11 -lbsd -lm
#-lmlx

OBJ := $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ) # $(GNL_OBJ) $(PRINTF_OBJ)
	$(CC) $(CCFLAGS) $^ minilibx-linux/libmlx.a $(LINUX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) -Iminilibx-linux -Iincludes -c $< -o $@

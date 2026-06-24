NAME = philo_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
		philo_process_bonus.c \
		philo_process_helpers_bonus.c \
		monitor_bonus.c \
		time_bonus.c \
		init_bonus.c \
		init_helpers_bonus.c \
		parse_args_bonus.c

OBJ_DIR = obj

OBJS = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -rf $(NAME) $(OBJ_DIR)

re: fclean all

.PHONY: all clean fclean re
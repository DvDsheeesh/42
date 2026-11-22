NAME = philo

CC = cc
CFLAGS = -g -Werror #-Wall -Wextra


SRC =	utils.c \
		arguments.c \
		main.c

OBJ = $(SRC:.c=.o)

all: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -lreadline

fclean:
	rm -f $(OBJ) $(NAME)

clean:
	rm -f $(OBJ)

re: fclean all

.PHONY: all rerun clean fclean re
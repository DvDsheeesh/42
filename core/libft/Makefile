cfiles = ft_isalpha.c ft_substr.c ft_strlen.c ft_strdup.c ft_strjoin.c

NAME = libft.a
CC = cc
FLAGS = -Wall -Wextra -Werror
OBJ = $(cfiles:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

testt: all fclean
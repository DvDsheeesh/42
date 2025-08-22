cfiles =	ft_isalpha.c \
			ft_substr.c \
			ft_strlen.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_count_word.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c

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

CFILES = phonebook.cpp
CC = c++
CFLAGS = -Werror -Wall -Wextra -std=c++98
OBJ = $(CFILES:.cpp=.o)

all: $(NAME)
	
$(NAME):$(OBJ)
	ar rcs $(NAME) $(OBJ)

vv:
	c++ -Wall -Werror -Wextra $(files) -std=c++98 -v

clean:
	rm -f $(target)

fclean: clean

re: clean all

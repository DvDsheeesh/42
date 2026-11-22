
# all:
# 	c++ -Wall -Werror -Wextra $(files) -std=c++98 -o $(target)

# vv:
# 	c++ -Wall -Werror -Wextra $(files) -std=c++98 -v

CFILES = megaphone.cpp
CC = c++
CFLAGS = -Werror -Wall -Wextra -std=c++98 -v
OBJ = $(CFILES:.cpp=.o)

all: $(NAME)
	
$(NAME):$(OBJ)
	ar rcs $(NAME) $(OBJ)

fclean:
	rm -f $(OBJ) $(NAME)

clean:
	rm -f $(OBJ)

re: fclean all

run: re
	./$(target) "shhhhh... I think the students are asleep..."
	@echo
	./$(target) "Damnit, I'm stuck in a loop!"
	@echo
	./$(target) "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
	@echo
	./$(target) "STOP CALLING ME SHIRLEY"
	@echo
	./$(target)
	@echo

.PHONY: all clean fclean re

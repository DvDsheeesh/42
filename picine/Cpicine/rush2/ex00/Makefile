
all: main.c
	@echo "testing make"
	cc -Wall -Wextra -Werror -c main.c
	cc -Wall -Wextra -Werror -c 2nd.c
	cc -Wall -Wextra -Werror -c 4th.c
	cc -Wall -Wextra -Werror -c 5th.c
	cc -Wall -Wextra -Werror main.o 2nd.o 4th.o 5th.o -o rush-02
	
fclean:
	rm *.o

clean:
	rm rush-02
	rm *.o
	
main:
	cc -Wall -Wextra -Werror -c main.c
	
2nd:
	cc -Wall -Wextra -Werror -c 2nd.c

3rd:
	cc -Wall -Wextra -Werror -c 3rd.c
	
4th:
	cc -Wall -Wextra -Werror -c 4th.c
	
5th:
	cc -Wall -Wextra -Werror -c 5th.c
	
final:
	cc -Wall -Wextra -Werror main.o 2nd.o 3rd.o 4th.o 5th.o -o rush-02

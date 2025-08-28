
done: main.c
	@echo "testing make"
	cc -Wall -Wextra -Werror main.c -o rush-02
	./rush-02
	#rm rush-02

gg: main.c
	@echo "testing cc main.c to main.o"
	cc -Wall -Wextra -Werror -c main.c

test: test.c
	@echo "testing cc test.c to test.o"
	cc -Wall -Wextra -Werror -c test.c
	
push:
	git clone git@vogsphere.42amman.com:vogsphere/intra-uuid-67691005-4504-48fd-947c-c4cf3d26a450-6276872-melshata jj
	
fclean:
	clear

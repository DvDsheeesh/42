#include <unistd.h>

void	calling(char al)
{
	write(1, &al, 1);
	if (al <= 'c')
		calling(al + 1);
	write(1, &al, 1);
}


int	main(void)
{
	calling('a');
	return (0);
}

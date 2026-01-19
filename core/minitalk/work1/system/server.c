#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

#include "../ft_printf/ft_printf.h"

size_t	len(char *s)
{
	size_t	l;

	if (!s)
		return (0);
	l = 0;
	while (s[l])
		l++;
	return (l);
}

static char	*extend_str(char *s1, char c)
{
	char	*ss;
	size_t	i;

	ss = malloc(len(s1) + 2);
	if (!ss)
		return (NULL);
	i = 0;
	if (s1)
	{
		while (s1[i])
		{
			ss[i] = s1[i];
			i++;
		}
	}
	free(s1);
	ss[i++] = c;
	ss[i] = '\0';
	return (ss);
}

void	singal_handler(int sig)
{
	static int	bitcount = 0;
	static char chrr = 0;
	static char	*msg = NULL;
	char		bit;

	bit = 0;
	if (sig == SIGUSR2)
		bit = 1;
	bitcount++;
	chrr = (chrr << 1) + bit;
	if (bitcount == 8)
	{
		ft_printf ("%c\n", chrr);
		msg = extend_str (msg, chrr);
		bitcount = 0;
		if (chrr == 0)
		{
			ft_printf ("%s\n", msg);
			free (msg);
		}
		chrr = 0;
	}
}
  
int main()  {
	signal(SIGUSR1, singal_handler);
	signal(SIGUSR2, singal_handler);
	// while (1){
	// 	printf("Hello World!\n");
	// }
	// sleep(2);
	ft_printf ("pid: %d\n", getpid());


	kill(getpid(), SIGUSR1); // A
	kill(getpid(), SIGUSR2);
	kill(getpid(), SIGUSR1);
	kill(getpid(), SIGUSR1);

	kill(getpid(), SIGUSR1);
	kill(getpid(), SIGUSR1);
	kill(getpid(), SIGUSR1);
	kill(getpid(), SIGUSR2);


	kill(getpid(), SIGUSR1); // B
	kill(getpid(), SIGUSR2);
	kill(getpid(), SIGUSR1);
	kill(getpid(), SIGUSR1);

	kill(getpid(), SIGUSR1);
	kill(getpid(), SIGUSR1);
	kill(getpid(), SIGUSR2);
	kill(getpid(), SIGUSR1);


	kill(getpid(), SIGUSR1); // C
	kill(getpid(), SIGUSR2);
	kill(getpid(), SIGUSR1);
	kill(getpid(), SIGUSR1);

	kill(getpid(), SIGUSR1);
	kill(getpid(), SIGUSR1);
	kill(getpid(), SIGUSR2);
	kill(getpid(), SIGUSR2);


	kill(getpid(), SIGUSR1); // space
	kill(getpid(), SIGUSR1);
	kill(getpid(), SIGUSR2);
	kill(getpid(), SIGUSR1);

	kill(getpid(), SIGUSR1);
	kill(getpid(), SIGUSR1);
	kill(getpid(), SIGUSR1);
	kill(getpid(), SIGUSR1);


	kill(getpid(), SIGUSR1); // \0
	kill(getpid(), SIGUSR1);
	kill(getpid(), SIGUSR1);
	kill(getpid(), SIGUSR1);

	kill(getpid(), SIGUSR1);
	kill(getpid(), SIGUSR1);
	kill(getpid(), SIGUSR1);
	kill(getpid(), SIGUSR1);
	
	while (1)
		pause();
}
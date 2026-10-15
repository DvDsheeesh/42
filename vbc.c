
#include <stdio.h>

int skipp(char *ex, int i)
{
	int c = 0;
	if (ex[i] == '(') i++;
	while (ex[i])
	{
		if (ex[i] == ')' && c == 0)
			return i;
		if (ex[i] == ')')
			c--;
		if (ex[i] == '(')
			c++;
		i++;
	}
	return i;
}

int new_part(char *ex, int i)
{
	int sum;
	sum = (ex[i] >= '0' && ex[i] <= '9'? ex[i] - 48 : 0);
	while (ex[i])
	{
		printf("i=%d\n", i);
		if (ex[i] == '(')
		{
			printf("start new bow\n");
			if (sum == 0)
			return new_part(ex, i + 1);
			i = skipp(ex, i + 1);
		}
		if (ex[i] == ')')
		{
			return sum;
		}
		else if (ex[i] == '+')
		{
			printf("start new plus\n");
			sum += new_part(ex, i + 1);
			i = skipp(ex, i + 1);
		}
		else if (ex[i] == '*')
		{
			if (ex[i + 1] == '(')
			{
				sum *= new_part(ex, i + 1);
				i = skipp(ex, i + 1);
			}
			else
			{
				sum *= ex[i + 1] - 48;
				i++;
			}
		}
		printf("%d\n", sum);
		i++;
	}
	return sum;
}


int main(int ac, char **av)
{
	if (ac != 2) return 1;
	printf("%d\n", new_part(av[1], 0));
	return 0;
}

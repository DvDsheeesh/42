unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (src[i])
	{
		if (i < size - 1)
			dest[i] = src[i];
		if (i == size - 1)
			dest[i] = 0;
		i++;
	}
	return (i);
}
/*
#include <stdio.h>
#include <string.h>

int main() {
    char buffer[13];
    char test[13];
    char *src = "HelloWorld";


    size_t result = strlcpy(buffer, src, 5);
    size_t resultt = ft_strlcpy(test, src, 5);

    printf("Final String: %s\n", buffer);  // Output: "Hello"
    printf("Total Length: %zu\n", result); // Output: 10 (tried to copy "HelloWorld")

    printf("Final String: %s\n", test);  // Output: "Hello"
    printf("Total Length: %zu\n", resultt); // Output: 10 (tried to copy "HelloWorld")

    return 0;
}
*/

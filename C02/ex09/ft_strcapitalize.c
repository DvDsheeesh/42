int	isal(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	str = ft_strlowcase(str);
	i = 1;
	if (isal(str[0]))
		str[0] -= 32;
	while (str[i])
	{
		if (isal(str[i]))
			if (!(isal(str[i - 1]) || (str[i - 1] >= '0' && str[i - 1] <= '9')))
				str[i] -= 32;
		i++;
	}
	return (str);
}

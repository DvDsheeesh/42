#include "philo.h"

int	parse_arguments(int argc, char **argv, t_config *config)/////اعادة ترتيب 
{
	if (argc != 5 && argc != 6)
	{
		print_error_message();
		return (0);
	}
	config->must_eat_count = -1;
	if (!parse_required_args(argv, argc, config))
	{
		print_error_message();
		return (0);
	}
	return (1);
}

void	print_error_message(void)
{
	write(2, "Error\n", 6);
	write(2, "Usage: ./philo number_of_philosophers time_to_die ", 50);
	write(2, "time_to_eat time_to_sleep ", 26);
	write(2, "[number_of_times_each_philosopher_must_eat]\n", 44);
}

int	parse_required_args(char **argv, int argc, t_config *config)
{
	if (!parse_positive_int(argv[1], &config->number_of_philosophers))
		return (0);
	if (!parse_positive_int(argv[2], &config->time_to_die))
		return (0);
	if (!parse_positive_int(argv[3], &config->time_to_eat))
		return (0);
	if (!parse_positive_int(argv[4], &config->time_to_sleep))
		return (0);
	if (argc == 6 && !parse_positive_int(argv[5], &config->must_eat_count))
		return (0);
	return (1);
}

int	parse_positive_int(const char *str, int *out)
{
	long	value;
	int		index;

	if (!is_str_positive_number(str))
		return (0);
	index = 0;
	if (str[index] == '+')
		index++;
	value = 0;
	while (str[index])
	{
		value = (value * 10) + (str[index] - '0');
		if (value > INT_MAX)
			return (0);
		index++;
	}
	if (value <= 0)
		return (0);
	*out = (int)value;
	return (1);
}

int	is_str_positive_number(const char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	if (str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

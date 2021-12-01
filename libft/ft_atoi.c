#include "../incs/ft_printf.h"

int	ft_atoi(const char *str)
{
	int	signe;
	int	result;

	signe = 1;
	result = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			signe = -signe;
		str++ ;
	}
	while (*str && ft_isdigit(*str))
	{
		result = result * 10 + *str - 48;
		str++;
	}
	result *= signe;
	return (result);
}

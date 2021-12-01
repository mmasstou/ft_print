#include "../incs/ft_printf.h"

int	ft_putstr(char *str)
{
	int	index;

	index = 0;
	while (*str)
		index += write(1, str++, 1);
	return (index);
}

#include "../incs/ft_printf.h"

int	ft_Unbrlen(unsigned n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	if (n <= 0)
	{
		n = -n;
		size++;
	}
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}
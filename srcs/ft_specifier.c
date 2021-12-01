#include "../incs/ft_printf.h"

void	ft_specifier(t_printf *tab,const char *format, int index)
{
	if (format[index] == 'c')
		ft_print_char(tab);
	else if (format[index] == 'd' || format[index] == 'i'){}
		//ft_print_integer(tab);
	else if (format[index] == 's')
		ft_print_str(tab);
	else if (format[index] == 'u'){}
	else if (format[index] == 'X' || format[index] == 'x'){}
	else if (format[index] == '%'){}
}
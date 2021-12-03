#include "../incs/ft_printf.h"

void	flags_check(t_printf *tab, const char *format, int index)
{
	if (tab->zero && tab->dash)
	{
		tab->zero = 0;
		tab->_rep->zero = 0;
		tab->_rep->flags -= 1;
	}
	if (is_integer_specifier(format[index]))
	{
		if (tab->zero && tab->precision)
		{
			tab->zero = 0;
			tab->_rep->zero = 0;
			tab->_rep->flags -= 1;
		}
		if (tab->plus)
		{
			tab->space = 0;
			tab->_rep->space = 0;
			tab->_rep->flags -= 1;
		}	
	}
	
}
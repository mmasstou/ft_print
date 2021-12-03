#include "../incs/ft_printf.h"


void	dash_flag(t_printf *tab, const char *format, int index)
{
	char	a;

	if (format[index] == 'c')
	{
		a = va_arg(tab->args, int);
		if (tab->dash && tab->width)
		{
			tab->tl += write(1, &a, 1);
			ft_right_cs(tab, format, index);
			tab->dash = 0;
			tab->_rep->dash = 0;
			tab->width = 0;
			tab->_rep->width = 0;
		}
		if (tab->dash && !tab->width )
		{
			tab->tl += write(1, &a, 1);
			tab->dash = 0;
			tab->_rep->dash = 0;
		}
	}
}

#include "incs/ft_printf.h"


int ft_printf(const char *format, ...)
{
	int ret;
	int	index;
	t_printf *tab;

	index = -1;				
	tab = (t_printf *)malloc(sizeof(t_printf));
	if (!tab)                         
		return (-1);
	tab->_rep = (t_rep *)malloc(sizeof(t_rep));
	if (!(tab->_rep))                         
		return (-1);
	ft_initialise_tab(tab);
	va_start(tab->args, format);
	ret = 0;
	while (format[++index]) //while the string exists
	{ 
		if (format[index] == '%')
			index = ft_eval_format(tab, format, index + 1);
		else
			ret += write(1, &format[index], 1); //print what you read
	}
	va_end(tab->args);
	ret += tab->tl;
	free (tab);
	free (tab->_rep);
	return (ret);
	}


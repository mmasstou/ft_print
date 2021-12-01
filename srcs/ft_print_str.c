#include "../incs/ft_printf.h"

void	ft_print_str(t_printf *tab)
{
	char *str;

	str  = va_arg(tab->args, char *);
	if (str == NULL)
		tab->tl += ft_putstr("(null)");
	else
		tab->tl += ft_putstr(str);
}

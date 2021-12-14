#include "../incs/ft_printf.h"

void	ft_zero_flag(t_printf *tab)
{
	int nbr;
	int	m;

	nbr = va_arg(tab->args, int);
	if (tab->_rep->width > ft_nbrlen(nbr))
	{
		m = tab->_rep->width - ft_nbrlen(nbr);
		while (m--)
			tab->tl += write(1, "0",1);
		tab->tl += ft_putnbr(nbr);
	}
}
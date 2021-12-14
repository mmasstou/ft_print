#include "../incs/ft_printf.h"

void	ft_dash_pnt(t_printf *tab)
{
	int m;
	int precision;
	int	nbr;
	int	nbrl;

	precision = tab->_rep->precision;
	nbr = va_arg(tab->args, int);
	nbrl = ft_nbrlen(nbr);
	if (!tab->_rep->width && !tab->_rep->precision)
		tab->tl += ft_putnbr(nbr);
	else if (tab->_rep->width && !tab->_rep->precision)
	{
		tab->tl += ft_putnbr(nbr);
		m = tab->_rep->width - nbrl;
		while (m--)
			tab->tl += write(1, " ", 1);
	}
	else if (tab->_rep->width > tab->_rep->precision)
	{
		if ( tab->_rep->precision >= nbrl)
		{
			m = precision - nbrl;
			while (m--)
				tab->tl += write(1, "0", 1);
			tab->tl += ft_putnbr(nbr);
			m = tab->_rep->width - tab->_rep->precision;
			while (m--)
				tab->tl += write(1, " ", 1);
		}
		else
			tab->tl += ft_putnbr(nbr);
	}
	else if (tab->_rep->width <= tab->_rep->precision || (!tab->_rep->width && tab->_rep->precision))
	{
		m = precision - nbrl;
		while (m--)
			tab->tl += write(1, "0", 1);
		tab->tl += ft_putnbr(nbr);
	}
	ft_resize_flags(tab);
}
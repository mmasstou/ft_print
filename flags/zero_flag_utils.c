#include "../incs/ft_printf.h"

int	zf_pnt_pre_p_l_w(t_printf *tab, int nbr, int len)
{
	int n;
	int m;
	int cp_p;
	if (nbr >= 0)
	{
		if (tab->_rep->precision > len)
		{
			cp_p = tab->_rep->precision;
			n = cp_p - len;
			m =tab->_rep->width - tab->_rep->precision ;
			while (m--)
				tab->tl += write(1, " ",1);
			while (n--)
				tab->tl += write(1, "0",1);
			tab->tl += ft_putnbr(nbr);
		}
		else if (tab->_rep->precision < len)
		{
			if (tab->_rep->width > len)
			{
				if (nbr != 0)
				{
					m = tab->_rep->width - len ;
					while (m--)
						tab->tl += write(1, " ",1);
					tab->tl += ft_putnbr(nbr);
				}
				else 
				{
					m = tab->_rep->width;
					while (m--)
						tab->tl += write(1, " ",1);
				}
			}
			else if (tab->_rep->width <= len)
			{
				if (nbr != 0)
					tab->tl += ft_putnbr(nbr);
				else 
				{
					m = tab->_rep->width;
					while (m--)
						tab->tl += write(1, " ",1);
				}
			}
			// else if (tab->_rep->width == len)
			// 	tab->tl += ft_putnbr(nbr);
		}
		else if (tab->_rep->precision == len)
			tab->tl += ft_putnbr(nbr);
	}
	else if (nbr < 0)
	{
		
		if (tab->_rep->precision > (len + 1))
		{
			cp_p = tab->_rep->precision;
			n = cp_p - len ;
			m =tab->_rep->width - (tab->_rep->precision + 1) ;
			while (m--)
				tab->tl += write(1, " ",1);
			tab->tl += write(1, "-",1);
			while (n--)
				tab->tl += write(1, "0",1);
			tab->tl += ft_putnbr(nbr);
		}
		else if (tab->_rep->precision <= (len + 1))
		{
			
			if (tab->_rep->width > (len + 1))
			{
				m = tab->_rep->width - (len + 1);
				while (m--)
					tab->tl += write(1, " ",1);
				tab->tl += write(1, "-",1);
				tab->tl += ft_putnbr(nbr);
			}
			else if (tab->_rep->width <= (len + 1))
			{
				tab->tl += write(1, "-",1);
				tab->tl += ft_putnbr(nbr);
			}
		}
	}
	return (0);
}
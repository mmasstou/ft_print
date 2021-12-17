#include "../incs/ft_printf.h"

int	ft_zero_flag(t_printf *tab)
{
	int nbr;
	int	m;
	int n;
	int	len;
	int cp_p;

	nbr = va_arg(tab->args, int);
	len  = ft_nbrlen(nbr);
	// if (nbr < 0)
	// 	len +=  1;		
	if (!tab->pnt)
	{
		if (!tab->width)
		{
			if (nbr < 0)
			{
				tab->tl += write(1, "-",1);
			}
			tab->tl += ft_putnbr(nbr);
			ft_resize_flags(tab);
			return (1);
		}
		else if (tab->width)
		{
			if (nbr < 0)
			{
				tab->tl += write(1, "-",1);
				len += 1;
			}
			if (tab->_rep->width > len)
			{
				m = tab->_rep->width - len;
				while (m--)
					tab->tl += write(1, "0",1);
				tab->tl += ft_putnbr(nbr);
			}
			else if (tab->_rep->width <= len)
				tab->tl += ft_putnbr(nbr);
		}
		ft_resize_flags(tab);
		return (1);
	}
	else if (tab->pnt)
	{
		if (tab->precision)
		{
			if (tab->width)
			{
				if (tab->_rep->precision > tab->_rep->width)
				{
					if (nbr < 0)
					{
						tab->tl += write(1, "-",1);
						
					}
					n = tab->_rep->precision - len;
					while (n--)
						tab->tl += write(1, "0",1);
					tab->tl += ft_putnbr(nbr);
				}
				else if (tab->_rep->precision < tab->_rep->width)
				{
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
				}
				else if (tab->_rep->precision == tab->_rep->width)
				{
					if (nbr < 0)
						tab->tl += write(1, "-",1);
					n = tab->_rep->precision - len ;
					while (n--)
						tab->tl += write(1, "0",1);
					tab->tl += ft_putnbr(nbr);
				
				}
			}
			else if (!tab->width)
			{
				if (tab->_rep->precision > len)
				{
					if (nbr < 0)
					{
						if (nbr < 0)
							tab->tl += write(1, "-", 1);
					}
					n = tab->_rep->precision - len;
					while (n--)
						tab->tl += write(1, "0",1);
					tab->tl += ft_putnbr(nbr);
				}
				else if (tab->_rep->precision <= len)
				{
					if (nbr == 0)
					{
						if (tab->_rep->precision == 0)
							return(ft_resize_flags(tab),1);
						else if (tab->_rep->precision > 0) 
						{
							tab->tl += ft_putnbr(nbr);
							return(ft_resize_flags(tab),1);
						}
						
					}
					else if (nbr < 0)
						tab->tl += write(1, "-", 1);
					tab->tl += ft_putnbr(nbr);
				}
			}
		}
		else if (!tab->precision)
		{
			if (!tab->width)
			{
				if (nbr == 0)
				{
					ft_resize_flags(tab);
					return (1);
				}
				else if (tab->width)
				{
					if (tab->_rep->width > len)
					{
						m = tab->_rep->width -len;
						while (m--)
							tab->tl += write(1, " ",1);
					}
				}
				if (nbr < 0)
					tab->tl += write(1, "-", 1);
				tab->tl += ft_putnbr(nbr);
			}
			else if (tab->width)
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
		}
	
	}
	ft_resize_flags(tab);
	return (0);
}
#include "../incs/ft_printf.h"

static int	zero_pnt_precision_no_dash(t_printf *tab, unsigned int nbr,int len)
{
	int n;
	int m;
	int cp_p;

	if (tab->precision)
	{
		if (tab->width)
		{
			if (tab->_rep->precision > tab->_rep->width)
			{
				n = tab->_rep->precision - len;
				while (n--)
					tab->tl += write(1, "0",1);
				tab->tl += ft_putunsigned(nbr);
			}
			else if (tab->_rep->precision < tab->_rep->width)
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
					tab->tl += ft_putunsigned(nbr);
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
							tab->tl += ft_putunsigned(nbr);
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
							tab->tl += ft_putunsigned(nbr);
						else 
						{
							m = tab->_rep->width;
							while (m--)
								tab->tl += write(1, " ",1);
						}
					}
					// else if (tab->_rep->width == len)
					// 	tab->tl += ft_putunsigned(nbr);
				}
				else if (tab->_rep->precision == len)
					tab->tl += ft_putunsigned(nbr);
				
			}
			else if (tab->_rep->precision == tab->_rep->width)
			{
				n = tab->_rep->precision - len ;
				while (n--)
					tab->tl += write(1, "0",1);
				tab->tl += ft_putunsigned(nbr);
			
			}
		}
		else if (!tab->width)
		{
			if (tab->_rep->precision > len)
			{
				n = tab->_rep->precision - len;
				while (n--)
					tab->tl += write(1, "0",1);
				tab->tl += ft_putunsigned(nbr);
			}
			else if (tab->_rep->precision <= len)
			{
				if (nbr == 0)
				{
					if (tab->_rep->precision == 0)
						return(ft_resize_flags(tab),1);
					else 
					{
						tab->tl += ft_putunsigned(nbr);
						return(ft_resize_flags(tab),1);
					}
					
				}
				else if (nbr < 0)
					tab->tl += write(1, "-", 1);
				tab->tl += ft_putunsigned(nbr);
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
			tab->tl += ft_putunsigned(nbr);
		}
		else if (tab->width)
		{
			if (nbr != 0)
				tab->tl += ft_putunsigned(nbr);
			else
			{
				m = tab->_rep->width;
				while (m--)
					tab->tl += write(1, " ",1);
			}
		}
	}
	return (0);
}
static int	zero_no_pnt_precision_no_dash(t_printf *tab, unsigned int nbr,int len)
{
	int	m;
	
	if (!tab->width)
	{
		tab->tl += ft_putunsigned(nbr);
		ft_resize_flags(tab);
		return (1);
	}
	else if (tab->width)
	{
		if (tab->_rep->width > len)
		{
			m = tab->_rep->width - len;
			while (m--)
				tab->tl += write(1, "0",1);
			tab->tl += ft_putunsigned(nbr);
		}
		else if (tab->_rep->width <= len)
			tab->tl += ft_putunsigned(nbr);
	}
	ft_resize_flags(tab);
	return (1);
}
static int	dash_pnt_width_no_zero(t_printf *tab, unsigned int nbr,int len)
{
	int n;
	int m;
	int cp_p;
	
	if (!tab->dash)
	{
		if (tab->precision)
		{
			if (tab->width)
			{
				if (tab->_rep->precision > tab->_rep->width)
				{
					if (tab->_rep->precision > len)
					{
						n = tab->_rep->precision  -  len ;
						while (n--)
							tab->tl += write (1, "0", 1);
						tab->tl += ft_putunsigned(nbr);	
					}
					else if (tab->_rep->precision <=  len)
						tab->tl += ft_putunsigned(nbr);
				}
				else if (tab->_rep->precision <= tab->_rep->width)
				{
					if (tab->_rep->width <= len)
						tab->tl += ft_putunsigned(nbr);
					else if (tab->_rep->width > len)
					{
						if (tab->_rep->precision <= len )
						{
							m = tab->_rep->width - len;
							while (m--)
								tab->tl += write (1, " ", 1);
							tab->tl += ft_putunsigned(nbr);
						
						}
						else if (tab->_rep->precision > len )
						{
							cp_p = tab->_rep->precision;
							m = tab->_rep->width - tab->_rep->precision;
							n = cp_p - len;
							while (m--)
								tab->tl += write (1, " ", 1);
							while (n--)
								tab->tl += write (1, "0", 1);
							tab->tl += ft_putunsigned(nbr);
						}
					}
				}
			}
		}
	}
	else if (tab->dash)
	{
		if (tab->precision)
		{
			if (tab->width)
			{
				if (tab->_rep->precision > tab->_rep->width)
				{
					if (tab->_rep->precision > len)
					{
						n = tab->_rep->precision - len;
						while (n--)
							tab->tl += write(1, "0", 1);
						tab->tl += ft_putunsigned(nbr);
					}
					else if (tab->_rep->precision <= len)
						tab->tl += ft_putunsigned(nbr);
				}
				else if (tab->_rep->precision < tab->_rep->width)
				{
					if (tab->_rep->width > len)
					{
						if (tab->_rep->precision > len)
						{
							cp_p = tab->_rep->precision;
							n = cp_p - len;
							m = tab->_rep->width - tab->_rep->precision;
							while (n--)
								tab->tl += write(1, "0", 1);
							tab->tl += ft_putunsigned(nbr);
							while (m--)
								tab->tl += write(1, " ", 1);
						}
						else if (tab->_rep->precision <= len)
						{
							m = tab->_rep->width -len ;
							tab->tl += ft_putunsigned(nbr);
							while (m--)
								tab->tl += write(1, " ", 1);
						}
					}
					else if (tab->_rep->width <= len)
						tab->tl += ft_putunsigned(nbr);
				}
				else if (tab->_rep->precision == tab->_rep->width)
				{
					
					n = tab->_rep->precision - len;
					while (n--)
						tab->tl += write(1, "0", 1);
					tab->tl += ft_putunsigned(nbr);
				}
			}
			else if (!tab->width)
			{
				if (tab->_rep->precision > len)
				{
					n = tab->_rep->precision - len;
					while (n--)
						tab->tl += write(1, "0", 1);
					tab->tl += ft_putunsigned(nbr);
				}
				else if (tab->_rep->precision <= len)
					tab->tl += ft_putunsigned(nbr);
			}
		}
		else if (!tab->precision)
		{
			if (tab->width)
			{
				if (tab->_rep->width > len)
				{
					m = tab->_rep->width;
					while (m--)
						tab->tl += write(1, " ", 1);
				}
				else if (tab->_rep->width <= len)
					tab->tl += ft_putunsigned(nbr);
			}
			else if (!tab->width){}
		}
	}
	return (0);	
}
static int	dash_no_pnt_width_no_zero(t_printf *tab, unsigned int nbr,int len, int m)
{
	if (!tab->dash)
	{
		if (tab->width && tab->_rep->width > len)
		{
			m = tab->_rep->width - len;
			while (m--)
				tab->tl += write (1, " ", 1);
		}
		tab->tl += ft_putunsigned(nbr);
	}
	else if (tab->dash)
	{
		if (tab->width && tab->_rep->width > len)
		{
			m = tab->_rep->width - len;
			tab->tl += ft_putunsigned(nbr);
			while (m--)
				tab->tl += write (1, " ", 1);
		}
		else if ((tab->width && tab->_rep->width <= len) || !tab->width)
			tab->tl += ft_putunsigned(nbr);
	}
	return (ft_resize_flags(tab), 0);
}
int	u_flags(t_printf *tab)
{
	unsigned int	nbr;
	int				len;
	int				m;

	m = 0;
	nbr = va_arg(tab->args, unsigned int);
	len = ft_Unbrlen(nbr);		
	if ((tab->zero || tab->pnt || tab->precision) && !tab->dash )
	{
		if (!tab->pnt)
			zero_no_pnt_precision_no_dash(tab, nbr, len);
		else if (tab->pnt)
			zero_pnt_precision_no_dash(tab, nbr, len);
	}
	else if ((tab->dash || tab->pnt || tab->width) && !tab->zero)
	{
		if (!tab->pnt)
			dash_no_pnt_width_no_zero(tab, nbr, len, m);
		else if (tab->pnt)
			dash_pnt_width_no_zero(tab, nbr, len);
	}
	return (ft_resize_flags(tab), 1);
}
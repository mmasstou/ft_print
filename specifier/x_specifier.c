#include "../incs/ft_printf.h"

int	x_flag(t_printf *tab, const char *format, int index)
{
	int 			len;
	unsigned int	u;
	int				m;
	int				c_precision;

	
	u = 0;
	len = 0;
	c_precision = 0;
	if (tab->shrap)
		shrap_flag(tab, format[index]);
	
	
	if (tab->width || tab->pnt || tab->dash)
	{
		
		// pnt
		if (tab->_rep->precision != 0 && !tab->dash && !tab->width )
		{
			u = va_arg(tab->args, unsigned int);
			len = ft_hex_len(u);
			if (tab->_rep->precision > len )
			{
				m = tab->_rep->precision - len;
				while (m--)
					tab->tl += write(1, "0",1);
				tab->tl += ft_puthex(u, format[index]);
				ft_resize_flags(tab);
				return (1);
			}
			else if ((tab->_rep->precision <= len) )
			{
				tab->tl += ft_puthex(u, format[index]);
				ft_resize_flags(tab);
				return (1);
			}
		}
		else if (tab->_rep->precision == 0 && !tab->dash && !tab->width)
		{
			u = va_arg(tab->args, unsigned int);
			len = ft_hex_len(u);
			if ( u != 0)
				tab->tl += ft_puthex(u, format[index]);
			ft_resize_flags(tab);
			return (1);
		}
		else if (!tab->width &&  tab->dash && !tab->pnt)
		{
			u = va_arg(tab->args, unsigned int);
			len = ft_hex_len(u);
			tab->tl += ft_puthex(u, format[index]);
			ft_resize_flags(tab);
			return (1);
		}
		else if (tab->pnt && tab->dash)
		{
			if (!tab->precision)
			{
				if (tab->width)
				{
					if (tab->_rep->width > len)
					{
						m = tab->_rep->width - len;
						while (m--)
							tab->tl += write(1, " ",1);
						ft_resize_flags(tab);
						return (1);
					}
				}
				else if (!tab->width)
				{
					ft_resize_flags(tab);
					return (1);
				}
			}
			else if (tab->precision)
			{
				if (tab->width)
				{
					u = va_arg(tab->args, unsigned int);
					len = ft_hex_len(u);
					if (tab->_rep->precision > tab->_rep->width)
					{
						if (tab->_rep->precision <= len)
						{
							tab->tl += ft_puthex(u, format[index]);
							ft_resize_flags(tab);
							return (1);	
						}
						m = tab->_rep->precision - len;
						while (m--)
							tab->tl += write(1, "0",1);
						tab->tl += ft_puthex(u, format[index]);
						ft_resize_flags(tab);
						return (1);
					}
					else if (tab->_rep->precision <= tab->_rep->width)
					{
						c_precision = tab->_rep->precision;
						m = c_precision - len;
						if(tab->_rep->width < len)
						{
							tab->tl += ft_puthex(u, format[index]);
							ft_resize_flags(tab);
							return(1);
						}
						if (tab->_rep->precision > len)
						{
							while (m--)
								tab->tl += write(1, "0",1);
							tab->tl += ft_puthex(u, format[index]);
							m = tab->_rep->width - tab->_rep->precision;
							while (m--)
								tab->tl += write(1, " ",1);
							ft_resize_flags(tab);
							return (1);
						}
						else if (tab->_rep->precision <= len)
						{
							tab->tl += ft_puthex(u, format[index]);
							m = tab->_rep->width - len;
							while (m--)
								tab->tl += write(1, " ",1);
							ft_resize_flags(tab);
							return (1);
						}
					}
				}
				else if (!tab->width)
				{
					u = va_arg(tab->args, unsigned int);
					len = ft_hex_len(u);
					if (tab->_rep->precision > len )
					{
						m = tab->_rep->precision - len;
						while (m--)
							tab->tl += write(1, "0",1);
						tab->tl += ft_puthex(u, format[index]);
						ft_resize_flags(tab);
						return(1);
					}
					else if ((tab->_rep->precision <= len) )
					{
						tab->tl += ft_puthex(u, format[index]);
						ft_resize_flags(tab);
						return (1);
					}
				}
			}
		}
	}
	// width pnt zero
	if (tab->width || tab->pnt || tab->zero)
	{
		
		// dash or width
		if ((tab->dash || tab->width) && !tab->zero )
		{
			u = va_arg(tab->args, unsigned int);
			len = ft_hex_len(u);
			if (!tab->dash && tab->width)
			{
				if (!tab->pnt)
				{
					if (tab->_rep->width > len)
					{
						m = tab->_rep->width - len;
						while (m--)
							tab->tl += write(1, " ",1);
					}
					tab->tl += ft_puthex(u, format[index]);
				}
				else if (tab->pnt)
				{
					// 
					if (tab->_rep->precision > tab->_rep->width)
					{
						if (tab->_rep->precision <= len)
						{
							tab->tl += ft_puthex(u, format[index]);
							ft_resize_flags(tab);
							return (1);	
						}
						m = tab->_rep->precision - len;
						while (m--)
							tab->tl += write(1, "0",1);
						tab->tl += ft_puthex(u, format[index]);
						ft_resize_flags(tab);
						return (1);
					}
					else if (tab->_rep->precision <= tab->_rep->width)
					{
						c_precision = tab->_rep->precision;
						m = c_precision - len;
						if(tab->_rep->width < len)
						{
							tab->tl += ft_puthex(u, format[index]);
							ft_resize_flags(tab);
							return(1);
						}
						if (tab->_rep->precision > len)
						{
							if (tab->_rep->precision > tab->_rep->width)
							{
								while (m--)
									tab->tl += write(1, "0",1);
								tab->tl += ft_puthex(u, format[index]);
								m = tab->_rep->width - tab->_rep->precision;
								while (m--)
									tab->tl += write(1, " ",1);
								ft_resize_flags(tab);
								return (1);
							}
							else if (tab->_rep->precision <= tab->_rep->width)
							{
								c_precision = m;
								m = tab->_rep->width - tab->_rep->precision;
								while (m--)
									tab->tl += write(1, " ",1);
								while (c_precision--)
									tab->tl += write(1, "0",1);
								tab->tl += ft_puthex(u, format[index]);
								ft_resize_flags(tab);
								return (1);
							}
						}
						else if (tab->_rep->precision <= len)
						{
							if (tab->_rep->precision == 0 && u == 0)
							{
								m = tab->_rep->width;
								while (m--)
									tab->tl += write(1, " ",1);
								ft_resize_flags(tab);
								return (1);
							}
							else if (tab->_rep->width > len)
							{
								m = tab->_rep->width - len;
								while (m--)
									tab->tl += write(1, " ",1);
								tab->tl += ft_puthex(u, format[index]);
							}
							else
							{
								tab->tl += ft_puthex(u, format[index]);
								m = tab->_rep->width - len;
								while (m--)
									tab->tl += write(1, " ",1);
							}
							ft_resize_flags(tab);
							return (1);
						}
					}
					// 
				}
			}
			else if (tab->dash && !tab->width)
			{
				tab->tl += ft_puthex(u, format[index]);
			}
			else if (tab->dash && tab->width)
			{
				tab->tl += ft_puthex(u, format[index]);
				if (tab->_rep->width > len)
				{
					m = tab->_rep->width - len;
					while (m--)
						tab->tl += write(1, " ",1);
				}
			}
		}
		// zero width
		if (tab->zero && !tab->dash && tab->width )
		{
			u = va_arg(tab->args, unsigned int);
			len = ft_hex_len(u);
			if (!tab->pnt)

			{
				if (tab->_rep->width > len)
				{
					m = tab->_rep->width - len;
					while (m--)
						tab->tl += write(1, "0",1);
				}
				tab->tl += ft_puthex(u, format[index]);
			}
			else if (tab->pnt)
			{
				if (u == 0)
				{
					m = tab->_rep->width ;
					while (m--)
						tab->tl += write(1, " ",1);
				}
				else if (u != 0)
				{
					m = tab->_rep->width - len;
					while (m--)
						tab->tl += write(1, " ",1);
					tab->tl += ft_puthex(u, format[index]);
				}
		
			}
		}
		else if (tab->zero && !tab->dash && !tab->width)
		{
			u = va_arg(tab->args, unsigned int);
			tab->tl += ft_puthex(u, format[index]);
		}
	}
	ft_resize_flags(tab);
	return (1);
}
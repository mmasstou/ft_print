#include "../incs/ft_printf.h"

static int	hex_pnt_dash(t_printf *tab, const char *format, int index)
{
	unsigned int	u;
	int				len;
	int				m;
	int				n;
	int				copy_p;

	m = 0;
	n = 0;
	copy_p = 0;
	u = va_arg(tab->args, unsigned int);
	len = ft_hex_len(u);
	
	if (!tab->pnt && tab->dash)
	{
		if (!tab->width)
		{
			tab->tl += ft_puthex(u, format[index]);
			ft_resize_flags(tab);
			return (1);
		}
		else if (tab->width)
		{
			if (tab->_rep->width <= len)
				m = 0;
			else if (tab->_rep->width > len)
				m = tab->_rep->width - len;
			tab->tl += ft_puthex(u, format[index]);
			while (m--)
				tab->tl += write(1, " ",1);
			ft_resize_flags(tab);
			return (1);
		}
	}
	else if ((tab->pnt && !tab->dash))
	{
		if (!tab->precision)
		{

			if (!tab->width)
			{
				if (u == 0)
				{
					ft_resize_flags(tab);
					return (1);
				}
				tab->tl += ft_puthex(u, format[index]);
				ft_resize_flags(tab);
				return (1);
			}
			else if (tab->width)
			{
				m = tab->_rep->width;
				while (m--)
					tab->tl += write(1, " ",1);
				ft_resize_flags(tab);
				return (1);
			}
		}
		else if (tab->precision)
		{
			if (tab->_rep->precision == 0 && u == 0)
			{
				ft_resize_flags(tab);
				return (1);
			}
			else if (tab->_rep->precision == 0 && u != 0)
			{
				tab->tl += ft_puthex(u, format[index]);
				ft_resize_flags(tab);
				return (1);
			}
			else if (!tab->width)
			{
				if (tab->_rep->precision > len)
					m = tab->_rep->precision - len;
				else if (tab->_rep->precision <= len)
					m = 0;
				while (m--)
					tab->tl += write(1, "0",1);
				tab->tl += ft_puthex(u, format[index]);
				ft_resize_flags(tab);
				return (1);
			}
			else if (tab->width || (tab->dash && tab->_rep->precision <= tab->_rep->width))
			{
				if (tab->_rep->precision > tab->_rep->width)
				{
					m = 0;
					n = tab->_rep->precision - len;
				}
				else if (tab->_rep->precision < tab->_rep->width)
				{
					if (tab->_rep->precision > len)
					{
						n = tab->_rep->precision - len;
						m = tab->_rep->width - n;
					}
					else if (tab->_rep->precision <= len)
					{
						n = 0;
						m = tab->_rep->width - len;
					}
				}
				else if (tab->_rep->precision == tab->_rep->width)
				{
					m = 0;
					n = tab->_rep->precision - len;
				}
				while (m--)
					tab->tl += write(1, " ",1);
				while (n--)
					tab->tl += write(1, "0",1);
				tab->tl += ft_puthex(u, format[index]);
				ft_resize_flags(tab);
				return (1);
			}
		}
	}
	else if (tab->dash && tab->pnt)
	{
		if (!tab->precision)
		{
			if (!tab->width)
			{
				if (u != 0)
				{
					tab->tl += ft_puthex(u, format[index]);
					ft_resize_flags(tab);
					return (1);
				}
				ft_resize_flags(tab);
				return (1);
			}
			else if (tab->width)
			{
				
				if (tab->_rep->width <= len)
				{
					if (u == 0)
					{
						ft_resize_flags(tab);
						return (1);
					}
					tab->tl += ft_puthex(u, format[index]);
					ft_resize_flags(tab);
					return (1);
				}
				else if (tab->_rep->width > len)
				{
					if (u == 0)
					{
						m = tab->_rep->width ;
						while (m--)
							tab->tl += write(1, " ",1);
						ft_resize_flags(tab);
						return (1);
					}
					else if (u != 0)
					{
						tab->tl += ft_puthex(u, format[index]);
						m = tab->_rep->width - len ;
						while (m--)
							tab->tl += write(1, " ",1);
						ft_resize_flags(tab);
						return (1);
					}
				}
			}
		}
		else if (tab->precision)
		{
			if (!tab->width)
			{
				if (tab->_rep->precision <= len)
				{
					tab->tl += ft_puthex(u, format[index]);
					ft_resize_flags(tab);
					return (1);
				}
				else if (tab->_rep->precision > len)
				{
					n = tab->_rep->precision - len;
					while (n--)
						tab->tl += write(1, "0",1);
					tab->tl += ft_puthex(u, format[index]);
					ft_resize_flags(tab);
					return (1);
				}
			}
			else if (tab->width)
			{
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
					if (tab->_rep->precision > len)
					{
						if (tab->_rep->width <= len)
						{
							copy_p = tab->_rep->precision;
							n = copy_p -len;
							m = 0;
						}
						else if (tab->_rep->width > len)
						{
							copy_p = tab->_rep->precision;
							n = copy_p -len;
							m = tab->_rep->width - tab->_rep->precision;
						}
					}
					else if (tab->_rep->precision <= len)
					{
						if (tab->_rep->width <= len)
						{
							n = 0;
							m = 0;
						}
						else if (tab->_rep->width > len)
						{
							n = 0;
							m = tab->_rep->width - len;
						}
					}
					while (n--)
						tab->tl += write(1, "0",1);
					tab->tl += ft_puthex(u, format[index]);
					while (m--)
						tab->tl += write(1, " ",1);
					ft_resize_flags(tab);
					return (1);
				}
			}
		}
	}
	return(0);
}

static int	hex_pnt_zero(t_printf *tab, const char *format, int index)
{
	unsigned int	u;
	int				len;
	int				m;
	int				n;
	int				copy_p;

	m = 0;
	n = 0;
	copy_p = 0;
	u = va_arg(tab->args, unsigned int);
	len = ft_hex_len(u);
	if (!tab->pnt && tab->zero)
	{
		if (!tab->width)
		{
			tab->tl += ft_puthex(u, format[index]);
			ft_resize_flags(tab);
			return (1);
		}
		else if (tab->width)
		{
			if (tab->_rep->width <= len)
				n = 0;
			else if (tab->_rep->width > len)
				n = tab->_rep->width - len;
			while (n--)
				tab->tl += write(1, "0",1);
			tab->tl += ft_puthex(u, format[index]);
			ft_resize_flags(tab);
			return (1);
		}
	}
	else if (tab->pnt && !tab->zero)
	{
		if (!tab->precision)
		{

			if (!tab->width)
			{
				if (u == 0)
				{
					ft_resize_flags(tab);
					return (1);
				}
				tab->tl += ft_puthex(u, format[index]);
				ft_resize_flags(tab);
				return (1);
			}
			else if (tab->width)
			{
				m = tab->_rep->width;
				while (m--)
					tab->tl += write(1, " ",1);
				ft_resize_flags(tab);
				return (1);
			}
		}
		else if (tab->precision)
		{
			if (tab->_rep->precision == 0 && u == 0)
			{
				ft_resize_flags(tab);
				return (1);
			}
			else if (tab->_rep->precision == 0 && u != 0)
			{
				tab->tl += ft_puthex(u, format[index]);
				ft_resize_flags(tab);
				return (1);
			}
			else if (!tab->width)
			{
				if (tab->_rep->precision > len)
					m = tab->_rep->precision - len;
				else if (tab->_rep->precision <= len)
					m = 0;
				while (m--)
					tab->tl += write(1, "0",1);
				tab->tl += ft_puthex(u, format[index]);
				ft_resize_flags(tab);
				return (1);
			}
			else if (tab->width || (tab->dash && tab->_rep->precision <= tab->_rep->width))
			{
				if (tab->_rep->precision > tab->_rep->width)
				{
					m = 0;
					n = tab->_rep->precision - len;
				}
				else if (tab->_rep->precision < tab->_rep->width)
				{
					if (tab->_rep->precision > len)
					{
						n = tab->_rep->precision - len;
						m = tab->_rep->width - n;
					}
					else if (tab->_rep->precision <= len)
					{
						n = 0;
						m = tab->_rep->width - len;
					}
				}
				else if (tab->_rep->precision == tab->_rep->width)
				{
					m = 0;
					n = tab->_rep->precision - len;
				}
				while (m--)
					tab->tl += write(1, " ",1);
				while (n--)
					tab->tl += write(1, "0",1);
				tab->tl += ft_puthex(u, format[index]);
				ft_resize_flags(tab);
				return (1);
			}
		}
	}
	else if (tab->pnt && tab->zero)
	{
		if (tab->precision)
		{
			if (!tab->width)
			{
				if (tab->_rep->precision > len)
				{
					if (u != 0)
					n = tab->_rep->precision - len ;
					while (n--)
						tab->tl += write(1, "0",1);
					tab->tl += ft_puthex(u, format[index]);
				}
				else if (tab->_rep->precision <= len)
				{
					tab->tl += ft_puthex(u, format[index]);
				}

				ft_resize_flags(tab);
				return (1);
			}
			else if (tab->width)
			{
				if (tab->_rep->precision > tab->_rep->width)
				{
					if (tab->_rep->precision <= len)
					{
						m = 0;
						n = 0;
					}
					else if (tab->_rep->precision > len)
					{
						m = 0;
						n = tab->_rep->precision - len;
					}
				}
				else if (tab->_rep->precision < tab->_rep->width)
				{
					if (tab->_rep->precision > len)
					{
						copy_p = tab->_rep->precision;
						n = tab->_rep->precision - len;
						m = tab->_rep->width - copy_p;
					}
					else if (tab->_rep->precision <= len)
					{
						if (tab->_rep->precision == 0)
						{
							if (u == 0)
							{
								n = 0;
								m = tab->_rep->width  ;
							}
							else if (u != 0)
							{
								tab->tl += ft_puthex(u, format[index]);
							}
						}
						else if (tab->_rep->precision != 0)
						{
							n = 0;
							m = tab->_rep->width - len;
						}
					}
				}
				else if (tab->_rep->precision == tab->_rep->width)
				{
					m = 0;
					n = tab->_rep->precision - len;
				}
				while (m--)
					tab->tl += write(1, " ",1);
				while (n--)
					tab->tl += write(1, "0",1);
				if (tab->_rep->precision != 0)
					tab->tl += ft_puthex(u, format[index]);
				ft_resize_flags(tab);
				return (1);
			}
		}
		else if (!tab->precision)
		{
			if (!tab->width)
			{
				//ft_resize_flags(tab);
				tab->tl += ft_puthex(u, format[index]);
				return (1);
			}	
			else if (tab->width)
			{
				if (tab->_rep->width >= len && u == 0)
				{
					m = tab->_rep->width;
					while (m--)
						tab->tl += write(1, " ",1);
				}
				if (tab->_rep->width == len && u != 0)
					tab->tl += ft_puthex(u, format[index]);
				ft_resize_flags(tab);
				return (1);
			}
		}
	}
	return (0);
}

static int	hex_width(t_printf *tab, const char *format, int index)
{
	int 			len;
	unsigned int	u;
	int				m;

	m = 0;
	u = va_arg(tab->args, unsigned int);
	len = ft_hex_len(u);
	if (tab->_rep->width <= len)
		m = 0;
	else if (tab->_rep->width > len)
		m = tab->_rep->width - len;
	while (m--)
		tab->tl += write(1, " ",1);
	tab->tl += ft_puthex(u, format[index]);
	ft_resize_flags(tab);
	return (1);
}

int	hex_specifer(t_printf *tab, const char *format, int index)
{
	unsigned int	u;

	u = 0;
	if (!tab->is_flag)
	{
		u = va_arg(tab->args, unsigned int);
		tab->tl += ft_puthex(u, format[index]);
	}
	else if (tab->is_flag)
	{
		if (tab->shrap)
			shrap_flag(tab, format[index]);
		else if (!tab->pnt && !tab->dash && !tab->zero && tab->width)
			hex_width(tab, format, index);
		else if ((tab->pnt || tab->dash) &&  !tab->zero)
			hex_pnt_dash(tab, format, index);
		else if ((tab->pnt || tab->zero) && !tab->dash)
			hex_pnt_zero(tab, format, index);
	}
	return (0);
}
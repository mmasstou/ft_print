/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:56:05 by mmasstou          #+#    #+#             */
/*   Updated: 2021/12/02 12:29:28 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

static int	decimal_specifier(t_printf *tab, const char *format, int index)
{
	int	nbr;
	int	len;
	int m;
	int	n;
	int	c_pre;

	m = 0;
	n = 0;
	c_pre = 0;
	if (tab->space && !tab->plus)
		space_flag(tab, format[index]);
	else if (!tab->space && tab->plus)
		plus_flag(tab, format[index]);
	else if ((tab->zero || tab->pnt || tab->precision) && !tab->dash )
		ft_zero_flag(tab);
	else if ((tab->dash || tab->pnt || tab->width) && !tab->zero)
	{
		nbr = va_arg(tab->args, int);
		len = ft_nbrlen(nbr);
		if (!tab->pnt)
		{
			if (!tab->dash)
			{
				if (tab->width)
				{
					if (tab->_rep->width <= len)
					{
						if (nbr < 0)
							tab->tl += write(1, "-", 1);
						tab->tl += ft_putnbr(nbr);
						ft_resize_flags(tab);
					}
					else if (tab->_rep->width > len)
					{
						if (nbr < 0)
							m = tab->_rep->width - (len + 1);
						else 
							m = tab->_rep->width - len;
						while (m--)
							tab->tl += write (1, " ", 1);
						if (nbr < 0)
							tab->tl += write(1, "-", 1);
						tab->tl += ft_putnbr(nbr);
						ft_resize_flags(tab);
					}
				}
			}
			else if (tab->dash)
			{
				if (tab->width)
				{
					if (nbr < 0)
					{
						tab->tl += write(1, "-", 1);
						len += 1;
					}
					if (tab->_rep->width > len)
					{
						m = tab->_rep->width - len;
						tab->tl += ft_putnbr(nbr);
						while (m--)
							tab->tl += write (1, " ", 1);
					}
					else if (tab->_rep->width <= len)
						tab->tl += ft_putnbr(nbr);
				}
				else if (!tab->width)
				{
					if (nbr < 0)
						tab->tl += write(1, "-", 1);
					tab->tl += ft_putnbr(nbr);
					ft_resize_flags(tab);
				}
			}
		}
		else if (tab->pnt)
		{
			if (!tab->dash)
			{
				if (tab->precision)
				{
					if (tab->width)
					{
						if (tab->_rep->precision > tab->_rep->width)
						{
							if (nbr < 0)
							{
								tab->tl += write(1, "-", 1);
								if (tab->_rep->precision > ( len + 1))
								{
									n = tab->_rep->precision  - ( len + 1);
									while (n--)
										tab->tl += write (1, "0", 1);
									tab->tl += ft_putnbr(nbr);	
								}
								else if (tab->_rep->precision <= ( len + 1))
									tab->tl += ft_putnbr(nbr);
							}
							else if (nbr >= 0)
							{
								if (tab->_rep->precision > len)
								{
									n = tab->_rep->precision  -  len ;
									while (n--)
										tab->tl += write (1, "0", 1);
									tab->tl += ft_putnbr(nbr);	
								}
								else if (tab->_rep->precision <=  len)
									tab->tl += ft_putnbr(nbr);
							}
						}
						else if (tab->_rep->precision <= tab->_rep->width)
						{
							if (nbr >= 0)
							{
								if (tab->_rep->width <= len)
									tab->tl += ft_putnbr(nbr);
								else if (tab->_rep->width > len)
								{
									if (tab->_rep->precision <= len )
									{
										m = tab->_rep->width - len;
										while (m--)
											tab->tl += write (1, " ", 1);
										tab->tl += ft_putnbr(nbr);
									
									}
									else if (tab->_rep->precision > len )
									{
										c_pre = tab->_rep->precision;
										m = tab->_rep->width - tab->_rep->precision;
										n = c_pre - len;
										while (m--)
											tab->tl += write (1, " ", 1);
										while (n--)
											tab->tl += write (1, "0", 1);
										tab->tl += ft_putnbr(nbr);
									}
								}
							}
							else if (nbr < 0)
							{
								tab->tl += write (1, "-", 1);
								if (tab->_rep->width <= (len + 1))
									tab->tl += ft_putnbr(nbr);
								else if (tab->_rep->width > (len + 1))
								{
									if (tab->_rep->precision <= (len + 1) )
									{
										m = tab->_rep->width - (len + 1);
										while (m--)
											tab->tl += write (1, " ", 1);
										tab->tl += ft_putnbr(nbr);
									
									}
									else if (tab->_rep->precision > (len + 1) )
									{
										c_pre = tab->_rep->precision;
										m = tab->_rep->width - tab->_rep->precision;
										n = c_pre - (len + 1);
										while (m--)
											tab->tl += write (1, " ", 1);
										while (n--)
											tab->tl += write (1, "0", 1);
										tab->tl += ft_putnbr(nbr);
									}
								}
							}
						}
					}
					else if (!tab->width)
					{

					}
				}
				else if (!tab->precision)
				{

				}
			}
			else if (tab->dash)
			{
				if (tab->precision)
				{
					if (tab->width)
					{
						if (nbr < 0)
						{
							tab->tl += write(1, "-", 1);
							//len += 1 ;
						}
						if (tab->_rep->precision > tab->_rep->width)
						{
							if (tab->_rep->precision > len)
							{
								n = tab->_rep->precision - len;
								while (n--)
									tab->tl += write(1, "0", 1);
								tab->tl += ft_putnbr(nbr);
							}
							else if (tab->_rep->precision <= len)
								tab->tl += ft_putnbr(nbr);
						}
						else if (tab->_rep->precision < tab->_rep->width)
						{
							if (tab->_rep->width > len)
							{
								if (tab->_rep->precision > len)
								{
									c_pre = tab->_rep->precision;
									if (nbr < 0)
										tab->_rep->precision += 1;
									n = c_pre - len;
									m = tab->_rep->width - tab->_rep->precision;
									while (n--)
										tab->tl += write(1, "0", 1);
									tab->tl += ft_putnbr(nbr);
									while (m--)
										tab->tl += write(1, " ", 1);
								}
								else if (tab->_rep->precision <= len)
								{
									if (nbr < 0)
										len += 1;
									m = tab->_rep->width -len ;
									tab->tl += ft_putnbr(nbr);
									while (m--)
										tab->tl += write(1, " ", 1);
								}
							}
							else if (tab->_rep->width <= len)
								tab->tl += ft_putnbr(nbr);
						}
						else if (tab->_rep->precision == tab->_rep->width)
						{
							
							n = tab->_rep->precision - len;
							while (n--)
								tab->tl += write(1, "0", 1);
							tab->tl += ft_putnbr(nbr);
						}
					}
					else if (!tab->width)
					{
						if (nbr < 0)
						{
							tab->tl += write(1, "-", 1);
							//len  += 1;
						}
						if (tab->_rep->precision == 0 && nbr == 0)
						{
							return (1);
						}
						else if (tab->_rep->precision > len)
						{
							n = tab->_rep->precision - len;
							while (n--)
								tab->tl += write(1, "0", 1);
							tab->tl += ft_putnbr(nbr);
						}
						else if (tab->_rep->precision <= len )
							tab->tl += ft_putnbr(nbr);
					}
				}
				else if (!tab->precision)
				{
					if (tab->width)
					{
						if (nbr < 0)
						{
							tab->tl += write(1, "-", 1);
							len += 1;
						}
						if (tab->_rep->width > len)
						{
							m = tab->_rep->width;
							//tab->tl += ft_putnbr(nbr);
							while (m--)
								tab->tl += write(1, " ", 1);
						}
						else if (tab->_rep->width <= len)
							tab->tl += ft_putnbr(nbr);
					}
					else if (!tab->width){}
				}
			}
		}
	}
	else
	{
		nbr = va_arg(tab->args, int);
		if (nbr < 0)
			tab->tl += write(1, "-", 1);
		tab->tl += ft_putnbr(nbr);
	}
	ft_resize_flags(tab);
	return (0);
}

static void	character_specifier(t_printf *tab, const char *format, int index)
{
	char	str;

	if (!tab->dash && !tab->width)
		ft_print_char(tab);
	else if (!tab->dash && tab->width)
	{
		str = va_arg(tab->args, int);
		tab->_rep->width--;
		while (tab->_rep->width--)
			tab->tl += write(1, " ", 1);
		tab->tl += ft_putchar(str);
		tab->width = 0;
		tab->_rep->width = 0;
	}
	else
		dash_flag(tab, format, index, "no");
}

void	ft_specifier(t_printf *tab, const char *format, int index)
{
	if (format[index] == 'c')
		character_specifier(tab, format, index);
	else if (format[index] == 'd' || format[index] == 'i')
		decimal_specifier(tab, format, index);
	else if (format[index] == 's')
		string_specifier(tab);
	else if (format[index] == 'p')
	{
		if (tab->is_flag)
			p_flag(tab);
		else
			ft_print_adress(tab);
	}
	else if (format[index] == 'u')
	{
		if (tab->is_flag)
			u_flags(tab);
		else
			ft_print_unsigned(tab);
	}
	else if (format[index] == 'X' || format[index] == 'x')
		hex_specifer(tab, format, index);
	else if (format[index] == '%')
		tab->tl += ft_putpercent();
}

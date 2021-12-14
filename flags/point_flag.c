/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 03:19:04 by mmasstou          #+#    #+#             */
/*   Updated: 2021/12/11 03:24:02 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

static void	point_flag_string(t_printf *tab, char *str, int len)
{
	int	m;

	m = 0;
	if (!tab->dash && !tab->width)
		ft_print_str(tab, str);
	else if (tab->dash && !tab->width)
		ft_print_str(tab, str);
	else if (!tab->dash && tab->width)
	{
		if (str)
			m = len - ft_strlen(str);
		while (m--)
			tab->tl += write(1, " ", 1);
		ft_print_str(tab, str);
	}
	else if (tab->dash && tab->width)
	{
		m = len - ft_strlen(str);
		ft_print_str(tab, str);
		while (m--)
			tab->tl += write(1, " ", 1);
	}
}

int	point_flag(t_printf *tab, const char *format, int index, char *str)
{
	int	len;
	int m;
	int nbrl;

	len = 0;
	nbrl = 0;
	if (format[index] == 's')
	{
		if (str == NULL)
			len = 6;
		else if (str != NULL)
			len = tab->_rep->width;
		point_flag_string(tab, str, len);
		ft_resize_flags(tab);
	}
	if (format[index] == 'd')
	{
		// no dash
		len = va_arg(tab->args, int);
		nbrl = ft_nbrlen(len);
		if (tab->_rep->width)
		{
			if (tab->_rep->precision > nbrl)
			{
				if (len < 0)
				{
					len *= -1;
					tab->tl += write(1, "-", 1);
					nbrl -= 1;
				}
				m = tab->_rep->precision - nbrl;
				while (m--)
					tab->tl += write(1, "0",1);
				tab->tl += ft_putnbr(len);
			}
			else 
				tab->tl += ft_putnbr(len);
		}
		else if (!tab->_rep->width)
		{
			if (tab->_rep->precision > nbrl)
			{
				if (len < 0)
				{
					len *= -1;
					tab->tl += write(1, "-", 1);
					nbrl -= 1;
				}
				m = tab->_rep->precision - nbrl;
				while (m--)
					tab->tl += write(1, "0",1);
				tab->tl += ft_putnbr(len);
			}
		}
	}
	return (1);
}

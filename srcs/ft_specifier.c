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

	if (tab->space && !tab->plus)
		space_flag(tab, format[index]);
	else if (!tab->space && tab->plus)
		plus_flag(tab, format[index]);
	else if ((tab->zero || tab->pnt || tab->precision) && !tab->dash)
		ft_zero_flag(tab);
	else if ((tab->dash || tab->pnt || tab->width) && !tab->zero)
	{
		nbr = va_arg(tab->args, int);
		if (!tab->pnt)
			d_spe_no_pnt(tab, nbr);
		else if (tab->pnt)
			d_spe_pnt(tab, nbr);
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

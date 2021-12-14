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

static void	decimal_specifier(t_printf *tab, const char *format, int index)
{
	if (tab->space && !tab->plus)
		space_flag(tab, format[index]);
	else if (!tab->space && tab->plus)
		plus_flag(tab, format[index]);
	else if (tab->zero)
		ft_zero_flag(tab);
	else
		tab->tl += ft_putnbr(va_arg(tab->args, int));
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
	unsigned int	u;

	if (format[index] == 'c')
		character_specifier(tab, format, index);
	else if (format[index] == 'd' || format[index] == 'i')
		decimal_specifier(tab, format, index);
	else if (format[index] == 's')
		string_specifier(tab);
	else if (format[index] == 'p')
		ft_print_adress(tab);
	else if (format[index] == 'u')
		ft_print_unsigned(tab);
	else if (format[index] == 'X' || format[index] == 'x')
	{
		if (tab->is_flag)
			x_flag(tab, format, index);
		else
		{
			u = va_arg(tab->args, unsigned int);
			tab->tl += ft_puthex(u, format[index]);
		}
	}
	else if (format[index] == '%')
		tab->tl += ft_putpercent();
}

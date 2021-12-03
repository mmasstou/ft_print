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

static int	update_index(t_printf *tab, int index)
{
	if (tab->is_flag)
	{
		if (tab->_rep->space)
			index += tab->_rep->space;
		if (tab->_rep->plus)
			index += tab->_rep->plus;
		if (tab->_rep->shrap)
			index += tab->_rep->shrap;
		if (tab->_rep->dash)
			index += tab->_rep->dash;
		return (index);
	}
	else
		return (index);
}

static void	d_specifier(t_printf *tab, const char *format, int index)
{
	if (tab->space && !tab->plus)
		space_flag(tab, format[index]);
	else if (!tab->space && tab->plus)
		plus_flag(tab, format[index]);
	else if (!tab->space && !tab->plus)
		tab->tl += ft_putnbr(va_arg(tab->args, int));
}
static void	c_specifier(t_printf *tab, const char *format, int index)
{
	char	a;

	if (!tab->dash && !tab->width)
		ft_print_char(tab);
	else if (!tab->dash && tab->width)
	{
		a = va_arg(tab->args, int);
		ft_right_cs(tab, format, index);
		tab->tl += write(1, &a, 1);
		tab->width = 0;
		tab->_rep->width = 0;
	}
	else
		dash_flag(tab, format, index);
		
}
void	ft_specifier(t_printf *tab, const char *format, int index)
{
	unsigned int	u;

	update_index(tab, index);
	flags_check(tab, format, index);
	if (format[index] == 'c')
		c_specifier(tab, format, index);
	else if (format[index] == 'd' || format[index] == 'i')
		d_specifier(tab, format, index);
	else if (format[index] == 's')
		ft_print_str(tab);
	else if (format[index] == 'p')
		ft_print_adress(tab);
	else if (format[index] == 'u')
		ft_print_unsigned(tab);
	else if (format[index] == 'X' || format[index] == 'x')
	{
		if (tab->shrap)
			shrap_flag(tab, format[index]);
		else
		{
			u = va_arg(tab->args, unsigned int);
			tab->tl += ft_puthex(u, format[index]);
		}
	}
	else if (format[index] == '%')
		return ;
}

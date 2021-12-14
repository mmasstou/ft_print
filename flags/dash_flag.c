/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dash_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 03:02:37 by mmasstou          #+#    #+#             */
/*   Updated: 2021/12/11 03:05:13 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

static void	dash_flag_char(t_printf *tab)
{
	char	a;

	a = va_arg(tab->args, int);
	if (tab->dash && tab->width)
	{
		tab->tl += write(1, &a, 1);
		while (--tab->_rep->width)
			tab->tl += write(1, " ", 1);
	}
	if (tab->dash && !tab->width)
		tab->tl += write(1, &a, 1);
}

int	dash_flag(t_printf *tab, const char *format, int index, char *str)
{
	if (format[index] == 'c')
		dash_flag_char(tab);
	if (format[index] == 's')
	{
		if (str == NULL)
		{
			ft_print_str(tab, str);
			return (1);
		}
		else
		{
			if (tab->dash && tab->width)
			{
				tab->tl += ft_putstr(str);
				tab->_rep->width -= ft_strlen(str);
				while (tab->_rep->width--)
					tab->tl += write(1, " ", 1);
			}
			else if (tab->dash && !tab->width)
				tab->tl += ft_putstr(str);
		}
	}
	ft_resize_flags(tab);
	return (1);
}

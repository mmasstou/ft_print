/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 22:09:39 by mmasstou          #+#    #+#             */
/*   Updated: 2021/12/11 22:09:43 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

static void	string_specifier_npnt(t_printf *tab, char *str)
{
	if (tab->width && !tab->dash)
	{
		if (tab->_rep->width > ft_strlen(str))
			tab->_rep->width -= ft_strlen(str);
		else
			tab->_rep->width = 0;
		while (tab->_rep->width--)
			tab->tl += write(1, " ", 1);
	}
	ft_print_str(tab, str);
	if (tab->width && tab->dash)
	{
		if (tab->_rep->width > ft_strlen(str))
			tab->_rep->width -= ft_strlen(str);
		else
			tab->_rep->width = 0;
		while (tab->_rep->width--)
			tab->tl += write(1, " ", 1);
	}
	ft_resize_flags(tab);
}

static void	string_specifier_pnt_nprec(t_printf *tab, char *str)
{
	if (tab->width && !tab->dash)
	{
		if (tab->_rep->width > 0)
			tab->_rep->width -= 0;
		else
			tab->_rep->width = 0;
		while (tab->_rep->width--)
			tab->tl += write(1, " ", 1);
	}
	ft_print_str(tab, "");
	if (tab->width && tab->dash)
	{
		if (tab->_rep->width > ft_strlen(str))
			tab->_rep->width -= ft_strlen(str);
		else
			tab->_rep->width = 0;
		while (tab->_rep->width--)
			tab->tl += write(1, " ", 1);
	}
	ft_resize_flags(tab);
}

static void	string_specifier_pnt_prec(t_printf *tab, char *str)
{
	str = ft_substr(str, 0, tab->_rep->precision);
	if (tab->width && !tab->dash)
	{
		if (tab->_rep->precision > ft_strlen(str))
			tab->_rep->width -= ft_strlen(str);
		else
			tab->_rep->width -= tab->_rep->precision;
		while (tab->_rep->width--)
			tab->tl += write(1, " ", 1);
	}
	ft_print_str(tab, str);
	if (tab->width && tab->dash)
	{
		if (tab->_rep->precision > ft_strlen(str))
			tab->_rep->width -= ft_strlen(str);
		else
			tab->_rep->width -= tab->_rep->precision;
		while (tab->_rep->width--)
			tab->tl += write(1, " ", 1);
	}
	free(str);
}

int	string_specifier(t_printf *tab)
{
	char	*str;

	str = va_arg(tab->args, char *);
	if (str == NULL)
		str = "(null)";
	if (!tab->pnt)
		string_specifier_npnt(tab, str);
	else if (tab->pnt)
	{
		if (!tab->precision)
			string_specifier_pnt_nprec(tab, str);
		else if (tab->precision)
			string_specifier_pnt_prec(tab, str);
		ft_resize_flags(tab);
	}
	return (1);
}

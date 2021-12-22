/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_specifer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:02:54 by mmasstou          #+#    #+#             */
/*   Updated: 2021/12/21 18:02:57 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

static int	hex_no_p_d(t_printf *t, const char *f, int x, unsigned int u)
{
	int	len;
	int	m;

	m = 0;
	len = ft_hex_len(u);
	if (!t->width)
		t->tl += ft_puthex(u, f[x]);
	else if (t->width)
	{
		if (t->_rep->width <= len)
			m = 0;
		else if (t->_rep->width > len)
			m = t->_rep->width - len;
		t->tl += ft_puthex(u, f[x]);
		while (m--)
			t->tl += write(1, " ", 1);
	}
	ft_resize_flags(t);
	return (0);
}

static int	hex_pnt_dash(t_printf *tab, const char *format, int index)
{
	unsigned int	u;
	int				len;

	u = va_arg(tab->args, unsigned int);
	len = ft_hex_len(u);
	if (!tab->pnt && tab->dash)
		hex_no_p_d(tab, format, index, u);
	else if (tab->pnt && !tab->dash)
	{
		if (!tab->precision && !tab->width)
		{
			if (u != 0)
				tab->tl += ft_puthex(u, format[index]);
		}
		else if (!tab->precision && tab->width)
		{
			while (tab->_rep->width--)
				tab->tl += write(1, " ", 1);
		}
		else if (tab->precision)
			h_p(tab, format, index, u);
	}
	else if (tab->dash && tab->pnt)
		hex_dash_pnt(tab, format, index, u);
	return (ft_resize_flags(tab), 1);
}

static int	hex_pnt_zero(t_printf *tab, const char *format, int index)
{
	unsigned int	u;

	u = va_arg(tab->args, unsigned int);
	if (!tab->pnt && tab->zero)
		h_no_p_z_u(tab, format, index, u);
	else if (tab->pnt && !tab->zero)
		h_p_no_z_u(tab, format, index, u);
	else if (tab->pnt && tab->zero)
		h_p_z_u(tab, format, index, u);
	return (0);
}

static int	hex_width(t_printf *tab, const char *format, int index)
{
	int				len;
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
		tab->tl += write(1, " ", 1);
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
		else if ((tab->pnt || tab->dash) && !tab->zero)
			hex_pnt_dash(tab, format, index);
		else if ((tab->pnt || tab->zero) && !tab->dash)
			hex_pnt_zero(tab, format, index);
	}
	return (0);
}

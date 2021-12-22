/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_specifer_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 21:22:02 by mmasstou          #+#    #+#             */
/*   Updated: 2021/12/18 21:22:04 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

static int	else_fun(t_printf *t, const char *f, int x, unsigned int u)
{
	int	i[3];

	i[1] = 0;
	i[2] = 0;
	i[0] = ft_hex_len(u);
	if (t->_rep->precision > t->_rep->width)
		i[2] = t->_rep->precision - i[0];
	else if (t->_rep->precision < t->_rep->width)
	{
		if (t->_rep->precision > i[0])
		{
			i[2] = t->_rep->precision - i[0];
			i[1] = t->_rep->width - i[2];
		}
		else if (t->_rep->precision <= i[0])
			i[1] = t->_rep->width - i[0];
	}
	else if (t->_rep->precision == t->_rep->width)
		i[2] = t->_rep->precision - i[0];
	while (i[1]--)
		t->tl += write(1, " ", 1);
	while (i[2]--)
		t->tl += write(1, "0", 1);
	t->tl += ft_puthex(u, f[x]);
	return (ft_resize_flags(t), 1);
}

int	h_p(t_printf *tab, const char *format, int index, unsigned int u)
{
	int	len;
	int	m;

	m = 0;
	len = ft_hex_len(u);
	if (tab->_rep->precision == 0 && u == 0)
		return (ft_resize_flags(tab), 1);
	else if (tab->_rep->precision == 0 && u != 0)
		tab->tl += ft_puthex(u, format[index]);
	else if (!tab->width)
	{
		if (tab->_rep->precision > len)
			m = tab->_rep->precision - len;
		else if (tab->_rep->precision <= len)
			m = 0;
		while (m--)
			tab->tl += write(1, "0", 1);
		tab->tl += ft_puthex(u, format[index]);
	}
	else if (tab->width || (tab->dash
			&& tab->_rep->precision <= tab->_rep->width))
		else_fun(tab, format, index, u);
	ft_resize_flags(tab);
	return (1);
}

static int	hex_pre_wid(t_printf *t, const char *f, int x, unsigned int u)
{
	int	i[4];

	i[2] = 0;
	i[0] = ft_hex_len(u);
	if (t->_rep->precision > i[0])
	{
		if (t->_rep->width <= i[0])
			i[2] = t->_rep->precision - i[0];
		else if (t->_rep->width > i[0])
		{
			i[3] = t->_rep->precision;
			i[2] = i[3] - i[0];
			i[1] = t->_rep->width - t->_rep->precision;
		}
	}
	else if (t->_rep->precision <= i[0])
		if (t->_rep->width > i[0])
			i[1] = t->_rep->width - i[0];
	while (i[2]--)
		t->tl += write(1, "0", 1);
	t->tl += ft_puthex(u, f[x]);
	while (i[1]--)
		t->tl += write(1, " ", 1);
	return (0);
}

static void	hfghhkj(t_printf *t, const char *f, int x, unsigned int u)
{
	int	len;

	len = ft_hex_len(u);
	if (!t->precision && t->width && t->_rep->width > len)
	{
		if (u != 0)
		{
			t->tl += ft_puthex(u, f[x]);
			t->_rep->width -= len ;
		}
		while (t->_rep->width--)
			t->tl += write(1, " ", 1);
	}
	else if (t->precision && !t->width)
	{
		if (t->_rep->precision <= len)
			t->tl += ft_puthex(u, f[x]);
		else if (t->_rep->precision > len)
		{
			t->_rep->precision -= len;
			while (t->_rep->precision--)
				t->tl += write(1, "0", 1);
			t->tl += ft_puthex(u, f[x]);
		}
	}
}

int	hex_dash_pnt(t_printf *t, const char *f, int x, unsigned int u)
{
	int	len;

	len = ft_hex_len(u);
	if ((!t->precision && !t->width) || (!t->precision
			&& t->width && t->_rep->width <= len))
	{
		if (u != 0)
			t->tl += ft_puthex(u, f[x]);
	}
	else if ((!t->precision && t->width) || (t->precision && !t->width))
		hfghhkj(t, f, x, u);
	else if (t->precision && t->width && t->_rep->precision > t->_rep->width)
	{
		if (t->_rep->precision > len)
		{
			t->_rep->precision -= len;
			while (t->_rep->precision--)
				t->tl += write(1, "0", 1);
		}
		t->tl += ft_puthex(u, f[x]);
	}
	else if (t->precision && t->width && t->_rep->precision <= t->_rep->width)
		hex_pre_wid(t, f, x, u);
	return (ft_resize_flags(t), 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_pnt_no_zero_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:29:01 by mmasstou          #+#    #+#             */
/*   Updated: 2021/12/22 18:29:04 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

void	w_or_d(t_printf *t, const char *f, int i, unsigned int u)
{
	int	m;
	int	n;
	int	len;

	m = 0;
	len = ft_hex_len(u);
	if (t->_rep->precision > t->_rep->width)
		n = t->_rep->precision - len;
	else if (t->_rep->precision < t->_rep->width)
	{
		if (t->_rep->precision > len)
		{
			n = t->_rep->precision - len;
			m = t->_rep->width - n;
		}
		else if (t->_rep->precision <= len)
			m = t->_rep->width - len;
	}
	else if (t->_rep->precision == t->_rep->width)
		n = t->_rep->precision - len;
	while (m--)
		t->tl += write(1, " ", 1);
	while (n--)
		t->tl += write(1, "0", 1);
	t->tl += ft_puthex(u, f[i]);
}

void	prec(t_printf *t, const char *f, int i, unsigned int u)
{
	int	m;
	int	len;

	m = 0;
	len = ft_hex_len(u);
	if (t->_rep->precision == 0 && u != 0)
		t->tl += ft_puthex(u, f[i]);
	else if (!t->width)
	{
		if (t->_rep->precision > len)
			m = t->_rep->precision - len;
		while (m--)
			t->tl += write(1, "0", 1);
		t->tl += ft_puthex(u, f[i]);
		ft_resize_flags(t);
	}
	else if (t->width || (t->dash && t->_rep->precision <= t->_rep->width))
		w_or_d(t, f, i, u);
	ft_resize_flags(t);
}

void	h_p_no_z_u(t_printf *t, const char *f, int i, unsigned int u)
{
	int	m;
	int	len;

	m = 0;
	len = ft_hex_len(u);
	if (!t->precision && !t->width)
		t->tl += ft_puthex(u, f[i]);
	else if (!t->precision && t->width)
	{
		m = t->_rep->width;
		while (m--)
			t->tl += write(1, " ", 1);
	}
	else if (t->precision)
		prec(t, f, i, u);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 12:36:31 by mmasstou          #+#    #+#             */
/*   Updated: 2021/12/18 12:36:34 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

static int	zero_pnt_precision_no_dash(t_printf *tab, unsigned int nbr, int len)
{
	int	n;

	if (tab->precision && tab->width)
	{
		if (tab->_rep->precision > tab->_rep->width)
		{
			n = tab->_rep->precision - len;
			while (n--)
				tab->tl += write(1, "0", 1);
			tab->tl += ft_putunsigned(nbr);
		}
		else if (tab->_rep->precision <= tab->_rep->width)
			z_pnt_pr_no_d_pw(tab, nbr, len);
	}
	else if (tab->precision && !tab->width)
		precision_no_width(tab, nbr, len);
	else if (!tab->precision && (!tab->width || tab->width))
		no_precision_a_w_a_no_w(tab, nbr, len);
	return (0);
}

static int	zero_no_pnt_pr_no_dash(t_printf *tab, unsigned int nbr, int len)
{
	int	m;

	if (!tab->width)
	{
		tab->tl += ft_putunsigned(nbr);
		ft_resize_flags(tab);
		return (1);
	}
	else if (tab->width)
	{
		if (tab->_rep->width > len)
		{
			m = tab->_rep->width - len;
			while (m--)
				tab->tl += write(1, "0", 1);
			tab->tl += ft_putunsigned(nbr);
		}
		else if (tab->_rep->width <= len)
			tab->tl += ft_putunsigned(nbr);
	}
	ft_resize_flags(tab);
	return (1);
}

static int	dash_pnt_width_no_zero(t_printf *tab, unsigned int nbr, int len)
{
	int	m;

	if (!tab->dash && tab->precision && tab->width)
		no_dash_precision_width(tab, nbr, len);
	else if (tab->dash && tab->precision)
		dash_precision(tab, nbr, len);
	if (tab->dash && !tab->precision && tab->width)
	{
		if (tab->_rep->width > len)
		{
			m = tab->_rep->width;
			while (m--)
				tab->tl += write(1, " ", 1);
		}
		else if (tab->_rep->width <= len)
			tab->tl += ft_putunsigned(nbr);
	}
	return (0);
}

static int	da_no_pn_wi_no_ze(t_printf *tab, unsigned int nbr, int len, int m)
{
	if (!tab->dash)
	{
		if (tab->width && tab->_rep->width > len)
		{
			m = tab->_rep->width - len;
			while (m--)
				tab->tl += write (1, " ", 1);
		}
		tab->tl += ft_putunsigned(nbr);
	}
	else if (tab->dash)
	{
		if (tab->width && tab->_rep->width > len)
		{
			m = tab->_rep->width - len;
			tab->tl += ft_putunsigned(nbr);
			while (m--)
				tab->tl += write (1, " ", 1);
		}
		else if ((tab->width && tab->_rep->width <= len) || !tab->width)
			tab->tl += ft_putunsigned(nbr);
	}
	ft_resize_flags(tab);
	return (0);
}

int	u_flags(t_printf *tab)
{
	unsigned int	nbr;
	int				len;
	int				m;

	m = 0;
	nbr = va_arg(tab->args, unsigned int);
	len = ft_unbrlen(nbr);
	if ((tab->zero || tab->pnt || tab->precision) && !tab->dash)
	{
		if (!tab->pnt)
			zero_no_pnt_pr_no_dash(tab, nbr, len);
		else if (tab->pnt)
			zero_pnt_precision_no_dash(tab, nbr, len);
	}
	else if ((tab->dash || tab->pnt || tab->width) && !tab->zero)
	{
		if (!tab->pnt)
			da_no_pn_wi_no_ze(tab, nbr, len, m);
		else if (tab->pnt)
			dash_pnt_width_no_zero(tab, nbr, len);
	}
	return (ft_resize_flags(tab), 1);
}

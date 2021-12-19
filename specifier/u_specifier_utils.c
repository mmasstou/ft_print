/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_specifier_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 12:01:07 by mmasstou          #+#    #+#             */
/*   Updated: 2021/12/18 12:01:12 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

static int	precision_g_width_a_len(t_printf *tab, unsigned int nbr, int len)
{
	int	m;

	if (tab->_rep->width > len && nbr != 0)
	{
		m = tab->_rep->width - len ;
		while (m--)
			tab->tl += write(1, " ", 1);
		tab->tl += ft_putunsigned(nbr);
	}
	else if (tab->_rep->width > len && nbr == 0)
		while (tab->_rep->width--)
			tab->tl += write(1, " ", 1);
	else if (tab->_rep->width <= len && nbr != 0)
		tab->tl += ft_putunsigned(nbr);
	else if (tab->_rep->width <= len && nbr == 0)
		while (tab->_rep->width--)
			tab->tl += write(1, " ", 1);
	return (1);
}

static int	precision_l_width_a_len(t_printf *tab, unsigned int nbr, int len)
{
	int	n;
	int	m;
	int	cp_p;

	cp_p = tab->_rep->precision;
	n = cp_p - len;
	m = tab->_rep->width - tab->_rep->precision;
	while (m--)
		tab->tl += write(1, " ", 1);
	while (n--)
		tab->tl += write(1, "0", 1);
	tab->tl += ft_putunsigned(nbr);
	return (0);
}

int	zero_pnt_precision_no_dashpw(t_printf *tab, unsigned int nbr, int len)
{
	int	n;

	if (tab->_rep->precision < tab->_rep->width && tab->_rep->precision > len)
		precision_l_width_a_len(tab, nbr, len);
	else if (tab->_rep->precision < tab->_rep->width
		&& tab->_rep->precision < len)
		precision_g_width_a_len(tab, nbr, len);
	else if (tab->_rep->precision < tab->_rep->width
		&& tab->_rep->precision == len)
		tab->tl += ft_putunsigned(nbr);
	else if (tab->_rep->precision == tab->_rep->width)
	{
		n = tab->_rep->precision - len ;
		while (n--)
			tab->tl += write(1, "0", 1);
		tab->tl += ft_putunsigned(nbr);
	}
	return (1);
}

int	precision_no_width(t_printf *tab, unsigned int nbr, int len)
{
	int	n;

	if (tab->_rep->precision > len)
	{
		n = tab->_rep->precision - len;
		while (n--)
			tab->tl += write(1, "0", 1);
		tab->tl += ft_putunsigned(nbr);
	}
	else if (tab->_rep->precision <= len)
	{
		if (nbr == 0 && tab->_rep->precision == 0)
			return (ft_resize_flags(tab), 1);
		else if (nbr == 0 && tab->_rep->precision != 0)
		{
			tab->tl += ft_putunsigned(nbr);
			return (ft_resize_flags(tab), 1);
		}
		else if (nbr < 0)
			tab->tl += write(1, "-", 1);
		tab->tl += ft_putunsigned(nbr);
	}
	return (0);
}

int	no_precision_a_w_a_no_w(t_printf *tab, unsigned int nbr, int len)
{
	int	m;

	len += 0;
	if (!tab->width)
	{
		if (nbr == 0)
			return (ft_resize_flags(tab), 1);
		tab->tl += ft_putunsigned(nbr);
	}
	else if (tab->width)
	{
		if (nbr != 0)
			tab->tl += ft_putunsigned(nbr);
		else
		{
			m = tab->_rep->width;
			while (m--)
				tab->tl += write(1, " ", 1);
		}
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_specifier_utils1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:42:15 by mmasstou          #+#    #+#             */
/*   Updated: 2021/12/18 13:42:17 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

static int	pre_g_w(t_printf *tab, unsigned int nbr, int len)
{
	int	n;
	int	cp_p;

	if (tab->_rep->width > len)
	{
		if (tab->_rep->precision <= len)
		{
			tab->_rep->width -= len;
			while (tab->_rep->width--)
				tab->tl += write (1, " ", 1);
		}
		else if (tab->_rep->precision > len)
		{
			cp_p = tab->_rep->precision;
			tab->_rep->width -= tab->_rep->precision;
			n = cp_p - len;
			while (tab->_rep->width--)
				tab->tl += write (1, " ", 1);
			while (n--)
				tab->tl += write (1, "0", 1);
		}
		tab->tl += ft_putunsigned(nbr);
	}
	return (0);
}

int	no_dash_precision_width(t_printf *tab, unsigned int nbr, int len)
{
	if (tab->_rep->precision > tab->_rep->width)
	{
		if (tab->_rep->precision > len)
		{
			tab->_rep->precision -= len;
			while (tab->_rep->precision--)
				tab->tl += write (1, "0", 1);
		}
		tab->tl += ft_putunsigned(nbr);
	}
	else if (tab->_rep->precision <= tab->_rep->width)
		pre_g_w(tab, nbr, len);
	return (0);
}

static void	w_and_pr_l_w(t_printf *tab, unsigned int nbr, int len)
{
	int	n;
	int	m;

	m = 0;
	if (tab->width && tab->_rep->precision < tab->_rep->width)
	{
		if (tab->_rep->width > len)
		{
			if (tab->_rep->precision > len)
			{
				m = tab->_rep->precision;
				n = m - len;
				m = tab->_rep->width - tab->_rep->precision;
				while (n--)
					tab->tl += write(1, "0", 1);
			}
			else if (tab->_rep->precision <= len)
				m = tab->_rep->width - len;
			tab->tl += ft_putunsigned(nbr);
			while (m--)
				tab->tl += write(1, " ", 1);
		}
		else if (tab->_rep->width <= len)
			tab->tl += ft_putunsigned(nbr);
	}
}

int	dash_precision(t_printf *tab, unsigned int nbr, int len)
{
	w_and_pr_l_w(tab, nbr, len);
	if (tab->width && tab->_rep->precision > tab->_rep->width)
	{
		if (tab->_rep->precision > len)
		{
			tab->_rep->precision -= len;
			while (tab->_rep->precision--)
				tab->tl += write(1, "0", 1);
		}
		tab->tl += ft_putunsigned(nbr);
	}
	else if ((tab->width && tab->_rep->precision == tab->_rep->width)
		|| (!tab->width && tab->_rep->precision > len))
	{
		tab->_rep->precision -= len;
		while (tab->_rep->precision--)
			tab->tl += write(1, "0", 1);
		tab->tl += ft_putunsigned(nbr);
	}
	else if (!tab->width && tab->_rep->precision <= len)
		tab->tl += ft_putunsigned(nbr);
	return (0);
}

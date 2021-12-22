/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_flag_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 11:20:55 by mmasstou          #+#    #+#             */
/*   Updated: 2021/12/21 11:20:57 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

static void	precision_g_len(t_printf *tab, int nbr, int len)
{
	if ((nbr >= 0 && tab->_rep->precision < len) && tab->_rep->width > len)
	{
		if (nbr != 0)
			tab->_rep->width -= len ;
		while (tab->_rep->width--)
			tab->tl += write(1, " ", 1);
		if (nbr != 0)
			tab->tl += ft_putnbr(nbr);
	}
	else if ((nbr >= 0 && tab->_rep->precision < len)
		&& tab->_rep->width <= len)
	{
		if (nbr != 0)
			tab->tl += ft_putnbr(nbr);
		else
		{
			while (tab->_rep->width--)
				tab->tl += write(1, " ", 1);
		}
	}
}

static void	precision_and_len(t_printf *tab, int nbr, int len, int m)
{
	int	n;

	if (nbr < 0 && tab->_rep->precision > (len + 1))
	{
		m = tab->_rep->precision;
		n = m - len ;
		m = tab->_rep->width - (tab->_rep->precision + 1);
		while (m--)
			tab->tl += write(1, " ", 1);
		tab->tl += write(1, "-", 1);
		while (n--)
			tab->tl += write(1, "0", 1);
	}
	else if (nbr < 0 && tab->_rep->precision <= (len + 1))
	{
		if (tab->_rep->width > (len + 1))
		{
			m = tab->_rep->width - (len + 1);
			while (m--)
				tab->tl += write(1, " ", 1);
		}
		tab->tl += write(1, "-", 1);
	}
	tab->tl += ft_putnbr(nbr);
}

int	zf_pnt_pre_p_l_w(t_printf *tab, int nbr, int len)
{
	int	n;
	int	m;

	m = 0;
	precision_g_len(tab, nbr, len);
	if (nbr >= 0 && tab->_rep->precision > len)
	{
		m = tab->_rep->precision;
		n = m - len;
		m = tab->_rep->width - tab->_rep->precision ;
		while (m--)
			tab->tl += write(1, " ", 1);
		while (n--)
			tab->tl += write(1, "0", 1);
		tab->tl += ft_putnbr(nbr);
	}
	else if (nbr >= 0 && tab->_rep->precision == len)
		tab->tl += ft_putnbr(nbr);
	else if (nbr < 0)
		precision_and_len(tab, nbr, len, m);
	return (0);
}

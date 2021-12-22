/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_pnt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 22:26:04 by mmasstou          #+#    #+#             */
/*   Updated: 2021/12/22 22:26:08 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

static void	prec_width(t_printf *tab, int nbr, int len)
{
	if (nbr < 0)
	{
		tab->tl += write (1, "-", 1);
		len += 1;
	}
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
			tab->_rep->width -= tab->_rep->precision;
			tab->_rep->precision -= len;
			while (tab->_rep->width--)
				tab->tl += write (1, " ", 1);
			while (tab->_rep->precision--)
				tab->tl += write (1, "0", 1);
		}
	}
	tab->tl += ft_putnbr(nbr);
}

static void	no_d_p_w(t_printf *tab, int nbr)
{
	int	len;

	len = ft_nbrlen(nbr);
	if (tab->_rep->precision > tab->_rep->width)
	{
		if (nbr < 0)
		{
			tab->tl += write (1, "-", 1);
			len += 1;
		}
		if (tab->_rep->precision > len)
		{
			tab->_rep->precision -= len ;
			while (tab->_rep->precision--)
				tab->tl += write (1, "0", 1);
		}
		tab->tl += ft_putnbr(nbr);
	}
	else if (tab->_rep->precision <= tab->_rep->width)
		prec_width(tab, nbr, len);
}

static void	w_and_p_l_w(t_printf *tab, int nbr, int len)
{
	int	n;
	int	m;

	if (tab->_rep->width > len && tab->_rep->precision > len)
	{
		m = tab->_rep->precision;
		if (nbr < 0)
			tab->_rep->precision += 1;
		n = m - len;
		m = tab->_rep->width - tab->_rep->precision;
		while (n--)
			tab->tl += write(1, "0", 1);
	}
	else if (tab->_rep->width > len && tab->_rep->precision <= len)
	{
		if (nbr < 0)
			len += 1;
		m = tab->_rep->width - len;
	}
	tab->tl += ft_putnbr(nbr);
	if (tab->_rep->width > len)
	{
		while (m--)
			tab->tl += write(1, " ", 1);
	}
}

static void	dash_prec(t_printf *tab, int nbr)
{
	int	len;

	len = ft_nbrlen(nbr);
	if (nbr < 0)
		tab->tl += write(1, "-", 1);
	if (tab->width && tab->_rep->precision < tab->_rep->width)
		w_and_p_l_w(tab, nbr, len);
	else
	{
		if ((tab->width && tab->_rep->precision > tab->_rep->width)
			|| (tab->width && tab->_rep->precision == tab->_rep->width)
			|| (!tab->width && tab->_rep->precision > len))
		{
			if ((tab->_rep->precision > len)
				|| (tab->width && tab->_rep->precision == tab->_rep->width)
				|| (!tab->width && tab->_rep->precision > len))
			{
				tab->_rep->precision -= len;
				while (tab->_rep->precision--)
					tab->tl += write(1, "0", 1);
			}
		}
		tab->tl += ft_putnbr(nbr);
	}
}

void	d_spe_pnt(t_printf *tab, int nbr)
{
	int	len;

	len = ft_nbrlen(nbr);
	if (!tab->dash && tab->precision && tab->width)
		no_d_p_w(tab, nbr);
	else if (tab->dash && tab->precision)
		dash_prec(tab, nbr);
	else if (tab->dash && !tab->precision)
	{
		if (tab->width && nbr < 0)
		{
			tab->tl += write(1, "-", 1);
			len += 1;
		}
		if (tab->width && tab->_rep->width > len)
		{
			while (tab->_rep->width--)
				tab->tl += write(1, " ", 1);
		}
		else if (tab->width && tab->_rep->width <= len)
			tab->tl += ft_putnbr(nbr);
	}
}

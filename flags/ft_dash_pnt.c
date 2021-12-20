/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dash_pnt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 22:09:31 by mmasstou          #+#    #+#             */
/*   Updated: 2021/12/20 22:09:35 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

static void	width_pre(t_printf *tab, int nbr, int nbrl)
{
	int	precision;

	precision = 0;
	if (tab->_rep->width > tab->_rep->precision
		&& tab->_rep->precision >= nbrl)
	{
		precision -= nbrl;
		while (precision--)
			tab->tl += write(1, "0", 1);
		tab->tl += ft_putnbr(nbr);
		tab->_rep->width -= tab->_rep->precision;
		while (tab->_rep->width--)
			tab->tl += write(1, " ", 1);
	}
	else if (tab->_rep->width > tab->_rep->precision
		&& tab->_rep->precision < nbrl)
		tab->tl += ft_putnbr(nbr);
	else if (tab->_rep->width <= tab->_rep->precision
		|| (!tab->_rep->width && tab->_rep->precision))
	{
		precision -= nbrl;
		while (precision--)
			tab->tl += write(1, "0", 1);
		tab->tl += ft_putnbr(nbr);
	}
}

void	ft_dash_pnt(t_printf *tab)
{
	int	m;
	int	precision;
	int	nbr;
	int	nbrl;

	precision = tab->_rep->precision;
	nbr = va_arg(tab->args, int);
	nbrl = ft_nbrlen(nbr);
	if (!tab->_rep->width && !tab->_rep->precision)
		tab->tl += ft_putnbr(nbr);
	else if (tab->_rep->width && !tab->_rep->precision)
	{
		tab->tl += ft_putnbr(nbr);
		m = tab->_rep->width - nbrl;
		while (m--)
			tab->tl += write(1, " ", 1);
	}
	width_pre(tab, nbr, nbrl);
	ft_resize_flags(tab);
}

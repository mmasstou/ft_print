/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_no_pnt.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 22:35:03 by mmasstou          #+#    #+#             */
/*   Updated: 2021/12/22 22:35:08 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

static void	no_dash(t_printf *tab, int nbr, int len)
{
	if (tab->width)
	{
		if (tab->_rep->width <= len)
		{
			if (nbr < 0)
				tab->tl += write(1, "-", 1);
			tab->tl += ft_putnbr(nbr);
			ft_resize_flags(tab);
		}
		else if (tab->_rep->width > len)
		{
			if (nbr < 0)
				tab->_rep->width -= (len + 1);
			else
				tab->_rep->width -= len;
			while (tab->_rep->width--)
				tab->tl += write (1, " ", 1);
			if (nbr < 0)
				tab->tl += write(1, "-", 1);
			tab->tl += ft_putnbr(nbr);
			ft_resize_flags(tab);
		}
	}
}

static void	dash(t_printf *tab, int nbr, int len)
{
	if (tab->width)
	{
		if (nbr < 0)
		{
			tab->tl += write(1, "-", 1);
			len += 1;
		}
		if (tab->_rep->width > len)
		{
			tab->_rep->width -= len;
			tab->tl += ft_putnbr(nbr);
			while (tab->_rep->width--)
				tab->tl += write (1, " ", 1);
		}
		else if (tab->_rep->width <= len)
			tab->tl += ft_putnbr(nbr);
	}
	else if (!tab->width)
	{
		if (nbr < 0)
			tab->tl += write(1, "-", 1);
		tab->tl += ft_putnbr(nbr);
		ft_resize_flags(tab);
	}
}

void	d_spe_no_pnt(t_printf *tab, int nbr)
{
	int	len;

	len = ft_nbrlen(nbr);
	if (!tab->dash)
		no_dash(tab, nbr, len);
	else if (tab->dash)
		dash(tab, nbr, len);
}

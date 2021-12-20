/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 00:15:40 by mmasstou          #+#    #+#             */
/*   Updated: 2021/12/21 00:15:42 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

static int	hdfsj(t_printf *tab, int nbr, int len)
{
	if (tab->_rep->precision > len)
	{
		if (nbr < 0)
			tab->tl += write(1, "-", 1);
		tab->_rep->precision -= len;
		while (tab->_rep->precision--)
			tab->tl += write(1, "0", 1);
		tab->tl += ft_putnbr(nbr);
	}
	else if (tab->_rep->precision <= len)
	{
		if (nbr == 0 && tab->_rep->precision == 0)
			return (ft_resize_flags(tab), 1);
		else if (nbr == 0 && tab->_rep->precision > 0)
		{
			tab->tl += ft_putnbr(nbr);
			return (ft_resize_flags(tab), 1);
		}
		else if (nbr < 0)
			tab->tl += write(1, "-", 1);
		tab->tl += ft_putnbr(nbr);
	}
	return (0);
}

static int	zf_pnt_pre(t_printf *tab, int nbr, int len)
{
	int	n;

	if (tab->width)
	{
		if (tab->_rep->precision < tab->_rep->width)
			zf_pnt_pre_p_l_w(tab, nbr, len);
		else if (tab->_rep->precision >= tab->_rep->width)
		{
			if (nbr < 0)
				tab->tl += write(1, "-", 1);
			n = tab->_rep->precision - len;
			while (n--)
				tab->tl += write(1, "0", 1);
			tab->tl += ft_putnbr(nbr);
		}
	}
	else if (!tab->width)
		hdfsj(tab, nbr, len);
	ft_resize_flags(tab);
	return (0);
}

static int	zf_pnt_no_pre(t_printf *tab, int nbr, int len)
{
	if (!tab->width)
	{
		if (nbr == 0)
			return (ft_resize_flags(tab), 1);
		else if (tab->width && tab->_rep->width > len)
		{
			tab->_rep->width -= len;
			while (tab->_rep->width--)
				tab->tl += write(1, " ", 1);
		}
		if (nbr < 0)
			tab->tl += write(1, "-", 1);
		tab->tl += ft_putnbr(nbr);
	}
	else if (tab->width && nbr != 0)
		tab->tl += ft_putnbr(nbr);
	else if (tab->width && nbr == 0)
		while (tab->_rep->width--)
			tab->tl += write(1, " ", 1);
	return (0);
}

static void	zf_no_pnt(t_printf *tab, int nbr, int len)
{
	if (!tab->width)
	{
		if (nbr < 0)
			tab->tl += write(1, "-", 1);
	}
	else if (tab->width && nbr < 0)
	{
		tab->tl += write(1, "-", 1);
		len += 1;
	}
	if (tab->width && tab->_rep->width > len)
	{
		tab->_rep->width -= len;
		while (tab->_rep->width--)
			tab->tl += write(1, "0", 1);
	}
	tab->tl += ft_putnbr(nbr);
}

int	ft_zero_flag(t_printf *tab)
{
	int	nbr;
	int	len;

	nbr = va_arg(tab->args, int);
	len = ft_nbrlen(nbr);
	if (!tab->pnt)
		zf_no_pnt(tab, nbr, len);
	else if ((!tab->pnt && tab->width) && tab->_rep->width <= len)
		tab->tl += ft_putnbr(nbr);
	if (tab->pnt && tab->precision)
		zf_pnt_pre(tab, nbr, len);
	else if (tab->pnt && !tab->precision)
		zf_pnt_no_pre(tab, nbr, len);
	ft_resize_flags(tab);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_specifer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:50:58 by mmasstou          #+#    #+#             */
/*   Updated: 2021/12/18 18:51:00 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

int	d_zero_pnt(t_printf *tab)
{
	int	nbr;
	int	m;
	int	len;

	nbr = va_arg(tab->args, int);
	len = ft_nbrlen(nbr);
	if (!tab->pnt)
	{
		if (!tab->width)
		{
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
				tab->tl += ft_putnbr(nbr);
			}
		}
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_dash_pnt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 22:11:30 by mmasstou          #+#    #+#             */
/*   Updated: 2021/12/20 22:11:32 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

void	no_dash_pnt(t_printf *tab)
{
	int	m;
	int	nbrl;
	int	nbr;

	nbr = va_arg(tab->args, int);
	nbrl = ft_nbrlen(nbr);
	if (tab->_rep->width)
	{
		m = tab->_rep->width - nbrl;
		while (m--)
			tab->tl += write(1, " ", 1);
		tab->tl += ft_putnbr(nbr);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:19:37 by mmasstou          #+#    #+#             */
/*   Updated: 2021/12/02 11:22:18 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

void	plus_flag(t_printf *tab, int spicefier)
{
	int	nbr;

	if (spicefier == 'd' || spicefier == 'i')
	{
		nbr = va_arg(tab->args, int);
		if (nbr >= 0)
			tab->tl += write(1, "+", 1);
		else if (nbr < 0)
			tab->tl += write(1, "-", 1);
		tab->tl += ft_putnbr(nbr);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:24:25 by mmasstou          #+#    #+#             */
/*   Updated: 2021/12/02 11:25:32 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

void	space_flag(t_printf *tab, int spicefier)
{
	int	nbr;

	if (spicefier == 'd' || spicefier == 'i')
	{
		nbr = va_arg(tab->args, int);
		if (nbr >= 0)
			tab->tl += write(1, " ", 1);
		else if (nbr < 0)
		{
			tab->tl += write(1, "-", 1);
			nbr *= -1;
		}

		tab->tl += ft_putnbr(nbr);
	}
}

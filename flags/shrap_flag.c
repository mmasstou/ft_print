/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shrap_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:22:35 by mmasstou          #+#    #+#             */
/*   Updated: 2021/12/02 11:24:07 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

void	shrap_flag(t_printf *tab, int spicefier)
{
	unsigned int	x;

	if (spicefier == 'x' || spicefier == 'X')
	{
		x = va_arg(tab->args, unsigned int);
		if (x == 0)
			tab->tl += write(1, "0", 1);
		else
		{
			if (spicefier == 'x')
				tab->tl += write(1, "0x", 2);
			if (spicefier == 'X')
				tab->tl += write(1, "0X", 2);
			tab->tl += ft_puthex(x, spicefier);
		}
	}
	ft_resize_flags(tab);
}

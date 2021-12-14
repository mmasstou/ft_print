/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:49:33 by mmasstou          #+#    #+#             */
/*   Updated: 2021/12/02 11:50:08 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

static int	ft_hex_len_ll(unsigned long long num)
{
	int	len;

	len = 0;
	while (num >= 16)
	{
		len++;
		num = num / 16;
	}
	len++;
	return (len);
}

static int	ft_putptr(unsigned long nbr)
{
	unsigned long	index;
	int				jndex;

	index = nbr;
	jndex = 0;
	if (nbr >= 16)
	{
		ft_putptr(nbr / 16);
		ft_putptr(nbr % 16);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar(nbr + 48);
		else
			ft_putchar((nbr - 10) + 'a');
	}
	jndex += ft_hex_len_ll(index);
	return (jndex);
}

void	ft_print_adress(t_printf *tab)
{
	unsigned long	p;

	p = va_arg(tab->args, unsigned long);
	tab->tl += ft_putstr("0x");
	tab->tl += ft_putptr(p);
}

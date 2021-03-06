/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:54:36 by mmasstou          #+#    #+#             */
/*   Updated: 2021/12/02 11:55:30 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

int	ft_putunsigned(unsigned int nbr)
{
	int	index;

	index = ft_unbrlen(nbr);
	if (nbr >= 10)
		ft_putunsigned(nbr / 10);
	ft_putchar(nbr % 10 + 48);
	return (index);
}

void	ft_print_unsigned(t_printf *tab)
{
	unsigned int	u;

	u = va_arg(tab->args, unsigned int);
	tab->tl += ft_putunsigned(u);
}

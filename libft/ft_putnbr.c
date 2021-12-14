/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:32:06 by mmasstou          #+#    #+#             */
/*   Updated: 2021/12/02 11:32:08 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

int	ft_putnbr(int n)
{
	unsigned int	nbr;
	int				index;

	index = ft_nbrlen(n);
	if (n < 0)
	{
		ft_putchar('-');
		nbr = (unsigned int)(n * -1);
	}
	else
		nbr = (unsigned int)n;
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + 48);
	return (index);
}

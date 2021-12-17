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

int	ft_putnbr(long long n)
{
	int				index;

	index = ft_nbrlen(n);
	if (n < 0)
		n = (n * -1);
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + 48);
	return (index);
}

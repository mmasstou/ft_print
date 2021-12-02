/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:29:41 by mmasstou          #+#    #+#             */
/*   Updated: 2021/12/02 11:31:48 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

static int	ft_hex_len(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

static	void	ft_put_hex_lower(unsigned int nbr)
{
	if (nbr >= 16)
	{
		ft_put_hex_lower(nbr / 16);
		ft_put_hex_lower(nbr % 16);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar(nbr + 48);
		else
			ft_putchar((nbr - 10) + 'a');
	}
}

static	void	ft_put_hex_upper(unsigned int nbr)
{
	if (nbr >= 16)
	{
		ft_put_hex_upper(nbr / 16);
		ft_put_hex_upper(nbr % 16);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar(nbr + 48);
		else
			ft_putchar((nbr - 10) + 'A');
	}
}

int	ft_puthex(unsigned int num, int specifier)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
	{
		if (specifier == 'x')
			ft_put_hex_lower(num);
		else
			ft_put_hex_upper(num);
	}
	return (ft_hex_len(num));
}

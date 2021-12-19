/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 18:47:19 by mmasstou          #+#    #+#             */
/*   Updated: 2021/12/18 18:47:23 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

static int	ft_hex_len_a(unsigned long num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

static int	p_no_d_and_w(t_printf *tab, int len, unsigned long p)
{
	int	m;

	if (tab->_rep->width > (len + 2))
	{
		m = tab->_rep->width - (len + 2);
		while (m--)
			tab->tl += write(1, " ", 1);
	}
	tab->tl += ft_p_adress(p);
	return (1);
}

int	p_flag(t_printf *tab)
{
	unsigned long	p;
	int				len;
	int				m;

	p = va_arg(tab->args, unsigned long);
	len = ft_hex_len_a(p);
	if (!tab->dash && tab->width)
		p_no_d_and_w(tab, len, p);
	else if (tab->dash && tab->width)
	{
		if (tab->_rep->width > (len + 2))
		{
			m = tab->_rep->width - (len + 2);
			tab->tl += ft_p_adress(p);
			while (m--)
				tab->tl += write(1, " ", 1);
		}
		else if (tab->_rep->width <= (len + 2))
			tab->tl += ft_p_adress(p);
	}
	else if (tab->dash && !tab->width)
		tab->tl += ft_p_adress(p);
	ft_resize_flags(tab);
	return (1);
}

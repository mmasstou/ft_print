/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_no_pnt_zero_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:16:30 by mmasstou          #+#    #+#             */
/*   Updated: 2021/12/22 18:16:32 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

void	h_no_p_z_u(t_printf *t, const char *f, int i, unsigned int u)
{
	int	len;

	len = ft_hex_len(u);
	if (!t->width)
		t->tl += ft_puthex(u, f[i]);
	else if (t->width)
	{
		if (t->_rep->width > len)
		{
			t->_rep->width -= len;
			while (t->_rep->width--)
				t->tl += write(1, "0", 1);
		}
		t->tl += ft_puthex(u, f[i]);
	}
	ft_resize_flags(t);
}

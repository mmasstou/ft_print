/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_pnt_zero_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:15:00 by mmasstou          #+#    #+#             */
/*   Updated: 2021/12/22 18:15:02 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

static int	prew(int m, int n)
{
	int	index;

	index = 0;
	while (m--)
		index += write(1, " ", 1);
	while (n--)
		index += write(1, "0", 1);
	return (index);
}

static void	p_l_w_and_p_g_l(int len, t_printf *t, int *m, int *n)
{
	*m = t->_rep->precision;
	*n = t->_rep->precision - len;
	*m = t->_rep->width - *m;
}

static void	prec_width(t_printf *t, const char *f, int i, unsigned int u)
{
	int	n[3];

	n[0] = 0;
	n[1] = 0;
	n[2] = ft_hex_len(u);
	if (t->_rep->precision > t->_rep->width && t->_rep->precision > n[2])
		n[1] = t->_rep->precision - n[2];
	else if (t->_rep->precision < t->_rep->width && t->_rep->precision > n[2])
		p_l_w_and_p_g_l(n[2], t, &n[0], &n[1]);
	else if (((t->_rep->precision < t->_rep->width
				&& t->_rep->precision <= n[2])
			&& t->_rep->precision == 0) && u == 0)
		n[0] = t->_rep->width ;
	else if (((t->_rep->precision < t->_rep->width
				&& t->_rep->precision <= n[2])
			&& t->_rep->precision == 0) && u != 0)
		t->tl += ft_puthex(u, f[i]);
	else if ((t->_rep->precision < t->_rep->width && t->_rep->precision <= n[2])
		&& t->_rep->precision != 0)
		n[0] = t->_rep->width - n[2];
	else if (t->_rep->precision == t->_rep->width)
		n[1] = t->_rep->precision - n[2];
	t->tl += prew(n[0], n[1]);
	if (t->_rep->precision != 0)
		t->tl += ft_puthex(u, f[i]);
}

void	h_p_z_u(t_printf *t, const char *f, int i, unsigned int u)
{
	int	len;

	len = ft_hex_len(u);
	if (t->precision && t->width)
		prec_width(t, f, i, u);
	else if (!t->precision && t->width && t->_rep->width >= len && u == 0)
	{
		while (t->_rep->width--)
			t->tl += write(1, " ", 1);
	}
	else
		t->tl += ft_puthex(u, f[i]);
	ft_resize_flags(t);
}

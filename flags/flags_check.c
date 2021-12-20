/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 03:05:45 by mmasstou          #+#    #+#             */
/*   Updated: 2021/12/11 03:06:11 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

void	flags_check(t_printf *tab, const char *format, int index)
{
	if (tab->zero && tab->dash)
	{
		tab->zero = 0;
		tab->_rep->zero = 0;
		tab->_rep->flags -= 1;
	}
	if (is_integer_specifier(format[index]))
	{
		if (tab->plus)
		{
			tab->space = 0;
			tab->_rep->space = 0;
			tab->_rep->flags -= 1;
		}	
	}	
}

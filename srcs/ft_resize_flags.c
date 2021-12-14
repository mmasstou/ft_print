/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialise_tab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:46:35 by mmasstou          #+#    #+#             */
/*   Updated: 2021/12/02 11:48:59 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

t_printf	*ft_resize_flags(t_printf *tab)
{
	tab->plus = 0;
	tab->_rep->plus = 0;
	tab->perc = 0;
	tab->_rep->perc = 0;
	tab->space = 0;
	tab->_rep->space = 0;
	tab->shrap = 0;
	tab->_rep->shrap = 0;
	tab->is_flag = 0;
	tab->_rep->flags = 0;
	tab->zero = 0;
	tab->_rep->zero = 0;
	tab->dash = 0;
	tab->_rep->dash = 0;
	tab->pnt = 0;
	tab->_rep->pnt = 0;
	tab->width = 0;
	tab->_rep->width = 0;
	tab->_rep->lenwidth = 0;
	tab->precision = 0;
	tab->_rep->precision = 0;
	tab->_rep->lenprecision = 0;
	return (tab);
}


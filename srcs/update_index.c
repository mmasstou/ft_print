/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 22:08:52 by mmasstou          #+#    #+#             */
/*   Updated: 2021/12/11 22:08:55 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

int	update_index(t_printf *tab, int index)
{
	if (tab->is_flag)
	{
		if (tab->_rep->space)
			index += tab->_rep->space;
		if (tab->_rep->plus)
			index += tab->_rep->plus;
		if (tab->_rep->shrap)
			index += tab->_rep->shrap;
		if (tab->_rep->dash)
			index += tab->_rep->dash;
	}
	return (index);
}

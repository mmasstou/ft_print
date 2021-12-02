/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:35:11 by mmasstou          #+#    #+#             */
/*   Updated: 2021/12/02 11:44:17 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

static void is_flags(t_printf *tab)
{
	if (tab->plus || tab->shrap || tab->space)
		tab->is_flag = 1;
}

int	ft_eval_format(t_printf *tab, const char *format, int index)
{
	int		strat;

	strat = (index) + 1;
	while (!is_specifier(format[index]))
	{
		if (format[index] == '+')
		{
			tab->plus = 1;
			tab->_rep->plus++;
		}	
		if (format[index] == ' ')
		{
			tab->space = 1;
			tab->_rep->space++;
		}
		if (format[index] == '#')
		{
			tab->shrap = 1;
			tab->_rep->shrap++;
		}
		index++;
	}
	is_flags(tab);
	ft_specifier(tab, format, index);
	return (index);
}


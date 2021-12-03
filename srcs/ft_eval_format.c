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

static void	flag_part1(t_printf *tab, const char *format, int index)
{
	if (format[index] == '+')
	{
		tab->plus = 1;
		tab->_rep->plus++;
		index++;
	}	
	if (format[index] == ' ')
	{
		tab->space = 1;
		tab->_rep->space++;
		index++;
	}
	if (format[index] == '#')
	{
		tab->shrap = 1;
		tab->_rep->shrap++;
		index++;
	}
	if (tab->shrap || tab->space || tab->plus)
	{
		tab->is_flag = 1;
		tab->_rep->flags += (tab->space + tab->shrap +tab->plus);
	}
}
static int	flag_part2(t_printf *tab, const char *format, int index)
{
	if (format[index] == '-')
	{
		tab->dash = 1;
		tab->_rep->dash++;
		index++;
	}	
	if (format[index] == '0')
	{
		tab->zero = 1;
		tab->_rep->zero++;
		index++;
	}
	if (format[index] == '.')
	{
		tab->pnt = 1;
		tab->_rep->pnt++;
		index++;
		while (ft_isdigit(format[index]))
		{
			tab->precision = 1;
			tab->_rep->precision++;
			index++;
		}
	}
	if (tab->pnt || tab->dash || tab->zero)
	{
		tab->is_flag = 1;
		tab->_rep->flags += (tab->pnt + tab->dash + tab->zero);
	}
	return (index);
}
int	ft_eval_format(t_printf *tab, const char *format, int index)
{
	int		strat;

	strat = (index) + 1;
	while (!is_specifier(format[index]))
	{
		
		if (format[index] > '0' && format[index] <= '9')
		{
			while (ft_isdigit(format[index]))
			{
				tab->width = 1;
				tab->_rep->width++;
				index++;
			}
		}
		index = flag_part2(tab, format, index);
		flag_part1(tab, format, index);
	}
	ft_specifier(tab, format, index);
	return (index);
}


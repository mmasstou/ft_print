/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 03:06:41 by mmasstou          #+#    #+#             */
/*   Updated: 2021/12/11 03:07:59 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

int	ft_get_precision(const char *format, int index)
{
	int	result;

	result = 0;
	while (format[index])
	{
		while (format[index] && ft_isdigit(format[index]))
		{
			result = result * 10 + format[index] - 48;
			index++;
		}
		if (!ft_isdigit(format[index]))
			return (result);
	}
	return (result);
}

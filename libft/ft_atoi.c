/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:26:45 by mmasstou          #+#    #+#             */
/*   Updated: 2021/12/02 11:26:49 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

int	ft_atoi(const char *str)
{
	int	signe;
	int	result;

	signe = 1;
	result = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			signe = -signe;
		str++ ;
	}
	while (*str && ft_isdigit(*str))
	{
		result = result * 10 + *str - 48;
		str++;
	}
	result *= signe;
	return (result);
}

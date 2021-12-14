/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 03:34:01 by mmasstou          #+#    #+#             */
/*   Updated: 2021/12/11 03:34:21 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

int	ft_strlen(const char *str)
{
	int	index;

	index = 0;
	if (str == NULL)
		index = 6;
	else
		while (str[index])
			index++;
	return (index);
}

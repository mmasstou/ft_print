/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:27:50 by mmasstou          #+#    #+#             */
/*   Updated: 2021/12/02 11:28:03 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

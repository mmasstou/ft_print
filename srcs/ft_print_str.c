/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:53:25 by mmasstou          #+#    #+#             */
/*   Updated: 2021/12/02 11:53:57 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

void	ft_print_str(t_printf *tab)
{
	char	*str;

	str = va_arg(tab->args, char *);
	if (str == NULL)
		tab->tl += ft_putstr("(null)");
	else
		tab->tl += ft_putstr(str);
}

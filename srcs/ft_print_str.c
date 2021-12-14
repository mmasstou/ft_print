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
#include <stdbool.h>

void	ft_print_str(t_printf *tab, char *str)
{
	char	*st;

	st = ft_substr(str, 0, ft_strlen(str));
	tab->tl += ft_putstr(st);
	free(st);
}

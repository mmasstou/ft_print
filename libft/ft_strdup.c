/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 03:33:34 by mmasstou          #+#    #+#             */
/*   Updated: 2021/12/11 03:33:37 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

char	*ft_strdup(const char *s)
{
	char	*string;
	char	*src;

	string = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!string)
		return (NULL);
	src = (char *)s;
	while (*src)
		*string++ = *src++;
	*string = 0;
	return (string - ft_strlen(s));
}

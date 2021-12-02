/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasstou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:27:14 by mmasstou          #+#    #+#             */
/*   Updated: 2021/12/02 11:27:32 by mmasstou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(int s)
{
	char	*space;

	space = "\f\n\r\t\v ";
	while (*space)
		if (s == *space++)
			return (1);
	return (0);
}

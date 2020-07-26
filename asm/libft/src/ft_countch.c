/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 17:52:28 by cpollich          #+#    #+#             */
/*   Updated: 2020/07/21 17:13:50 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Считает количество символов c в строке str
*/

int	ft_countch(const char *str, int c)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == c)
			res++;
		i++;
	}
	return (res);
}

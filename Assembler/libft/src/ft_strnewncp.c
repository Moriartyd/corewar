/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnewncp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 21:35:43 by cpollich          #+#    #+#             */
/*   Updated: 2020/07/21 17:14:15 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnewncp(const char *str, size_t len)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!(res = ft_strnew(len + 1)))
		return (NULL);
	while (i < len && str[i])
	{
		res[i] = str[i];
		i++;
	}
	if (i != len)
	{
		ft_strdel(&res);
		return (NULL);
	}
	return (res);
}

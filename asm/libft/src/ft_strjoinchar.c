/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 15:57:55 by cpollich          #+#    #+#             */
/*   Updated: 2020/07/21 17:14:25 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strjoinchar(char **str, char c)
{
	char	*tmp;
	size_t	len;

	if (!*str)
		return (0);
	len = ft_strlen(*str);
	if (!(tmp = (char *)malloc(sizeof(char) * (len + 2))))
		return (0);
	tmp = ft_strcpy(tmp, *str);
	if (len)
	{
		tmp[len] = c;
		tmp[len + 1] = 0;
	}
	else
	{
		tmp[0] = c;
		tmp[1] = 0;
	}
	ft_strdel(str);
	*str = tmp;
	return (1);
}

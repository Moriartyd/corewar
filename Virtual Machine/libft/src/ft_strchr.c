/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:42:08 by mriley            #+#    #+#             */
/*   Updated: 2019/04/12 16:42:11 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int symbol)
{
	int i;

	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == symbol)
			return ((char*)string + i);
		i++;
	}
	if (string[i] == symbol)
		return ((char*)string + i);
	return (NULL);
}

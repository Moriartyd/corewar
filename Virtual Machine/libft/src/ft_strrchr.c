/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 21:42:36 by mriley            #+#    #+#             */
/*   Updated: 2019/04/12 16:13:15 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int symbol)
{
	int i;
	int h;

	i = 0;
	h = -1;
	while (string[i] != '\0')
	{
		if (string[i] == symbol)
			h = i;
		i++;
	}
	if (string[i] == symbol)
		h = i;
	if (h == -1)
		return (NULL);
	else
		return ((char*)string + h);
}

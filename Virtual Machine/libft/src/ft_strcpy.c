/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:46:55 by mriley            #+#    #+#             */
/*   Updated: 2019/04/12 16:15:00 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *destptr, const char *srcptr)
{
	int i;
	int h;

	i = 0;
	h = 0;
	while (srcptr[i] != '\0')
	{
		i++;
	}
	while (h < i)
	{
		destptr[h] = srcptr[h];
		h++;
	}
	destptr[h] = '\0';
	return (destptr);
}

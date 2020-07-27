/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:45:16 by mriley            #+#    #+#             */
/*   Updated: 2019/04/18 16:01:34 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *d, const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*st;
	unsigned char		*dt;
	unsigned char		h;

	h = (unsigned char)c;
	st = (unsigned char *)s;
	dt = (unsigned char *)d;
	i = 0;
	while (i < n)
	{
		if (st[i] == h)
		{
			dt[i] = st[i];
			i++;
			return ((void *)&(dt[i]));
		}
		else
		{
			dt[i] = st[i];
			i++;
		}
	}
	return (NULL);
}

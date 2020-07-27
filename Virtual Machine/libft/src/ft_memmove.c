/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:44:12 by mriley            #+#    #+#             */
/*   Updated: 2019/04/18 16:00:23 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *d, const void *s, size_t n)
{
	size_t			i;
	unsigned char	*b;

	b = (unsigned char*)malloc(sizeof(unsigned char*) * n);
	i = 0;
	if (b)
	{
		ft_memcpy(b, s, n);
		ft_memcpy(d, b, n);
	}
	return (d);
}

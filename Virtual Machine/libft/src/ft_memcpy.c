/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <mriley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:19:40 by mriley            #+#    #+#             */
/*   Updated: 2019/05/12 18:17:13 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned long	*s;
	unsigned long	*d;
	unsigned char	*sc;
	unsigned char	*dc;
	size_t			nb;

	d = (unsigned long *)dst;
	s = (unsigned long *)src;
	nb = n / sizeof(unsigned long);
	while (nb--)
		*(d++) = *(s++);
	nb = n % sizeof(unsigned long);
	sc = (unsigned char *)s;
	dc = (unsigned char *)d;
	while (nb--)
		*(dc++) = *(sc++);
	return (dst);
}

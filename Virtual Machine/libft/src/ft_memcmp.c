/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 18:18:16 by mriley            #+#    #+#             */
/*   Updated: 2019/04/18 21:07:54 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *m1, const void *m2, size_t num)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char*)m1;
	p2 = (unsigned char*)m2;
	i = 0;
	if (num == 0)
		return (0);
	while (p1[i] == p2[i] && i < (num - 1))
	{
		i++;
	}
	return (p1[i] - p2[i]);
}

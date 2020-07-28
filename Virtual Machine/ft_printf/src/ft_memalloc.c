/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:14:41 by mriley            #+#    #+#             */
/*   Updated: 2019/04/18 18:13:28 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*s;

	s = (unsigned char*)malloc(size);
	if (s != NULL)
	{
		ft_bzero(s, size);
		return ((void*)s);
	}
	else
		return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:45:44 by mriley            #+#    #+#             */
/*   Updated: 2019/04/12 18:51:59 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	const unsigned char	*string;
	int					i;

	string = (const unsigned char*)arr;
	i = 0;
	while (i < (int)n)
	{
		if (string[i] == (unsigned char)c)
		{
			return ((void*)arr + i);
		}
		else
			i++;
	}
	return (NULL);
}

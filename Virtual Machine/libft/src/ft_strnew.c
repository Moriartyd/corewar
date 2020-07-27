/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 21:39:03 by mriley            #+#    #+#             */
/*   Updated: 2019/04/18 18:52:44 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*s;

	if (size == (size_t)(-1))
		return (NULL);
	s = (char*)malloc(size + 1);
	if (s == NULL)
		return (NULL);
	while (size + 1 > 0)
	{
		s[size] = '\0';
		size--;
	}
	return (s);
}

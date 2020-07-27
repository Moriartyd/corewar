/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:41:35 by smanhack          #+#    #+#             */
/*   Updated: 2019/04/07 18:41:36 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *p;

	if (size == (size_t)(-1))
		return (NULL);
	p = (char *)malloc(sizeof(*p) * (size + 1));
	if (p)
	{
		while (size)
		{
			p[size] = '\0';
			size--;
		}
		p[size] = '\0';
		return (p);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 21:40:33 by mriley            #+#    #+#             */
/*   Updated: 2019/04/18 17:05:17 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t length)
{
	size_t	i;
	size_t	j;
	size_t	p;

	i = 0;
	j = 0;
	p = 0;
	if (*s2 == '\0')
		return ((char*)s1);
	if (length == 0)
		return (NULL);
	while (s1[i] != '\0' && i < length)
	{
		while (s1[i] == s2[j] && s1[i] != '\0' && s2[j] != '\0' && i < length)
		{
			i++;
			j++;
		}
		if (s2[j] == '\0')
			return ((char*)&s1[i - j]);
		j = 0;
		i = ++p;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 21:50:19 by mriley            #+#    #+#             */
/*   Updated: 2019/04/18 15:58:53 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		o;
	int		k;

	i = 0;
	j = 0;
	k = -1;
	o = ft_strlen(s2);
	if (!*s2)
		return ((char*)s1);
	while (s1[i] != '\0')
	{
		while (s1[i] == s2[j] && s1[i] != '\0' && s2[j] != '\0')
		{
			i++;
			j++;
		}
		if (s2[j] == '\0')
			return ((char*)s1 + i - j);
		j = 0;
		i = ++k;
	}
	return (NULL);
}

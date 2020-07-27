/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 21:33:00 by mriley            #+#    #+#             */
/*   Updated: 2019/04/18 17:23:16 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*t;
	int		i;
	int		y;

	y = 0;
	i = 0;
	if (s && f)
	{
		while (s[i] != '\0')
		{
			i++;
		}
		t = ft_memalloc(i + 1);
		if (t == NULL)
			return (NULL);
		while (y < i)
		{
			t[y] = f(y, s[y]);
			y++;
		}
		t[y] = '\0';
		return (t);
	}
	return (NULL);
}

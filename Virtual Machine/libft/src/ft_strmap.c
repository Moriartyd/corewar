/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 21:31:32 by mriley            #+#    #+#             */
/*   Updated: 2019/04/18 17:21:45 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
			t[y] = f(s[y]);
			y++;
		}
		t[y] = '\0';
		return (t);
	}
	return (NULL);
}

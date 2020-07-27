/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 21:52:47 by mriley            #+#    #+#             */
/*   Updated: 2019/04/18 18:41:39 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*f;
	int		i;
	int		y;
	int		j;

	i = 0;
	y = -1;
	if (!s)
		return (NULL);
	j = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] != '\0')
		while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
			j--;
	else
		j--;
	j++;
	f = (char*)malloc(sizeof(char*) * (j - i + 1));
	if (f == NULL)
		return (NULL);
	while (i <= j)
		f[++y] = (char)s[i++];
	f[y] = '\0';
	return (f);
}

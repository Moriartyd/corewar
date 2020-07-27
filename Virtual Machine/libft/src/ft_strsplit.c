/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 21:44:30 by mriley            #+#    #+#             */
/*   Updated: 2019/04/18 18:05:43 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int				snt(const char *s, char c, int g)
{
	int		i;
	int		j;
	int		y;

	i = 0;
	j = 0;
	while (j <= g && s[i] != '\0')
	{
		y = 0;
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c &&
			s[i + 1] == '\0'))
			j++;
		if (s[i] != c)
			y++;
		i++;
	}
	return (y);
}

static	void			ft_memwdel(unsigned char **d, int g)
{
	int		i;

	i = 0;
	while (i <= g)
	{
		free(d[i]);
		d[i] = NULL;
		i++;
	}
	free(d);
	d = NULL;
}

static unsigned char	**ft_memstr(const char *s, char c)
{
	int				i;
	int				j;
	unsigned char	**d;

	i = -1;
	j = 0;
	if (!s || !c)
		return (NULL);
	while (s[++i] != '\0')
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
			j++;
	}
	i = -1;
	d = (unsigned char**)malloc(sizeof(unsigned char*) * (j + 1));
	if (d == NULL)
		return (NULL);
	while (++i < j)
	{
		d[i] = (unsigned char*)malloc(sizeof(unsigned char*) *
				(snt(s, c, i) + 1));
		if (d[i] == NULL)
			ft_memwdel(d, i);
	}
	return (d);
}

char					**ft_strsplit(char const *s, char c)
{
	int				i;
	int				h;
	int				r;
	unsigned char	**d;

	r = 0;
	d = ft_memstr(s, c);
	if (s && c && d)
	{
		i = 0;
		while (s[i] != '\0' && snt(s, c, 0) > 0)
		{
			h = -1;
			while (s[i] == c && s[i] != '\0')
				i++;
			while (s[i] != c && s[i] != '\0')
				d[r][++h] = ((unsigned char*)s)[i++];
			d[r++][++h] = '\0';
			while (s[i] == c && s[i] != '\0')
				i++;
		}
		d[r] = 0;
		return ((char**)d);
	}
	return (NULL);
}

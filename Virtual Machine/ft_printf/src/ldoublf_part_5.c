/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldoublf_part_5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <mriley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:21:44 by smanhack          #+#    #+#             */
/*   Updated: 2019/08/29 15:17:59 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_okruglyaem(char *h, long double n)
{
	int		g;
	int		i;

	i = ft_strlen(h) - 1;
	g = (int)(n);
	if (g > 5)
	{
		h[i] = h[i] + 1;
		while (i >= 0)
		{
			while (h[i] > '9')
			{
				h[i] = '0';
				if (i - 1 < 0)
					return (ft_strjoin("1.", h));
				h[i - 1] = h[i - 1] + 1;
			}
			i--;
		}
	}
	return (h);
}

int					*todes(char *s)
{
	char	*d;
	int		*des;
	int		i;

	i = 0;
	d = (char*)malloc(ft_strlen(s) + 1);
	while (s[i] != '.' && s[i] != '\0')
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	des = izdvatodes(d);
	return (des);
}

char				*ft_peredel(char *zifra, int j)
{
	j--;
	while (zifra[j] > '9' && j > -1)
	{
		zifra[j] = '0';
		if (j - 1 > -1)
			zifra[j - 1] = zifra[j - 1] + 1;
		j--;
	}
	if (j == -1)
		zifra = ft_strjoin("1.", zifra);
	return (zifra);
}

char				*ft_peredelzel(char *zifra, int j)
{
	j--;
	zifra[j] = zifra[j] + 1;
	while (zifra[j] > '9' && j > -1)
	{
		zifra[j] = '0';
		zifra[j - 1] = zifra[j - 1] + 1;
		j--;
	}
	if (j == -1)
		zifra = ft_strjoin("1", zifra);
	return (zifra);
}

char				*ft_delaem_part_2(int *g, int *j, char **zifra)
{
	char	*stroka;

	stroka = *zifra;
	if (g[j[2] + 1] < 100 && j[1] != 0)
	{
		stroka = ft_strjoin(*zifra, "0");
		free(*zifra);
		*zifra = stroka;
	}
	if (g[j[2] + 1] < 10 && j[1] != 0)
	{
		stroka = ft_strjoin(*zifra, "0");
		free(*zifra);
		*zifra = stroka;
	}
	return (*zifra);
}

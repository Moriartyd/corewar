/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldoublf_part_6.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:22:28 by smanhack          #+#    #+#             */
/*   Updated: 2020/07/27 23:40:34 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_stroka(char **zifra, char *s)
{
	char	*stroka;

	stroka = ft_strjoin(*zifra, s);
	free(*zifra);
	free(s);
	return (stroka);
}

char				*ft_delaem(int *g, char *znak, char *mantissa)
{
	int		j[3];
	char	*s;
	char	*zifra;

	j[1] = 0;
	j[2] = 0;
	while (mantissa[j[2]] != '.' && (j[0] = 0) == 0)
		j[2]++;
	zifra = (char*)malloc(5);
	ft_bzero(zifra, 5);
	if (znak[0] == '1')
		zifra[j[0]++] = '-';
	while (g[j[2]] == 0 && j[2] > 0)
		j[2]--;
	while (j[2]-- > -1)
	{
		zifra = ft_delaem_part_2(g, j, &zifra);
		s = ft_itoa(g[j[2] + 1]);
		if (zifra[0] == '\0')
			zifra = s;
		else
			zifra = ft_stroka(&zifra, s);
		j[1] = 1;
	}
	return (zifra);
}

char				*ft_okrtoc(char *t, t_format ff)
{
	if (ff.prec == -1 || ff.prec == 0)
	{
		t[0] = '\0';
		return (t);
	}
	if ((t[ff.prec - 1] - 48) % 2 == 0)
		t[ff.prec] = '\0';
	else
	{
		if ((t[ff.prec] - 48) > 4)
		{
			t[ff.prec - 1] = t[ff.prec - 1] + 1;
			t[ff.prec] = '\0';
			if (t[ff.prec - 1] > '9')
			{
				t = ft_peredel(t, ff.prec);
			}
		}
	}
	return (t);
}

char				*delaem1(int *g, t_format ff, char *mantissa, long double n)
{
	int		j[3];
	char	*s;
	char	*d;
	char	*stroka;

	d = (char*)malloc((ft_strlen(mantissa) + 2) + 1);
	ft_bzero(d, (ft_strlen(mantissa) + 2) + 1);
	ft_zero(j);
	(n < 0) ? n = -n : 0;
	while (j[1] < ff.prec + 1)
	{
		s = ft_itoa(g[j[1]++]);
		stroka = ft_strjoin(d, s);
		free(d);
		free(s);
		d = stroka;
		j[0]++;
		j[2] = 1;
	}
	if (((s[0] - 48 > 5) ||
			(s[0] - 48 == 5 && (long long)n % 2 != 0)) && j[1] == 1)
		return (ft_strdup("1.0"));
	d = ft_okrtoc(d, ff);
	return (d);
}

int					*sumfive(int *f, int *g, t_format ff)
{
	int sum;
	int i;

	sum = 0;
	i = ff.prec + 1;
	while (i >= 0)
	{
		f[i] = g[i] + f[i] + sum;
		sum = 0;
		if (f[i] >= 10)
		{
			sum = f[i] / 10;
			f[i] = f[i] % 10;
		}
		i--;
	}
	return (f);
}

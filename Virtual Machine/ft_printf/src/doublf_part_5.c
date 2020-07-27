/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublf_part_5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <mriley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 15:38:39 by smanhack          #+#    #+#             */
/*   Updated: 2019/08/29 16:29:55 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*todestocd(double n, t_format fа)
{
	char	*des;
	int		i;
	int		j;

	j = 0;
	i = 0;
	des = izdvatodestocd(n, fа);
	return (des);
}

int					*ft_rowkuld(int i, int *h, int k)
{
	int *f;
	int g;

	g = 0;
	f = (int*)malloc(sizeof(int) * (k + 3));
	ft_bzero(f, sizeof(int) * (k + 3));
	f[g] = 1;
	if (i == 0)
	{
		h[0] = h[0] + 1;
		return (h);
	}
	f = ft_rowhelp1(i, f, k + 3);
	h = ft_rowhelp2(h, f, k + 3);
	free(f);
	return (h);
}

int					*izdvatodesd(char *d)
{
	int	i;
	int	*h;

	i = 0;
	h = (int*)malloc(sizeof(int) * (ft_strlen(d) + 3));
	ft_bzero(h, sizeof(int) * (ft_strlen(d) + 3));
	i = 0;
	while (d[i] != '\0')
	{
		if (d[i] == '1')
		{
			h = ft_rowkuld(ft_strlen(d) - i - 1, h, ft_strlen(d));
		}
		i++;
	}
	return (h);
}

char				*okruglyaem(char *h, double n)
{
	int	g;
	int	i;

	i = ft_strlen(h) - 1;
	g = (int)n * 10;
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

int					*todesd(char *s)
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
	des = izdvatodesd(d);
	free(d);
	return (des);
}

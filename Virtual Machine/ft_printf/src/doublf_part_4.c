/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublf_part_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <mriley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 15:35:23 by smanhack          #+#    #+#             */
/*   Updated: 2019/07/31 17:08:46 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*mantisdvig4(char *s, long long n)
{
	int		i;
	char	*f;

	n = 0;
	i = 1;
	f = (char*)malloc(55);
	f[0] = s[0];
	f[1] = '.';
	while (s[i] != '\0' && i < 52)
	{
		f[i + 1] = s[i];
		i++;
	}
	f[i + 1] = '\0';
	return (f);
}

char				*dvigaemd(long long n, char *s)
{
	if (n > 0 && n > 52)
		return (mantisdvig1(s, n));
	if (n < 0)
		return (mantisdvig2(s, n));
	if (n > 0 && n < 53)
		return (mantisdvig3(s, n));
	if (n == 0)
		return (mantisdvig4(s, n));
	return (s);
}

char				*ft_mantissad(char *s)
{
	char	*mantissa;
	int		i;

	i = 1;
	mantissa = (char*)malloc(57);
	mantissa[0] = '1';
	while (s[i + 11] != '\0' && i < 55)
	{
		mantissa[i] = s[i + 11];
		i++;
	}
	mantissa[i] = '\0';
	return (mantissa);
}

int					*ft_rowhelp1(int i, int *f, int k)
{
	int sum;
	int g;

	sum = 0;
	g = 0;
	while (i-- > 0)
	{
		while (g < k)
		{
			f[g] = f[g] * 2 + sum;
			sum = 0;
			if (f[g] >= 1000)
			{
				sum = f[g] / 1000;
				f[g] = f[g] % 1000;
			}
			g++;
		}
		g = 0;
	}
	return (f);
}

int					*ft_rowhelp2(int *h, int *f, int k)
{
	int sum;
	int g;

	sum = 0;
	g = 0;
	while (g < k)
	{
		h[g] = h[g] + f[g] + sum;
		sum = 0;
		if (h[g] >= 1000)
		{
			sum = h[g] / 1000;
			h[g] = h[g] % 1000;
		}
		g++;
	}
	return (h);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldoublf_part_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <mriley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:20:51 by smanhack          #+#    #+#             */
/*   Updated: 2019/08/01 19:44:59 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*mantisdvig42(char *s, long long n)
{
	int		i;
	char	*f;

	n = 0;
	i = 1;
	f = (char*)malloc(67);
	f[0] = s[0];
	f[1] = '.';
	while (s[i] != '\0' && i < 64)
	{
		f[i + 1] = s[i];
		i++;
	}
	f[i + 1] = '\0';
	return (f);
}

char				*dvigaem(long long n, char *s)
{
	int		i;

	i = 0;
	if (n > 0 && n > 63)
		return (mantisdvig12(s, n));
	if (n < 0)
		return (mantisdvig22(s, n));
	if (n > 0 && n < 64)
		return (mantisdvig32(s, n));
	if (n == 0)
	{
		return (mantisdvig42(s, n));
	}
	return (ft_strjoin("0.", s));
}

char				*ft_mantissa(char *s)
{
	char	*mantissa;
	int		i;

	mantissa = (char*)malloc(65);
	i = 0;
	while (s[i + 16] != '\0' && i < 64)
	{
		mantissa[i] = s[i + 16];
		i++;
	}
	mantissa[i] = '\0';
	return (mantissa);
}

int					*ft_rowkul(int i, int *h, int k)
{
	int		*f;
	int		g;

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

int					*izdvatodes(char *d)
{
	int i;
	int *h;

	h = (int*)malloc(sizeof(int) * (ft_strlen(d) + 3));
	ft_bzero(h, sizeof(int) * (ft_strlen(d) + 3));
	i = 0;
	while (d[i] != '\0')
	{
		if (d[i] == '1')
			h = ft_rowkul(ft_strlen(d) - i - 1, h, ft_strlen(d));
		i++;
	}
	return (h);
}

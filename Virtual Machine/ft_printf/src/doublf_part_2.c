/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublf_part_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <mriley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 15:29:39 by smanhack          #+#    #+#             */
/*   Updated: 2019/07/31 19:37:53 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_bitstrd(unsigned char *c, int var_size)
{
	int		qt;
	char	*s;
	size_t	d;
	int		i;

	i = 0;
	s = (char*)malloc(66);
	d = var_size;
	qt = -1;
	while (--d < (size_t)var_size)
	{
		while (++qt < 8)
		{
			s[i++] = c[d] & (128 >> qt) ? '1' : '0';
		}
		qt = -1;
	}
	s[i] = '\0';
	return (s);
}

char				*ft_putbitd(void *ptr, size_t var_size)
{
	unsigned char	*mem;
	char			*s;

	mem = (unsigned char*)ptr;
	s = ft_bitstrd(mem, var_size);
	return (s);
}

unsigned long long	ft_rowd(int i, double g)
{
	unsigned long long sum;

	sum = 1;
	if (i == 0)
		return (1);
	while (i-- > 0)
	{
		sum = sum * g;
	}
	return (sum);
}

long long			chekbitd(long long n, int i)
{
	int result;

	if ((n & (1L << i)) == 0)
	{
		result = 0;
	}
	else
	{
		result = 1;
	}
	return (result);
}

long long			izdestodvad(char *s)
{
	int			h;
	int			d;
	long long	sum;

	h = 10;
	d = 10;
	sum = 0;
	while (h > -1)
	{
		if (s[h] == '1')
			sum += ft_rowd(d - h, 2);
		h--;
	}
	return (sum - 1023);
}

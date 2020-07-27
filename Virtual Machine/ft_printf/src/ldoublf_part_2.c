/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldoublf_part_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <mriley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:18:43 by smanhack          #+#    #+#             */
/*   Updated: 2019/08/01 16:46:01 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_bitstr(unsigned char *c, int var_size)
{
	int		qt;
	char	*s;
	size_t	d;
	int		i;

	i = 0;
	s = (char*)malloc(81);
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

char				*ft_putbit(void *ptr, size_t var_size)
{
	unsigned char	*mem;
	char			*s;

	mem = (unsigned char*)ptr;
	s = ft_bitstr(mem, var_size);
	return (s);
}

unsigned long long	ft_row(int i, long double g)
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

long long			chekbit(long long n, int i)
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

long long			izdestodva(char *s)
{
	int			h;
	int			d;
	long long	sum;

	h = 14;
	d = 14;
	sum = 0;
	while (h > -1)
	{
		if (s[h] == '1')
			sum += ft_row(d - h, 2);
		h--;
	}
	return (sum - 16383);
}

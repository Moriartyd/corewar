/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldoublf_part_7.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <mriley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 18:04:05 by smanhack          #+#    #+#             */
/*   Updated: 2019/08/01 18:37:39 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				toretry_part_2(t_point *p)
{
	p->znak = ft_znak(p->s);
	p->exp = ft_exp(p->s);
	p->mantissa = ft_mantissa(p->s);
}

void				ft_zero(int *j)
{
	j[0] = 0;
	j[1] = 0;
	j[2] = 0;
}

void				ft_five_bonus(int *t, int *l, long long i)
{
	t[0] = i - 1;
	t[1] = i - 1;
	t[2] = 0;
	if (i > *l)
		*l = i;
}

int					*ft_five(long long i, int *f, t_format ff, int l)
{
	int	*g;
	int t[3];

	ft_five_bonus(t, &l, i);
	g = (int*)malloc(sizeof(int) * l);
	ft_bzero(g, sizeof(int) * l);
	g[t[0]] = 1;
	while (i-- > 0)
	{
		while (t[0] > -1)
		{
			g[t[0]] = g[t[0]] * 5 + t[2];
			t[2] = 0;
			if (g[t[0]] >= 10)
			{
				t[2] = g[t[0]] / 10;
				g[t[0]] = g[t[0]] % 10;
			}
			t[0]--;
		}
		t[0] = t[1];
	}
	f = sumfive(f, g, ff);
	free(g);
	return (f);
}

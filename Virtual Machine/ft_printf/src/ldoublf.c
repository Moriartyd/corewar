/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldoublf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:05:49 by smanhack          #+#    #+#             */
/*   Updated: 2020/07/27 23:19:43 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"
#include <limits.h>

int					*dlindouble(int *f, char *h, t_format ff, int l)
{
	long long i;

	i = 0;
	while (h[i] != '\0')
	{
		if (h[i] == '1')
		{
			f = ft_five(i + 1, f, ff, l);
		}
		i++;
	}
	return (f);
}

int					*dlinayadrob(char *mantissa, t_format ff)
{
	int		*f;
	char	*h;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (mantissa[i] != '.' && mantissa[i] != '\0')
		i++;
	i++;
	h = (char*)malloc(ft_strlen(mantissa) + 3);
	ft_bzero(h, ft_strlen(mantissa) + 3);
	while (mantissa[i] != '\0')
		h[j++] = mantissa[i++];
	h[j] = '\0';
	if (ff.prec > ((int)ft_strlen(mantissa) + 3))
		i = ff.prec + 3;
	else
		i = ft_strlen(mantissa) + 3;
	f = (int*)malloc(sizeof(int) * i);
	ft_bzero(f, sizeof(int) * i);
	f = dlindouble(f, h, ff, i);
	free(h);
	return (f);
}

char				*tocotrub(char *toc)
{
	char	*new;
	int		i;

	i = 2;
	new = ft_strnew(ft_strlen(toc));
	while (i < (int)ft_strlen(toc))
	{
		new[i - 2] = toc[i];
		i++;
	}
	new[i - 2] = '\0';
	return (new);
}

void				ft_toretry_bbonus(t_point *p, t_format *ff, char **d)
{
	if (p->toc[1] == '.')
	{
		p->zifra = ft_peredelzel(p->zifra, ft_strlen(p->zifra));
		p->toc = tocotrub(p->toc);
	}
	if (ff->prec != 0)
	{
		*d = ft_strjoin(p->zifra, ".");
		free(p->zifra);
		p->zifra = *d;
		*d = ft_strjoin(p->zifra, p->toc);
		free(p->zifra);
		free(p->toc);
		free(p->mantissa);
		p->zifra = *d;
	}
}

char				*toretry(va_list ap, t_format ff)
{
	long long	i;
	long double	n;
	t_point		p;
	char		*d;

	n = va_arg(ap, long double);
	p.s = ft_putbit(&n, 10);
	toretry_part_2(&p);
	i = izdestodva(p.exp);
	p.mantissa = dvigaem(i, p.mantissa);
	p.g = todes(p.mantissa);
	p.posle = dlinayadrob(p.mantissa, ff);
	p.zifra = ft_delaem(p.g, p.znak, p.mantissa);
	p.toc = delaem1(p.posle, ff, p.mantissa, n);
	ft_toretry_bbonus(&p, &ff, &d);
	free(p.posle);
	free(p.s);
	free(p.g);
	free(p.znak);
	if ((ff.flags & 1) && ft_strchr(p.zifra, '.') == NULL)
		return (ft_strjoin(p.zifra, "."));
	return (p.zifra);
}

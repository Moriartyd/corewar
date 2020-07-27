/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 20:41:10 by mriley            #+#    #+#             */
/*   Updated: 2020/07/27 23:45:53 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"
#include <limits.h>

char	*izdvatodestocd(double n, t_format f)
{
	int		i;
	char	*h;
	int		p;
	double	g;

	i = 0;
	p = 6;
	g = n;
	n = n - (long long)n;
	(f.prec > 0) ? p = f.prec : 0;
	(f.prec == 0 || f.prec == -1) ? p = 1 : 0;
	izdvatodestocd_norm(&n, &g);
	if (((n > 0.5) || ((long long)g % 2 != 0 && n == 0.5)) && f.prec == 0)
		return (ft_strdup("1.0"));
	h = (char*)malloc(p + 2);
	while (i < p)
	{
		n = n * 10;
		h[i++] = (int)n + '0';
		n = n - (int)n;
	}
	h[p] = '\0';
	return (ft_okruglyaem(h, n * 10));
}

void	toretryd_part_2(t_point *p, long long *i, t_format *ff)
{
	p->znak = ft_znakd(p->s);
	p->exp = ft_expd(p->s);
	p->mantissa = ft_mantissad(p->s);
	*i = izdestodvad(p->exp);
	p->mantissa = dvigaemd(*i, p->mantissa);
	p->g = todesd(p->mantissa);
	p->posle = dlinayadrob(p->mantissa, *ff);
}

void	ft_toretryd_bonus(t_point *p, char **stroka, t_format *ff)
{
	if (p->toc[1] == '.')
	{
		p->zifra = ft_peredelzel(p->zifra, ft_strlen(p->zifra));
		p->toc = tocotrub(p->toc);
	}
	if (ff->prec != 0)
	{
		*stroka = ft_strjoin(p->zifra, ".");
		free(p->zifra);
		p->zifra = *stroka;
		*stroka = ft_strjoin(p->zifra, p->toc);
		ft_free(*p);
		p->zifra = *stroka;
	}
}

char	*func_infinity(char *string)
{
	if (ft_strcmp(string, K_S1) == 0)
		return (ft_strdup("inf"));
	if (ft_strcmp(string, K_S2) == 0)
		return (ft_strdup("-inf"));
	if (ft_strcmp(string, K_S3) == 0)
		return (ft_strdup("nan"));
	if (ft_strcmp(string, K_S4) == 0)
		return (ft_strdup("nan"));
	if (ft_strcmp(string, K_S5) == 0)
		return (ft_strdup("nan"));
	if (ft_strcmp(string, K_S6) == 0)
		return (ft_strdup("nan"));
	return (NULL);
}

char	*toretryd(va_list ap, t_format ff)
{
	double		n;
	long long	i;
	t_point		p;
	char		*stroka;

	(ff.prec == 0) ? ff.prec = 6 : 0;
	(ff.prec == -1) ? ff.prec = 0 : 0;
	if (ff.type == 2)
		return (toretry(ap, ff));
	n = va_arg(ap, double);
	p.s = ft_putbitd(&n, 8);
	if (func_infinity(p.s))
	{
		(ff.prec == 0) ? ff.prec = -1 : 0;
		(ff.prec == 6) ? ff.prec = 0 : 0;
		ff.sym = 's';
		return (func_infinity(p.s));
	}
	toretryd_part_2(&p, &i, &ff);
	p.zifra = ft_delaem(p.g, p.znak, p.mantissa);
	p.toc = todestocd(n, ff);
	ft_toretryd_bonus(&p, &stroka, &ff);
	if ((ff.flags & 1) && ft_strchr(p.zifra, '.') == NULL)
		return (ft_strjoin(p.zifra, "."));
	return (p.zifra);
}

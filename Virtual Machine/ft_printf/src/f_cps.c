/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_cps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 18:17:21 by smanhack          #+#    #+#             */
/*   Updated: 2019/07/18 00:43:41 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*f_c(va_list ap, t_format f)
{
	int		buf;
	char	*c;

	f.type = 0;
	c = ft_strnew(1);
	buf = va_arg(ap, int);
	*(int *)c = buf;
	return (c);
}

char	*f_s(va_list ap, t_format f)
{
	char	*buf;
	char	*s;

	f.type = 0;
	buf = va_arg(ap, char *);
	if (buf == NULL)
	{
		s = ft_strnew(6);
		s = ft_strcpy(s, "(null)");
	}
	else
	{
		s = ft_strnew(ft_strlen(buf));
		s = ft_strcpy(s, buf);
	}
	return (s);
}

char	*f_p(va_list ap, t_format f)
{
	int		*buf;
	char	*p;
	long	buf_l;

	f.type = 0;
	buf = va_arg(ap, int *);
	buf_l = (long)buf;
	p = ft_itoa_base_ull(buf_l, 16);
	return (p);
}

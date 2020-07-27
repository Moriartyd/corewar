/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublf2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 23:31:00 by cpollich          #+#    #+#             */
/*   Updated: 2020/07/27 23:38:51 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"
#include <limits.h>

void	ft_free(t_point p)
{
	free(p.mantissa);
	free(p.g);
	free(p.s);
	free(p.exp);
	free(p.zifra);
	free(p.toc);
}

void	izdvatodestocd_norm(double *n, double *g)
{
	if (*n < 0.0)
	{
		*n = -*n;
		*g = -*g;
	}
}

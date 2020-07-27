/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 11:26:35 by smanhack          #+#    #+#             */
/*   Updated: 2019/04/07 11:26:39 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	char	fl;
	long	res;
	long	buf;

	fl = 0;
	i = 0;
	res = 0;
	buf = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
		fl = str[i++] == '-';
	while (ft_isdigit(str[i]))
	{
		buf = res;
		res = res * 10 + (str[i++] - '0');
		if (buf > 0 && buf > res)
			return (fl ? 0 : -1);
	}
	if (fl == 1)
		res = -res;
	return ((int)res);
}

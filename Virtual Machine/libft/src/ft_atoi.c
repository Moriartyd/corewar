/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:47:00 by mriley            #+#    #+#             */
/*   Updated: 2019/04/18 16:06:30 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sign(char i)
{
	int sign;

	if (i == 45)
		sign = -1;
	else
		sign = 1;
	return (sign);
}

static int	maxmin(int sign)
{
	if (sign == -1)
		return (0);
	else
		return (-1);
}

int			ft_atoi(const char *str)
{
	long			i;
	long			m;
	int				sign;

	i = 0;
	m = 0;
	sign = 1;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v' ||
			str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if ((str[i] == 43) || (str[i] == 45))
		sign = ft_sign(str[++i - 1]);
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		if ((m > 2147483648 && sign == -1) || (m > 2147483647 && sign == 1))
		{
			m = maxmin(sign);
			return (m);
		}
		m = 10 * m + (str[i] - 48);
		i++;
	}
	return (m * sign);
}

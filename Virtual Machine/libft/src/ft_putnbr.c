/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:33:21 by mriley            #+#    #+#             */
/*   Updated: 2019/04/16 21:06:56 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		num(long n, long u, long y)
{
	while (u > 0)
	{
		u = u / 10;
		y = y * 10;
	}
	y = y / 10;
	while (y >= 1)
	{
		u = n / y + 48;
		write(1, &u, 1);
		n = n % y;
		y = y / 10;
	}
}

void			ft_putnbr(int n)
{
	long long		u;
	long long		y;

	y = 1;
	if (n == 0)
		write(1, "0", 1);
	else
	{
		if (n == -2147483648)
			write(1, "-2147483648", 12);
		else
		{
			if (n < 0 && n > -2147483648)
			{
				write(1, "-", 1);
				n = n * (-1);
			}
			u = n;
			num(n, u, y);
		}
	}
}

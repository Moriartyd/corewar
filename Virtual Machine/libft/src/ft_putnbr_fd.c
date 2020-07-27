/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:32:40 by mriley            #+#    #+#             */
/*   Updated: 2019/04/18 15:43:31 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		num(long n, long u, long y, int fd)
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
		write(fd, &u, 1);
		n = n % y;
		y = y / 10;
	}
}

void			ft_putnbr_fd(int n, int fd)
{
	long long		u;
	long long		y;

	y = 1;
	if (n == 0)
		write(fd, "0", 1);
	else
	{
		if (n == -2147483648)
			write(fd, "-2147483648", 12);
		else
		{
			if (n < 0 && n > -2147483648)
			{
				write(fd, "-", 1);
				n = n * (-1);
			}
			u = n;
			num(n, u, y, fd);
		}
	}
}

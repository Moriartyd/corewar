/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:08:13 by mriley            #+#    #+#             */
/*   Updated: 2019/04/16 15:22:46 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		gig1(int n)
{
	long		i;
	long		y;

	if (n < 0)
		n = n * (-1);
	i = 0;
	y = 1;
	while (n > 0)
	{
		n = n / 10;
		i++;
		y = y * 10;
	}
	return (i);
}

static	int		gig2(int n)
{
	long		i;
	long		y;

	if (n < 0)
		n = n * (-1);
	i = 0;
	y = 1;
	while (n > 0)
	{
		n = n / 10;
		i++;
		y = y * 10;
	}
	y = y / 10;
	return (y);
}

static	char	*rer(int n, int i, int j, int y)
{
	char	*s;

	s = ft_memalloc(i + 2);
	if (s == NULL)
		return (NULL);
	if (n < 0)
	{
		s[j] = '-';
		j++;
		i++;
		n = n * (-1);
	}
	while (j < i)
	{
		s[j] = n / y + 48;
		j++;
		n = n % y;
		y = y / 10;
	}
	s[j] = '\0';
	return (s);
}

static	char	*ft_zero(void)
{
	char	*d;

	d = ft_memalloc(2);
	if (d == NULL)
		return (NULL);
	d[0] = '0';
	d[1] = '\0';
	return (d);
}

char			*ft_itoa(int n)
{
	char		*s;
	long		i;
	long		y;
	long		j;

	j = 0;
	if (n < -2147483647)
	{
		i = gig1(n + 1);
		y = gig2(n + 1);
		s = rer(n + 1, i, j, y);
		s[10] = '8';
	}
	else
	{
		i = gig1(n);
		y = gig2(n);
		if (n == 0)
			s = ft_zero();
		else
			s = rer(n, i, j, y);
	}
	return (s);
}

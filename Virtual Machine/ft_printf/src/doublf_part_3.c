/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublf_part_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <mriley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 15:34:57 by smanhack          #+#    #+#             */
/*   Updated: 2019/07/27 19:57:57 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_znakd(char *s)
{
	char *znak;

	znak = (char*)malloc(3);
	znak[0] = s[0];
	znak[1] = '\0';
	return (znak);
}

char				*ft_expd(char *s)
{
	char	*exp;
	int		i;

	i = 0;
	exp = (char*)malloc(13);
	while (i < 11)
	{
		exp[i] = s[i + 1];
		i++;
	}
	exp[i] = '\0';
	return (exp);
}

char				*mantisdvig1(char *s, long long n)
{
	char *f;
	char *stroka;

	n = n - 53 + 1;
	f = (char*)malloc(n + 2);
	f[n] = '\0';
	while (n > 0)
		f[--n] = '0';
	stroka = ft_strjoin(s, f);
	free(f);
	free(s);
	s = stroka;
	stroka = ft_strjoin(s, ".0");
	free(s);
	s = stroka;
	return (s);
}

char				*mantisdvig2(char *s, long long n)
{
	char *f;

	n = -n;
	f = (char*)malloc(n + 1);
	f[n] = '\0';
	while (n > 0)
		f[--n] = '0';
	f = ft_strjoin(f, s);
	f = ft_strjoin("0.", f);
	return (f);
}

char				*mantisdvig3(char *s, long long n)
{
	int		i;
	char	*f;

	i = 0;
	f = (char*)malloc(60);
	while (n > -1)
	{
		f[i] = s[i];
		i++;
		n--;
	}
	f[i] = '.';
	i++;
	while (s[i - 1] != '\0' && i < 53)
	{
		f[i] = s[i - 1];
		i++;
	}
	f[i] = '\0';
	return (f);
}

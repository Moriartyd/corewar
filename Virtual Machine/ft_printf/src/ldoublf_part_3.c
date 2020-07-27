/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldoublf_part_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <mriley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:19:55 by smanhack          #+#    #+#             */
/*   Updated: 2019/07/27 16:21:27 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_znak(char *s)
{
	char	*znak;

	znak = (char*)malloc(2);
	znak[0] = s[0];
	znak[1] = '\0';
	return (znak);
}

char				*ft_exp(char *s)
{
	char	*exp;
	int		i;

	exp = (char*)malloc(17);
	i = 0;
	while (i < 15)
	{
		exp[i] = s[i + 1];
		i++;
	}
	exp[i] = '\0';
	return (exp);
}

char				*mantisdvig12(char *s, long long n)
{
	char *f;
	char *stroka;

	n = n - 63;
	f = (char*)malloc(n + 2);
	f[n] = '\0';
	while (n > 0)
	{
		f[n - 1] = '0';
		n--;
	}
	stroka = ft_strjoin(s, f);
	free(f);
	free(s);
	s = stroka;
	stroka = ft_strjoin(s, ".0");
	free(s);
	s = stroka;
	return (s);
}

char				*mantisdvig22(char *s, long long n)
{
	char *f;
	char *stroka;

	n = -n - 1;
	f = (char*)malloc(n + 1);
	f[n] = '\0';
	while (n > 0)
	{
		f[n - 1] = '0';
		n--;
	}
	stroka = ft_strjoin(f, s);
	free(f);
	free(s);
	s = stroka;
	stroka = ft_strjoin("0.", s);
	free(s);
	s = stroka;
	return (s);
}

char				*mantisdvig32(char *s, long long n)
{
	int		i;
	char	*f;

	i = 0;
	f = (char*)malloc(66);
	while (n > -1)
	{
		f[i] = s[i];
		n--;
		i++;
	}
	f[i] = '.';
	i++;
	while (s[i - 1] != '\0' && i < 63)
	{
		f[i] = s[i - 1];
		i++;
	}
	f[i] = '\0';
	return (f);
}

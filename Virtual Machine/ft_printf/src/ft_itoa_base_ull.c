/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ull.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 14:31:28 by noobythetur       #+#    #+#             */
/*   Updated: 2019/07/18 00:44:53 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_len(unsigned long long nb, int base)
{
	int	k;

	k = 1;
	while ((nb /= base) != 0)
		k++;
	return (k);
}

static	char	*ft_go(char *str, int k, unsigned long long value, int base)
{
	int			sym;

	while (k--)
	{
		sym = value % base;
		if (sym >= 10 && sym <= 15)
			str[k] = 'a' + sym % 10;
		else
			str[k] = sym + 48;
		value /= base;
	}
	return (str);
}

char			*ft_itoa_base_ull(unsigned long long value, int base)
{
	int			k;
	char		*str;

	k = ft_len(value, base);
	if (base < 2 || base > 16)
		return (NULL);
	if ((str = (char*)malloc(sizeof(char) * (k + 1))) != NULL)
		str[k] = '\0';
	return (ft_go(str, k, value, base));
}

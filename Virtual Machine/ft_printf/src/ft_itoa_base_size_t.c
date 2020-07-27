/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_size_t.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 16:02:13 by smanhack          #+#    #+#             */
/*   Updated: 2019/07/30 16:18:21 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

static	int		ft_len(size_t nb, int base)
{
	int	k;

	k = 1;
	while ((nb /= base) != 0)
		k++;
	return (k);
}

static	char	*ft_go(char *str, int k, size_t value, int base)
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

char			*ft_itoa_base_size_t(size_t value, int base)
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

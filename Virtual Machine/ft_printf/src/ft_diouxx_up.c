/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diouxx_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 19:57:42 by smanhack          #+#    #+#             */
/*   Updated: 2019/07/30 16:43:24 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_di(va_list ap, t_format f)
{
	if (f.type == 0)
		return (ft_itoa(va_arg(ap, int)));
	else if (f.type == 1)
		return (ft_itoa_ll(va_arg(ap, long int)));
	else if (f.type == 2)
		return (ft_itoa_ll(va_arg(ap, long long int)));
	else if (f.type == -1)
		return (ft_itoa((short int)va_arg(ap, int)));
	else if (f.type == -2)
		return (ft_itoa((char)va_arg(ap, int)));
	else if (f.type == 3)
		return (ft_itoa_intmax_t(va_arg(ap, intmax_t)));
	else if (f.type == 4)
		return (ft_itoa_ssize_t(va_arg(ap, ssize_t)));
	return (0);
}

char	*ft_o(va_list ap, t_format f)
{
	if (f.type == 0)
		return (ft_itoa_base_ull(va_arg(ap, unsigned int), 8));
	else if (f.type == 1)
		return (ft_itoa_base_ull(va_arg(ap, unsigned long), 8));
	else if (f.type == 2)
		return (ft_itoa_base_ull(va_arg(ap, unsigned long long), 8));
	else if (f.type == -1)
		return (ft_itoa_base_ull((unsigned short int)va_arg(ap, int), 8));
	else if (f.type == -2)
		return (ft_itoa_base_ull((unsigned char)va_arg(ap, int), 8));
	else if (f.type == 3)
		return (ft_itoa_base_uintmax_t(va_arg(ap, uintmax_t), 8));
	else if (f.type == 4)
		return (ft_itoa_base_size_t(va_arg(ap, size_t), 8));
	return (0);
}

char	*ft_u(va_list ap, t_format f)
{
	if (f.type == 0)
		return (ft_itoa_base_ull(va_arg(ap, unsigned int), 10));
	else if (f.type == 1)
		return (ft_itoa_base_ull(va_arg(ap, unsigned long), 10));
	else if (f.type == 2)
		return (ft_itoa_base_ull(va_arg(ap, unsigned long long), 10));
	else if (f.type == -1)
		return (ft_itoa_base_ull((unsigned short int)va_arg(ap, int), 10));
	else if (f.type == -2)
		return (ft_itoa_base_ull((unsigned char)va_arg(ap, int), 10));
	else if (f.type == 3)
		return (ft_itoa_base_uintmax_t(va_arg(ap, uintmax_t), 10));
	else if (f.type == 4)
		return (ft_itoa_base_size_t(va_arg(ap, size_t), 10));
	return (0);
}

char	*ft_x(va_list ap, t_format f)
{
	if (f.type == 0)
		return (ft_itoa_base_ull(va_arg(ap, unsigned int), 16));
	else if (f.type == 1)
		return (ft_itoa_base_ull(va_arg(ap, unsigned long), 16));
	else if (f.type == 2)
		return (ft_itoa_base_ull(va_arg(ap, unsigned long long), 16));
	else if (f.type == -1)
		return (ft_itoa_base_ull((unsigned short int)va_arg(ap, int), 16));
	else if (f.type == -2)
		return (ft_itoa_base_ull((unsigned char)va_arg(ap, int), 16));
	else if (f.type == 3)
		return (ft_itoa_base_uintmax_t(va_arg(ap, uintmax_t), 16));
	else if (f.type == 4)
		return (ft_itoa_base_size_t(va_arg(ap, size_t), 16));
	return (0);
}

char	*ft_x_up(va_list ap, t_format f)
{
	char	*x_up;
	int		i;

	x_up = ft_x(ap, f);
	i = 0;
	while (x_up[i])
	{
		x_up[i] = ft_toupper(x_up[i]);
		i++;
	}
	return (x_up);
}

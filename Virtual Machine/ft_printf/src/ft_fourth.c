/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fourth.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <mriley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 16:25:30 by smanhack          #+#    #+#             */
/*   Updated: 2019/08/29 15:27:20 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_precision(t_format *f, const char *frmt, int *i, va_list ap)
{
	if (frmt[*i] == '*')
	{
		if (frmt[(*i) - 1] == '.')
		{
			f->prec = va_arg(ap, int);
			f->prec = f->prec ? f->prec : -1;
			if (f->prec < -1)
				f->prec = 0;
		}
		else
		{
			f->width = va_arg(ap, int);
			if (f->width < 0)
			{
				f->width = -f->width;
				f->flags |= 4;
			}
		}
	}
}

t_format	ft_format(const char *frmt, int j, char sym, va_list ap)
{
	int			i;
	t_format	f;

	ft_bzero(&f, sizeof(f));
	i = 0;
	f.sym = sym;
	while (i < j)
	{
		if (frmt[i] == '.')
		{
			f.prec = ft_atoi(frmt + i + 1);
			f.prec = f.prec ? f.prec : -1;
			if (ft_isdigit(*(frmt + i + 1)))
				i += ft_number_of_digits(f.prec);
		}
		else
			ft_format_part_2(&f, frmt, &i);
		ft_precision(&f, frmt, &i, ap);
		i++;
	}
	if (f.flags & 4 || f.prec)
		f.flags &= ~(2);
	if ((f.flags & 8 || f.flags & 2) && f.sym != 'd' && f.sym != 'i')
		f.flags &= ~(16);
	return (f);
}

char		*ft_u_up(va_list ap, t_format f)
{
	f.type += 2;
	return (ft_u(ap, f));
}

char		*ft_b(va_list ap, t_format f)
{
	if (f.type == 0)
		return (ft_itoa_base_ull(va_arg(ap, unsigned int), 2));
	else if (f.type == 1)
		return (ft_itoa_base_ull(va_arg(ap, unsigned long), 2));
	else if (f.type == 2)
		return (ft_itoa_base_ull(va_arg(ap, unsigned long long), 2));
	else if (f.type == -1)
		return (ft_itoa_base_ull((unsigned short int)va_arg(ap, int), 2));
	else if (f.type == -2)
		return (ft_itoa_base_ull((unsigned char)va_arg(ap, int), 2));
	else if (f.type == 3)
		return (ft_itoa_base_uintmax_t(va_arg(ap, uintmax_t), 2));
	else if (f.type == 4)
		return (ft_itoa_base_size_t(va_arg(ap, size_t), 2));
	return (0);
}

int			ft_print(char *buff, t_format f)
{
	int		count;

	count = ft_strlen(buff);
	if (*buff == '-' && f.sym != 'c')
		count--;
	if (*buff == '\0' && f.sym == 'c')
		count = 1;
	if (count == 1 && *buff == '0' && f.prec == -1 && f.sym != 'f'
		&& !(f.sym == 'o' && (f.flags & 1) == 1))
	{
		count = 0;
		while (f.width-- > 0)
			count += ft_write(" ");
		if (f.sym == 'p')
			count += ft_ox(f, buff);
		return (count);
	}
	if (f.prec < count)
		f.prec = count;
	if (f.width < f.prec)
		f.width = f.prec;
	f.width -= f.prec;
	ft_print_part_2(&f, &count, buff);
	ft_print_part_3(&f, &count, buff);
	return (count);
}

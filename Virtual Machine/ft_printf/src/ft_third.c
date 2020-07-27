/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_third.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 00:58:03 by smanhack          #+#    #+#             */
/*   Updated: 2019/08/02 19:52:51 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_part_2(t_format *f, int *count, char *buff)
{
	f->prec -= *count;
	if (((f->flags & 1) && (ft_strchr("oxX", f->sym)) != NULL) || f->sym == 'p')
	{
		if (f->sym == 'o')
		{
			if (f->prec <= *count)
				f->width--;
		}
		else
			f->width -= 2;
	}
	if ((f->flags & 8) && *buff != '-')
		f->width--;
	if ((f->flags & 16) && !(f->flags & 8) && *buff != '-')
		f->width--;
	if (*buff == '-')
		f->width--;
	if (!(f->flags & 2) && !(f->flags & 4))
		while (f->width-- > 0)
			*count += ft_write(" ");
	if ((f->flags & 8) && *buff != '-')
		*count += ft_write("+");
	if ((f->flags & 16) && !(f->flags & 8) && *buff != '-')
		*count += ft_write(" ");
}

void	ft_print_part_3(t_format *f, int *count, char *buff)
{
	if (*buff == '-' && f->sym != 'c')
	{
		*count += ft_write("-");
		buff++;
	}
	if ((f->flags & 1 && *buff != '0') || f->sym == 'p')
		*count += ft_ox(*f, buff);
	if (!(f->flags & 4) && (f->flags & 2))
		while (f->width-- > 0)
			*count += ft_write("0");
	while (f->prec-- > 0)
		*count += ft_write("0");
	ft_putprint(buff, f->sym);
	while (f->width-- > 0)
		*count += ft_write(" ");
}

void	ft_putprint(char *buff, char c)
{
	if (*buff == '\0' && c == 'c')
		write(1, "\0", 1);
	else
		write(1, buff, ft_strlen(buff));
}

int		ft_write(char *str)
{
	write(1, str, 1);
	return (1);
}

void	ft_format_part_2(t_format *f, const char *frmt, int *i)
{
	if (frmt[*i] == '0')
		f->flags |= 2;
	else if (frmt[*i] == '#')
		f->flags |= 1;
	else if (ft_isdigit(frmt[*i]))
	{
		f->width = ft_atoi(frmt + (*i));
		*i += ft_number_of_digits(f->width) - 1;
	}
	else if (frmt[*i] == '-')
		f->flags |= 4;
	else if (frmt[*i] == '+')
		f->flags |= 8;
	else if (frmt[*i] == ' ')
		f->flags |= 16;
	else if (frmt[*i] == 'l')
		f->type++;
	else if (frmt[*i] == 'h')
		f->type--;
	else if (frmt[*i] == 'L')
		f->type = 2;
	else if (frmt[*i] == 'j')
		f->type = 3;
	else if (frmt[*i] == 'z')
		f->type = 4;
}

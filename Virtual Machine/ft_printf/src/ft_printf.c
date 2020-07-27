/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 00:53:22 by smanhack          #+#    #+#             */
/*   Updated: 2019/08/02 19:26:41 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_conv	g_conv[] =
{
	{'c', &f_c},
	{'s', &f_s},
	{'p', &f_p},
	{'d', &ft_di},
	{'i', &ft_di},
	{'o', &ft_o},
	{'u', &ft_u},
	{'U', &ft_u_up},
	{'x', &ft_x},
	{'X', &ft_x_up},
	{'%', &ft_percent},
	{'f', &toretryd},
	{'b', &ft_b},
	{'r', &ft_rainbow},
	{'\0', NULL}
};

static	int		ft_valid(const char *frmt)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (ft_strchr("%#0+- hlzjL", frmt[i]) != NULL && (frmt[i] != '\0'))
		i++;
	while (ft_strchr("%cprs123456789.diouxXf", frmt[i]) == NULL && (frmt[i]
	!= '\0'))
	{
		write(1, (frmt + i), 1);
		count++;
		i++;
	}
	return (count);
}

void			ft_printf_part_777(char **buff, t_format *f, t_count *reg,
		int *count)
{
	*buff = ft_correct(*buff, f, g_conv[reg->i].conv);
	*count += ft_print(*buff, *f);
	free(*buff);
}

int				ft_printf_part_1(t_count *reg, int *count, const char *frmt,
va_list *ap)
{
	t_format	f;
	char		*buff;

	reg->j = 0;
	while (frmt[reg->j] && (reg->i = 0) == 0)
	{
		while (g_conv[reg->i].conv)
		{
			if (g_conv[reg->i].conv == frmt[reg->j])
			{
				f = ft_format(frmt, reg->j, g_conv[reg->i].conv, *ap);
				if (ft_fix(&f, g_conv[reg->i].conv, frmt, reg->j) == -1)
					return (-1);
				if ((buff = g_conv[reg->i].f(*ap, f)) == NULL)
					exit(0);
				ft_printf_part_777(&buff, &f, reg, count);
				break ;
			}
			reg->i++;
		}
		if ((reg->j++) > -1 && g_conv[reg->i].conv)
			break ;
	}
	return (0);
}

static	void	ft_printf_start(t_count *reg, int *count, const char **frmt,
va_list *ap)
{
	if (**frmt != '\0')
	{
		if (ft_printf_part_1(reg, count, *frmt, ap) == 0)
		{
			if ((*frmt += reg->j) != NULL && g_conv[reg->i].conv == 0)
			{
				reg->i = ft_valid(*frmt - reg->j);
				*count += reg->i;
			}
		}
		else
		{
			while (ft_strchr("#0+- hlLzj123456789.*", **frmt) != NULL
			&& (**frmt != '\0'))
				(*frmt)++;
		}
	}
}

int				ft_printf(const char *frmt, ...)
{
	va_list		ap;
	int			count;
	t_count		reg;

	va_start(ap, frmt);
	count = 0;
	while (*frmt)
	{
		if (*(frmt++) == '%')
			ft_printf_start(&reg, &count, &frmt, &ap);
		else
		{
			count++;
			write(1, frmt - 1, 1);
		}
	}
	va_end(ap);
	return (count);
}

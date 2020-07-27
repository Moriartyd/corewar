/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_second.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 01:31:07 by smanhack          #+#    #+#             */
/*   Updated: 2019/07/30 16:16:28 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_percent(va_list ap, t_format f)
{
	char *c;

	(void)ap;
	(void)f;
	c = ft_strnew(1);
	c[0] = '%';
	return (c);
}

int		ft_ox(t_format f, char *buff)
{
	if (f.sym == 'o')
	{
		if (f.prec <= (int)ft_strlen(buff))
		{
			write(1, "0", 1);
			return (1);
		}
	}
	else if (f.sym == 'X' || f.sym == 'x' || f.sym == 'p')
	{
		if (f.sym == 'X')
			write(1, "0X", 2);
		else
			write(1, "0x", 2);
		return (2);
	}
	return (0);
}

int		ft_fix(t_format *f, char c, const char *frmt, int j)
{
	int i;

	if (c == 'c' || c == 's' || c == '%')
		f->flags &= 6;
	if (c == 'p' || c == 'u')
		f->flags &= 6;
	if (c == 'x' || c == 'X' || c == 'o')
		f->flags &= 7;
	i = 0;
	while (i < j)
	{
		if (ft_strchr("#0+- hlLjz123456789.*", frmt[i]) == NULL &&
		(frmt[i] != '\0'))
			return (-1);
		i++;
	}
	return (0);
}

char	*ft_correct(char *buff, t_format *f, char c)
{
	char	*str;
	int		count;

	count = ft_strlen(buff);
	if ((c == 'c' || c == 's') && (count > (*f).prec) && (*f).prec != 0)
	{
		if ((*f).prec == -1)
			(*f).prec = 0;
		str = ft_strnew((*f).prec);
		str = ft_strncpy(str, buff, (*f).prec);
		free(buff);
		(*f).prec = 0;
		return (str);
	}
	if (c == 'c' || c == 's')
		(*f).prec = 0;
	return (buff);
}

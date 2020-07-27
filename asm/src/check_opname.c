/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_opname.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 19:48:26 by cpollich          #+#    #+#             */
/*   Updated: 2020/07/27 14:58:48 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	Между инструкцией и аргументтами должен быть пробел/таб,
**	если первый аргумен - T_REG
*/

int	is_blank(char *str)
{
	char	*s;

	if (!(s = ft_str_white_trim(str)))
		return (1);
	if (ft_strlen(s) == 1 && *s == '\n')
		return (ft_strdel(&s));
	if (*s == COMMENT_CHAR || *s == ALT_COMMENT_CHAR)
		return (ft_strdel(&s));
	ft_strdel(&s);
	return (0);
}

int	sep_char(char c)
{
	if (c == '\t' || c == ' '
		|| c == SEPARATOR_CHAR || c == '\n' || c == COMMENT_CHAR
			|| c == ALT_COMMENT_CHAR)
		return (1);
	return (0);
}

int	need_char(char c)
{
	if (c == DIRECT_CHAR || c == '\t' || c == ' ' || c == '-')
		return (1);
	return (0);
}

int	check_opname(char *str)
{
	if (*str == 'a')
		return (a_check(str));
	else if (*str == 'f')
		return (fxoz_check(str));
	else if (*str == 'l')
		return (l_check(str));
	else if (*str == 'o')
		return (fxoz_check(str));
	else if (*str == 's')
		return (s_check(str));
	else if (*str == 'x')
		return (fxoz_check(str));
	else if (*str == 'z')
		return (fxoz_check(str));
	else
		return (-1);
}

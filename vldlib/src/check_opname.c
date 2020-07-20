/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_opname.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 19:48:26 by cpollich          #+#    #+#             */
/*   Updated: 2020/07/20 20:10:20 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	Между инструкцией и аргументтами должен быть пробел/таб,
**	если первый аргумен - T_REG
*/

int			sep_char(char c)
{
	if (c == '\t' || c == ' '
		|| c == SEPARATOR_CHAR || c == '\n' || c == COMMENT_CHAR)
		return (1);
	return (0);
}

int			need_char(char c)
{
	if (c == DIRECT_CHAR || c == '\t' || c == ' ' || c == '-')
		return (1);
	return (0);
}

int			check_opname(char *str)
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
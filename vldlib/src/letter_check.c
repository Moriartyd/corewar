/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letter_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 23:01:56 by cpollich          #+#    #+#             */
/*   Updated: 2020/07/20 20:10:20 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			s_check(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] >= 'a' && str[i] <= 'z')
		i++;
	if (str[i] && !need_char(str[i]) && i != 2 && i != 3)
		return (-1);
	if (i == 2)
		if (str[1] == 't')
			return (OP_ST);
	if (i == 3)
	{
		if (str[1] == 't' && str[2] == 'i')
			return (OP_STI);
		if (str[1] == 'u' && str[2] == 'b')
			return (OP_SUB);
	}
		return (-1);
}

int			fxoz_check(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] >= 'a' && str[i] <= 'z')
		i++;
	if (str[i] && str[i + 1] && !need_char(str[i + 1]) &&
				i != 2 && i != 3 && i != 4)
		return (-1);
	if (i == 2)
		if (str[1] == 'r')
			return (OP_OR);
	if (i == 3)
		if (str[1] == 'o' && str[2] == 'r')
			return (OP_XOR);
	if (i == 4)
	{
		if (!ft_strncmp(str, STR_ZJMP, 4))
			return (OP_ZJMP);
		if (!ft_strncmp(str, STR_FORK, 4))
			return (OP_FORK);
	}
	return (-1);
}

int			a_check(char *str)
{
	int	i;

	i = 1;
	if (str[i] == 'd' &&
		(str[i + 1] && str[i + 1] == 'd') &&
			(str[i + 2] && need_char(str[i + 2])))
				return (OP_ADD);
	else if (str[i] == 'f' &&
		(str[i + 1] && str[i + 1] == 'f') &&
			(str[i + 2] && need_char(str[i + 2])))
				return (OP_AFF);
	else if (str[i] == 'n' &&
		(str[i + 1] && str[i + 1] == 'd') &&
			(str[i + 2] && need_char(str[i + 2])))
				return (OP_AND);
	else
		return (-1);
}

static int	l_check_norm(char *str, int i)
{
	if (i == 4 && !ft_strncmp(str, STR_LIVE, 4))
			return (OP_LIVE);
	if (i == 5 && !ft_strncmp(str, STR_LFORK, 5))
			return (OP_LFORK);
	return (-1);
}

int			l_check(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] >= 'a' && str[i] <= 'z')
		i++;
	if (str[i] && str[i + 1] && !need_char(str[i + 1]) &&
				i != 2 && i != 3 && i != 4 && i != 5)
		return (-1);
	if (i == 2 && str[1] == 'd')
		return (OP_LD);
	if (str[1] == 'd')
	{
		if (i == 2)
			return (OP_LD);
		if (i == 3 && str[2] == 'i')
			return (OP_LDI);
	}
	if (str[1] == 'l')
	{
		if (i == 3 && str[2] == 'd')
			return (OP_LLD);
		if (i == 4 && str[2] == 'd' && str[3] == 'i')
			return (OP_LLDI);
	}
	return (l_check_norm(str, i));
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 19:41:22 by cpollich          #+#    #+#             */
/*   Updated: 2020/07/20 21:08:59 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**							Описание p[5]
**		+ 0 - Имя
**		+ 1 - Комментарий чемпиона
**		+ 2 - пустая строка
**		+ 3 - Начало метки
**		+ 4 - Инструкция
*/

static int	is_namecomm(char *str)
{
	size_t	i;

	i = 0;
	//printf("NCS=%s---CCS=%s-\n",NAME_CMD_STRING, COMMENT_CMD_STRING);
	while (str[i] && (str[i] == NAME_CMD_STRING[i]
					|| str[i] == COMMENT_CMD_STRING[i]))
	{
		//printf("i=%d,---NAMECOMSTR[i]=%c////NCS[i]=%c///CCS[i]=%c\n",i, str[i], NAME_CMD_STRING[i], COMMENT_CMD_STRING[i]);
		i++;
	}
	//printf("i=%d // str-isnamecomm=%s\n",i, str);
	if (i == ft_strlen(NAME_CMD_STRING))
		return (0);
	else if (i == ft_strlen(COMMENT_CMD_STRING))
		return (1);
	else
	{
		return (-1);
	}
}

static int	is_labelinst(char *str)
{
	if (is_label(str))
		return (3);
	else if (is_inst(str) > 0)
		return (4);
	else
		return (-1);
}

int			get_type(char **str, int bytes, int fd, t_hero **hero)
{
	int		type;
	char	*s;

	if (!*str && bytes == -2)
		quit(EN_MALLOC, NULL, NULL);
	if (!(s = ft_str_white_trim(*str)) ||
			(ft_strlen(*str) == 1 && **str == '\n'))
		return (2);
	ft_strdel(str);
	if (s[0] == COMMENT_CHAR || s[0] == ALT_COMMENT_CHAR)
	{
		ft_strdel(&s);
		return (2);
	}
	if (((type = is_namecomm(s)) != -1))
		if (check_namecomm(&s, type, fd, hero) >= 0)
			return (type);
//	printf("TYPE=%d\n",type);
	if ((type = is_labelinst(s)) > 0)
	{
//		printf("INSTLABELtype=%d\n", type);
		return (parse_instruct(s, type, fd, hero));
	}
//	printf("SECTYPEislabelTYPE=%d\n",type);
	return (-1);
}

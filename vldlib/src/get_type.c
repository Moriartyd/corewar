/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 19:41:22 by cpollich          #+#    #+#             */
/*   Updated: 2020/07/18 19:55:40 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vldlib.h"

/*
**							Описание p[5]
**		+ 0 - Имя
**		+ 1 - Комментарий чемпиона
**		+ 2 - Комментарий к коду
**		+ 3 - Начало метки
**		+ 4 - Инструкция
**		+ 5 - Пустая строка
*/

static int	is_namecomm(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == NAME_CMD_STRING[i]
					|| str[i] == COMMENT_CMD_STRING[i]))
		i++;
	if (i == ft_strlen(NAME_CMD_STRING))
		return (0);
	else if (i == ft_strlen(COMMENT_CMD_STRING))
		return (1);
	else
		return (-1);
}

static int	is_labelinst(char *str, t_hero **hero)
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
		exit(-1); // Ошибка в малоке
	if (!(s = ft_str_white_trim(*str)) ||
			(ft_strlen(*str) == 1 && **str == '\n'))
		return (5);
	ft_strdel(str);
	if (s[0] == COMMENT_CHAR || s[0] == ALT_COMMENT_CHAR)
	{
		ft_strdel(&s);
		return (2);
	}
	if (((type = is_namecomm(s)) != -1))
		if (check_namecomm(s, type, fd, hero) >= 0)
			return (type);
	if ((type = is_labelinst(s, hero)) > 0)
		parse_instruct(s, type, fd, hero);
	return (-1);
}

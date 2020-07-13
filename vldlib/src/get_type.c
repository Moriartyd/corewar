/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 19:41:22 by cpollich          #+#    #+#             */
/*   Updated: 2020/07/13 19:07:15 by cpollich         ###   ########.fr       */
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

int			get_type(char *str, int bytes, int fd)
{
	int		type;
	char	*s;

	if (!str && bytes == -2)
		exit(-1); // Ошибка в малоке
	if (!(s = ft_str_white_trim(str)))
		return (5);
	if (s[0] == COMMENT_CHAR || s[0] == ALT_COMMENT_CHAR)
	{
		ft_strdel(&s);
		return (2);
	}
	if (((type = is_namecomm(s)) != -1))
		if (check_namecomm(s, type, fd) >= 0)
			return (type);
	return (2);
}

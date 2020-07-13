/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 18:02:00 by cpollich          #+#    #+#             */
/*   Updated: 2020/07/13 19:11:49 by cpollich         ###   ########.fr       */
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

static int	tail_check(char *tail)
{
	int	i;

	i = 0;
	while (tail[i] && (tail[i] == '\t' || tail[i] == ' '))
		i++;
	if (tail[i] && (tail[i] == COMMENT_CHAR || tail[i] == ALT_COMMENT_CHAR))
		return (1);
	else if (!tail[i])
		return (1);
	else
		return (0);
}

static int	mnogostrok(char **str, int fd, int type)
{
	char	*protail;
	char	*tail;
	char	*tmp;

	ft_read_until_ch(fd, '"', &protail);
	ft_read_until_ch(fd, '\n', &tail);
	if (!tail_check(tail))
		exit(-1); //Мусор в окончании
	if (!(tmp = ft_strjoin(*str, protail)))
		exit (-1); //Malloc error
	ft_strdel(str);
	ft_strdel(&protail);
	*str = tmp;
	return (type);
}

int			check_namecomm(char *str, int type, int fd)
{
	int	len;
	int	n;

	len = type ? ft_strlen(COMMENT_CMD_STRING) : ft_strlen(NAME_CMD_STRING);
	if (ft_strlen(str) <= len ||
				(str[len] != '\t' && str[len] != ' ' && str[len] != '"'))
		exit (-1); //Ошибка в имени/комменте
	while (str[len] == '\t' || str[len] == ' ')
		len++;
	if (str[len] == '"')
	{
		if (ft_countch(&str[len], '"') == 2)
		{
			n = strrchr(&str[len], '"') - strchr(&str[len], '"') - 1;
			if (!tail_check(strrchr(&str[len], '"') + 1))
				exit(-1); //Мусор в конце строки
			len = type ? COMMENT_LENGTH : PROG_NAME_LENGTH;
			if (n > len)
				exit(-1); //Слишком много символов в имени/комменте
			return (type);
		}
		else
			return (mnogostrok(&str, fd, type));
	}
	else
		exit(-1); // Отсутствует имя/коммент
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:18:50 by cpollich          #+#    #+#             */
/*   Updated: 2020/07/13 18:41:12 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vldlib.h"

/*
**	От начала файла до первой записи может быть сколько угодно пустых строчек
**	Имя и комментарий чампиона могут меняться местами
**	Файл может начаться с комментария к коду
**	Между NAME_CMD и строкой может быть сколько угодно пробелов и только пробелов
**	Между NAME_CMD и строкой может вообще ничего не быть
**	Если строка началась с COMMENT_CHAR, то ее можно не проверять
**	Строчек между командами/комментами/именем/итд может быть сколько угодно
**	Строка может начинаться и оканчиваться whitespaces
**	Метка состоит только из LABEL_CHARS
*/

/*
**							Описание p[5]
**		+ p[0] - Имя
**		+ p[1] - Комментарий чемпиона
**		+ p[2] - Комментарий к коду
**		+ p[3] - Начало метки
**		+ p[4] - инструкция
*/

void	check_file(int fd)
{
	char	*str;
	int		p[5];
	int		t;
	int		bytes;

	ft_bzero(p, 5);
	while ((bytes = ft_read_until_ch(fd, '\n', &str)) >= 0 || bytes == -3)
	{
		t = get_type(str, bytes, fd);
		if (p[t] == 1 && (t == 0 || t == 1))
			exit(-1); //Два имени или коммента чемпиона
	}
	if (bytes == -1)
		exit(-1); //Ошибка при чтении до символа
}
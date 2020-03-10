/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 19:05:27 by cpollich          #+#    #+#             */
/*   Updated: 2020/03/10 21:11:36 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vldlib.h"
#include "fcntl.h"

/*
**	От начала файла до первой записи может быть сколько угодно пустых строчек
**	Имя и коммент могут меняться местами
**	Файл может начаться с комментария к коду
**	Между NAME_CMD и строкой может быть сколько угодно пробелов
**	Между NAME_CMD и строкой может вообще ничего не быть
**	Если строка началась с COMMENT_CHAR, то ее можно не проверять
**	Строчек между командами/комментами/именем/итд может быть сколько угодно
*/

int check_asm_name(char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	while (ft_gnl(fd, &line) > 0)
	{
		//проверить с чего начинается строка
		
		if (ft_strequ)
	}
	close(fd);
}

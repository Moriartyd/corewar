/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_checker2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 19:05:27 by cpollich          #+#    #+#             */
/*   Updated: 2020/07/06 17:25:40 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vldlib.h"
#include "fcntl.h"

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

void	check_begin(int *p, char *str, t_hero *hero)
{
	size_t	nlen;
	size_t	clen;

	if (str[0] == COMMENT_CHAR)
	{
		p[2] = 1;
		return ;
	}
	nlen = ft_strlen(NAME_CMD_STRING);
	if (ft_strnequ(str, NAME_CMD_STRING, nlen) && 
			(str[nlen] == ' ' || str[nlen] == '"'))
	{
		if (check_name(&str[nlen]), hero)
			p[0] = 1;
		else
			//вывести что не так и завершить прогу
		return ;
	}
	// clen = ft_strlen(COMMENT_CMD_STRING);
	// if (ft_strnequ(str, COMMENT_CMD_STRING, clen) && 
	// 		(ft_iswhitespace(str[clen]) || str[clen] == '"'))
	// {
	// 	if (check_comment(&str[clen]))
	// 		p[1] = 1;
	// 	else
	// 		//вывести что не так и завершить прогу
	// 	return ;
	// }
}

/*
**							Описание p[5]
**		+ p[0] - Имя
**		+ p[1] - Комментарий чампиона
**		+ p[2] - Комментарий к коду
**		+ p[3] - Начало метки
**		+ p[4] - инструкция
*/

int check_asm(char *file, t_hero *hero)
{
	int		fd;
	char	*line;
	char	*trim;
	int		p[5];

	ft_bzero((void*)p, sizeof(int) * 5);
	fd = open(file, O_RDONLY);
	while (ft_gnl(fd, &line) > 0)
	{
		//проверить первый символ
		//если не comment_char, то проверять NAME|CMD STRING
		//скипнуть whitespaces
		trim = ft_strtrim(line);
		ft_strdel(&line);
		if (!p[0] || !p[1])
			check_begin(p, trim, hero);
	}
	close(fd);
	return (1);
}

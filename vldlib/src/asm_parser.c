/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:18:50 by cpollich          #+#    #+#             */
/*   Updated: 2020/07/20 21:08:59 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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

int		check_last_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (!str[i])
		return (1);
	else
		return (0);
}

void	read_file(int fd, t_hero **hero)
{
	char	*str;
	int		p[5];
	int		t;
	int		bytes;

	ft_bzero(p, sizeof(int) * 5);
	while ((bytes = ft_read_until_ch(fd, '\n', &str)) >= 0)// || bytes == -3)
	{
		printf("/Users/student/corewarte/parserasm/vldlib \n");
		printf("str=%s\\\\\\|", str);
		if (!ft_strchr(str, '\n'))
			quit(EN_LASTSTR, NULL, NULL);
		if ((t = get_type(&str, bytes, fd, hero)) == -1)
			quit(EN_TRASH, NULL, NULL);
		if (p[t] == 1 && (t == 0 || t == 1))
			quit(EN_MORENAMES, NULL, NULL);
		if (t == 3)
		{
			p[3] = 1;
			p[4] = 1;
		}
		p[t] = 1;
	}
	printf("almost end of reading cycle end\n");
	if (bytes == -1 || bytes == -2)
		exit(-1); //Ошибка при чтении до символа
	if (bytes == -3 && !ft_strchr(str, '\n') && !check_last_str(str))
		quit(EN_LASTSTR, NULL, NULL);
	if (str)
		ft_strdel(&str);
	ft_strdel(&str);
}
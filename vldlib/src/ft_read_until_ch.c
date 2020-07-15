/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_until_ch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 22:28:07 by cpollich          #+#    #+#             */
/*   Updated: 2020/07/15 16:05:24 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vldlib.h"

/*
**	Читает открытый файл до символа c
**	и записывает каждый символ в строку str
**	Выделяет память для строки str
**	Возвращаемое значение:	- количество считанных символов
**							- <0 в случае ошибки
**		-1 - Ошибка в файлк
**		-2 - Ошибка в малоке
**		-3 - Не нашел нужный символ до конца файла
**	 Аргументы: fd 		- дискриптор открытого файла
**				c 		- символ до которого нужно читать
**				**str	- указатель на строку
*/

int			ft_read_until_ch(int fd, int c, char **str)
{
	char	buff[2];
	int		i;
	int		r;

	if (fd < 0 || read(fd, buff, 0))
		return (-1);
	*str = ft_strnew(1);
	i = 0;
	while ((r = read(fd, buff, 1)) && buff[0] != c)
	{
		buff[1] = 0;
		i++;
		if (!ft_strjoinchar(str, buff[0]))
			return (-2);
		buff[0] = 0;
	}
	if (buff[0])
		ft_strjoinchar(str, buff[0]);
	if (!r)
		return (-3);
	return (i ? i : r);
}

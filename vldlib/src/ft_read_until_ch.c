/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_until_ch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 22:28:07 by cpollich          #+#    #+#             */
/*   Updated: 2020/07/13 20:39:26 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vldlib.h"

static int	ft_strjoinchar(char **str, char c)
{
	char	*tmp;
	size_t	len;

	if (!*str)
		return (0);
	len = ft_strlen(*str);
	if (!(tmp = (char *)malloc(sizeof(char) * (len + 2))))
		return (0);
	tmp = ft_strcpy(tmp, *str);
	if (len)
	{
		tmp[len] = c;
		tmp[len + 1] = 0;
	}
	else
	{
		tmp[0] = c;
		tmp[1] = 0;
	}
	ft_strdel(str);
	*str = tmp;
	return (1);
}

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
	}
	if (!r)
		return (-3);
	return (i ? i : r);
}

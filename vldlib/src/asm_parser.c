/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:18:50 by cpollich          #+#    #+#             */
/*   Updated: 2020/07/10 16:21:01 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vldlib.h"

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
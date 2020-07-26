/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:18:50 by cpollich          #+#    #+#             */
/*   Updated: 2020/07/26 15:39:43 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**							Описание p[5]
**		+ p[0] - Имя
**		+ p[1] - Комментарий чемпиона
**		+ p[2] - Комментарий к коду
**		+ p[3] - Начало метки
**		+ p[4] - инструкция
*/

static int	check_last_str(char *str)
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

static void	check_errors(int *p, int bytes, char *str)
{
	if (bytes == -1 || bytes == -2)
		ft_quit(bytes, 0);
	if (bytes == -3 && !ft_strchr(str, '\n') && !check_last_str(str))
		quit(EN_LASTSTR, NULL, NULL);
	if (!p[0] || !p[1])
		quit(EN_CHAMPMISS, NULL, NULL);
	if (p[0] && p[1] && !p[3])
		quit(EN_NOINST, NULL, NULL);
}

void		read_file(int fd, t_hero **hero)
{
	char	*str;
	int		p[5];
	int		t;
	int		bytes;

	ft_bzero(p, sizeof(int) * 5);
	while ((bytes = ft_read_until_ch(fd, '\n', &str)) > 0)
	{
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
	check_errors(p, bytes, str);
	if (str)
		ft_strdel(&str);
}

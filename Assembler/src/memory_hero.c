/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_hero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 21:39:16 by cpollich          #+#    #+#             */
/*   Updated: 2020/07/27 19:07:55 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	thanks_norminette(char **str, t_vldop **op, int fd)
{
	char	*tmp;
	int		t;

	while ((t = is_label(*str)) || is_blank(*str))
		if (!(tmp = parse_label(*str, *op, t)))
		{
			ft_strdel(str);
			if ((t = ft_read_until_ch(fd, '\n', str)) <= 0 && t != -3)
				ft_quit(t, '\n');
			if (t == -3)
				break ;
		}
		else
		{
			!(tmp = ft_strnewncp(tmp, ft_strlen(tmp))) ?\
				quit(EN_MALLOC, NULL, NULL) : ft_strdel(str);
			*str = tmp;
			break ;
		}
}

t_hero	*init_hero(void)
{
	t_hero	*hero;

	hero = (t_hero *)malloc(sizeof(t_hero));
	if (!hero)
		quit(EN_MALLOC, NULL, NULL);
	hero->name = NULL;
	hero->comment = NULL;
	hero->op = NULL;
	return (hero);
}

void	del_hero(t_hero **hero)
{
	if (hero && *hero)
	{
		ft_strdel(&((*hero)->name));
		ft_strdel(&((*hero)->comment));
		del_ops((*hero)->op);
		free(*hero);
		*hero = NULL;
	}
}

void	fill_hero(int type, char **str, t_hero **hero)
{
	char	*s;

	s = ft_strchr(*str, '"');
	if (!type)
	{
		if ((*hero)->name)
			quit(EN_MORENAMES, NULL, NULL);
		(*hero)->name = ft_strnewncp(s + 1, ft_strrchr(*str, '"') - s - 1);
		if (!(*hero)->name)
			quit(EN_MALLOC, NULL, NULL);
		ft_strdel(str);
	}
	else
	{
		if ((*hero)->comment)
			quit(EN_MORENAMES, NULL, NULL);
		(*hero)->comment = ft_strnewncp(s + 1, ft_strrchr(*str, '"') - s - 1);
		if (!(*hero)->comment)
			quit(EN_MALLOC, NULL, NULL);
		ft_strdel(str);
	}
}

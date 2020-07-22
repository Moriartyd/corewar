/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_hero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 21:39:16 by cpollich          #+#    #+#             */
/*   Updated: 2020/07/22 18:11:39 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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
	}
}

void	fill_hero(int type, char **str, t_hero **hero)
{
	char	*s;

	s = ft_strchr(*str, '"');
	if (!type)
	{
		(*hero)->name = ft_strnewncp(s + 1, ft_strrchr(*str, '"') - s - 1);
		if (!(*hero)->name)
			quit(EN_MALLOC, NULL, NULL);
		ft_strdel(str);
	}
	else
	{
		(*hero)->comment = ft_strnewncp(s + 1, ft_strrchr(*str, '"') - s - 1);
		if (!(*hero)->comment)
			quit(EN_MALLOC, NULL, NULL);
		ft_strdel(str);
	}
}

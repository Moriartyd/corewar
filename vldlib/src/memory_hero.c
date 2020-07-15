/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_hero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 21:39:16 by cpollich          #+#    #+#             */
/*   Updated: 2020/07/15 18:41:08 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vldlib.h"

t_hero	*init_hero()
{
	t_hero	*hero;

	hero = (t_hero *)malloc(sizeof(t_hero));
	if (!hero)
		exit(-1);// Malloc error
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
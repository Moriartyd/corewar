/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_hero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 18:17:51 by cpollich          #+#    #+#             */
/*   Updated: 2020/07/20 16:55:27 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vldlib.h"

void	fill_hero(int type, char **str, t_hero **hero)
{
	char	*s;

	s = ft_strchr(*str, '"');
	if (!type)
	{
		(*hero)->name = ft_strnewncp(s + 1, ft_strrchr(*str, '"') - s - 1);
		if (!(*hero)->name)
			exit(-1); //Malloc error
		ft_strdel(str);
	}
	else
	{
		(*hero)->comment = ft_strnewncp(s + 1, ft_strrchr(*str, '"') - s - 1);
		if (!(*hero)->comment)
			exit(-1); //Malloc error
		ft_strdel(str);
	}
}
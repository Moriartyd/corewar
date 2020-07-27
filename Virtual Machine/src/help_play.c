/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_play.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 17:01:52 by mriley            #+#    #+#             */
/*   Updated: 2020/07/27 23:10:55 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual.h"
#include <stdio.h>

t_car	*parse_func_champ(t_car *champ, t_core *core, int cycle)
{
	if (g_arena[champ->pc] == 1)
		champ->cycle_live = cycle;
	if (g_arena[champ->pc] == 15 || g_arena[champ->pc] == 12)
		core->num_ch = core->num_ch + 1;
	if (g_arena[champ->pc] > 0 && g_arena[champ->pc] < 17)
		g_op_tab[g_arena[champ->pc] - 1].f(champ);
	else
		champ->pc = (champ->pc + 1) % MEM_SIZE;
	return (champ);
}

t_car	*init_champions(t_car *player, int j, t_core *champ)
{
	player->num = champ->champions[j].num;
	player->pc = change_arena(champ->champions[j], player->num, champ->num_ch);
	player->time = -1;
	player->cycle_live = -1;
	player->carry = 0;
	player = init_reg(player);
	player = to_reg_from_int(player, 1, -player->num);
	player->next = ft_memalloc(sizeof(t_car));
	return (player);
}

t_car	*ft_zjmp(t_car *car)
{
	int		indir;

	indir = to_int(g_arena[car->pc + 1], g_arena[car->pc + 2]);
	if (car->carry == 1)
	{
		if ((car->pc + (indir % IDX_MOD)) % MEM_SIZE >= 0)
			car->pc = (car->pc + (indir % IDX_MOD)) % MEM_SIZE;
		else
			car->pc = MEM_SIZE + (car->pc + (indir % IDX_MOD)) % MEM_SIZE;
	}
	else
	{
		car->pc = (car->pc + 3) % MEM_SIZE;
	}
	return (car);
}

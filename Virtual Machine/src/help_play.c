/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_play.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <mriley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 17:01:52 by mriley            #+#    #+#             */
/*   Updated: 2020/07/28 19:57:31 by mriley           ###   ########.fr       */
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
		champ = g_op_tab[g_arena[champ->pc] - 1].f(champ);
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
	player->next->next = NULL;
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

void	usage(void)
{
	ft_printf("for help usage: -help\n");
	ft_printf("for dump memory usage: -dump or -d\n");
	ft_printf("for set number champion usage: -n\n");
	exit(0);
}

t_core	*parse_cor(int num, int *nums, t_core *champ)
{
	champ->num_ch = num;
	free(nums);
	if (num == 0)
		ft_error(EINVAL, -2);
	return (champ);
}

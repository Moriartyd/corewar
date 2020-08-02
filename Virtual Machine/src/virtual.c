/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtual.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <mriley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 16:41:09 by mriley            #+#    #+#             */
/*   Updated: 2020/08/02 17:49:42 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual.h"
#include <stdio.h>

t_car			*time_to_die(t_car *car)
{
	t_car	*new;

	new = car->next;
	free(car);
	car = NULL;
	return (new);
}

t_car			*check_die(int cycle,
int cycles_to_die, t_core *champ)
{
	t_car	*buf;
	int		i;

	i = 0;
	while (champ->player && (champ->player->cycle_live < cycle - cycles_to_die
	|| (cycles_to_die <= 0)))
	{
		(champ->player && !champ->player->next) ? print_hello(champ, champ->player->num) : 0;
		champ->player = time_to_die(champ->player);
		champ->num_ch = champ->num_ch - 1;
	}
	buf = champ->player;
	while (champ->player)
	{
		while (champ->player->next  && (champ->player->next->cycle_live
		< cycle - cycles_to_die || (cycles_to_die <= 0)))
		{
			champ->player->next = time_to_die(champ->player->next);
			champ->num_ch = champ->num_ch - 1;
		}
		if (champ->player)
			champ->player = champ->player->next;
	}
	return (buf);
}

unsigned int	change_arena(t_champ champ, int n, int num_ch)
{
	unsigned int	start;
	unsigned int	i;

	start = (MEM_SIZE / num_ch) * (n - 1);
	i = 0;
	while (i < champ.mem.prog_size)
	{
		g_arena[start + i] = champ.code[i];
		i++;
	}
	return (start);
}

t_car			*init_reg(t_car *car)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= REG_NUMBER)
	{
		while (j < REG_SIZE)
		{
			car->reg[i].reg[j] = '\0';
			j++;
		}
		j = 0;
		i++;
	}
	return (car);
}

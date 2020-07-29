/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtual.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <mriley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 16:41:09 by mriley            #+#    #+#             */
/*   Updated: 2020/07/29 14:24:57 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual.h"
#include <stdio.h>

t_car			*time_to_die(t_car *car)
{
	t_car	*new;

	new = car->next;
	free(car);
	return (new);
}

t_car			*check_die(t_car *car, int cycle,
int cycles_to_die, t_core *champ)
{
	t_car	*buf;
	int		i;

	i = 0;
	while (car && (car->cycle_live < cycle - cycles_to_die
	|| (cycles_to_die <= 0)))
	{
		(car && !car->next) ? print_hello(champ, car->num) : 0;
		car = time_to_die(car);
		champ->num_ch = champ->num_ch - 1;
	}
	buf = car;
	while (car && car->next)
	{
		while (car && car->next && (car->next->cycle_live
		< cycle - cycles_to_die || (cycles_to_die <= 0)))
		{
			car->next = time_to_die(car->next);
			champ->num_ch = champ->num_ch - 1;
		}
		car = car->next;
	}
	(car && !car->next && (car->cycle_live < cycle - cycles_to_die \
	|| (cycles_to_die <= 0))) ? car = time_to_die(car) : 0;
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

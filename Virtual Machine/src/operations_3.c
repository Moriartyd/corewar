/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <mriley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 17:12:59 by mriley            #+#    #+#             */
/*   Updated: 2020/07/28 21:11:04 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual.h"

void	copy_to_arena(int start, int copy)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		g_arena[(start + 3 - i) % MEM_SIZE] = (char)(copy & 0x000000ff);
		i++;
		copy = copy >> 8;
	}
}

int		to_int_from_reg(t_car *car, int reg)
{
	int		solve;
	int		n;
	int		i;

	solve = 0;
	n = 0;
	i = 0;
	while (i < REG_SIZE)
	{
		n = (int)car->reg[reg].reg[i];
		n = n & 0x000000ff;
		solve = solve | n;
		i++;
		if (i < REG_SIZE)
			solve = solve << 8;
	}
	return (solve);
}

t_car	*ft_live(t_car *car)
{
	int		k;

	k = -to_int_size(car->pc + 1, 4);
	if (k > 0 && k < 5)
		car->num = k;
	car->pc = (car->pc + 5) % MEM_SIZE;
	return (car);
}

t_car	*ft_ld(t_car *car)
{
	int		*arg;
	int		in1;
	int		i;

	arg = ft_memalloc(sizeof(int) * 3);
	arg = read_arg(arg, g_arena[car->pc + 1], 4);
	if ((arg[0] == 4 || arg[0] == 2) && arg[1] == 1)
	{
		if (arg[0] == 4)
			in1 = to_int_size(car->pc + 2, 4);
		else
		{
			in1 = to_int(g_arena[car->pc + 2], g_arena[car->pc + 3]);
			in1 = (car->pc + in1 % IDX_MOD) % MEM_SIZE >= 0 ?
			to_int_size((car->pc + in1 % IDX_MOD) % MEM_SIZE, 4) :
			to_int_size(MEM_SIZE + (car->pc + in1 % IDX_MOD) % MEM_SIZE, 4);
		}
		i = 2 + arg[0];
		if (g_arena[car->pc + i] > 0 && g_arena[car->pc + i] <= REG_NUMBER)
			car = to_reg_from_int(car, g_arena[car->pc + i], in1);
		car->carry = in1 == 0 ? 1 : 0;
	}
	car->pc = (car->pc + 2 + arg[0] + arg[1]) % MEM_SIZE;
	free(arg);
	return (car);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 17:21:07 by mriley            #+#    #+#             */
/*   Updated: 2020/07/27 23:56:22 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual.h"

static void	norme(int **arg, t_car *car)
{
	*arg = ft_memalloc(sizeof(int) * 3);
	*arg = read_arg(*arg, g_arena[car->pc + 1], 4);
}

t_car		*ft_st(t_car *car)
{
	int		*arg;
	int		in1;
	int		in2;

	norme(&arg, car);
	if (arg[0] == 1 && (arg[1] == 1 || arg[1] == 2) &&
	g_arena[car->pc + 2] > 0 && g_arena[car->pc + 2] <= REG_NUMBER)
	{
		in1 = to_int_from_reg(car, g_arena[car->pc + 2]);
		if (arg[1] == 1 && g_arena[car->pc + 3] > 0
		&& g_arena[car->pc + 3] <= REG_NUMBER)
			car = to_reg_from_int(car, g_arena[car->pc + 3], in1);
		else
		{
			in2 = to_int(g_arena[car->pc + 3], g_arena[car->pc + 4]);
			if (g_arena[car->pc + 2] > 0 && g_arena[car->pc + 2] <= REG_NUMBER)
				((car->pc + (in2 % IDX_MOD)) % MEM_SIZE >= 0) ?
				copy_to_arena((car->pc + (in2 % IDX_MOD)) % MEM_SIZE, in1) :
				copy_to_arena(MEM_SIZE + (car->pc + (in2 % IDX_MOD)) %
				MEM_SIZE, in1);
		}
	}
	car->pc = (car->pc + 2 + arg[0] + arg[1]) % MEM_SIZE;
	free(arg);
	return (car);
}

t_car		*ft_add(t_car *car)
{
	int		*arg;
	int		reg1;
	int		reg2;

	arg = ft_memalloc(sizeof(int) * 3);
	arg = read_arg(arg, g_arena[car->pc + 1], 4);
	if (g_arena[car->pc + 2] > 0 && g_arena[car->pc + 2] <= REG_NUMBER &&
	g_arena[car->pc + 3] > 0 && g_arena[car->pc + 3] <= REG_NUMBER &&
	g_arena[car->pc + 4] > 0 && g_arena[car->pc + 4] <= REG_NUMBER
	&& arg[0] == 1 && arg[1] == 1 && arg[2] == 1)
	{
		reg1 = to_int_from_reg(car, g_arena[car->pc + 2]);
		reg2 = to_int_from_reg(car, g_arena[car->pc + 3]);
		reg1 = reg1 + reg2;
		car->carry = (reg1 == 0) ? 1 : 0;
		car = to_reg_from_int(car, g_arena[car->pc + 4], reg1);
	}
	car->pc = (car->pc + 2 + arg[0] + arg[1] + arg[2]) % MEM_SIZE;
	free(arg);
	return (car);
}

t_car		*ft_sub(t_car *car)
{
	int		*arg;
	int		reg1;
	int		reg2;

	reg1 = 0;
	reg2 = 0;
	arg = ft_memalloc(sizeof(int) * 3);
	arg = read_arg(arg, g_arena[car->pc + 1], 4);
	if (g_arena[car->pc + 2] > 0 && g_arena[car->pc + 2] <= REG_NUMBER &&
	g_arena[car->pc + 3] > 0 && g_arena[car->pc + 3] <= REG_NUMBER &&
	g_arena[car->pc + 4] > 0 && g_arena[car->pc + 4] <= REG_NUMBER &&
	arg[0] == 1 && arg[1] == 1 && arg[2] == 1)
	{
		reg1 = to_int_from_reg(car, g_arena[car->pc + 2]);
		reg2 = to_int_from_reg(car, g_arena[car->pc + 3]);
		reg1 = reg1 - reg2;
		car->carry = (reg1 == 0) ? 1 : 0;
		car = to_reg_from_int(car, g_arena[car->pc + 4], reg1);
	}
	car->pc = (car->pc + 2 + arg[0] + arg[1] + arg[2]) % MEM_SIZE;
	free(arg);
	return (car);
}

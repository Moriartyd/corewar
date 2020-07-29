/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <mriley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 21:10:47 by mriley            #+#    #+#             */
/*   Updated: 2020/07/29 15:17:53 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual.h"
#include <stdio.h>

int		ret_asm_in1(int code, int i, t_car *car)
{
	int		in1;

	in1 = 0;
	if (code == 0xc0)
	{
		in1 = to_int(g_arena[car->pc + i], g_arena[car->pc + i + 1]);
		if (((car->pc + in1 % IDX_MOD) % MEM_SIZE) >= 0)
			in1 = to_int_size((car->pc + in1 % IDX_MOD) % MEM_SIZE, 4);
		else
			in1 = to_int_size(MEM_SIZE + (car->pc + in1 % IDX_MOD) % MEM_SIZE,
			4);
	}
	if (code == 0x80)
		in1 = to_int(g_arena[car->pc + i], g_arena[car->pc + i + 1]);
	if (code == 0x40)
	{
		if (g_arena[car->pc + i] > 0 && g_arena[car->pc + i] <= REG_NUMBER)
			in1 = to_int_from_reg(car, g_arena[car->pc + i]);
	}
	return (in1);
}

int		ret_asm_in2(int code, int i, t_car *car)
{
	int		in1;

	in1 = 0;
	if (code == 0x30)
	{
		in1 = to_int(g_arena[car->pc + i], g_arena[car->pc + i + 1]);
		if (((car->pc + in1 % IDX_MOD) % MEM_SIZE) >= 0)
			in1 = to_int_size((car->pc + in1 % IDX_MOD) % MEM_SIZE, 4);
		else
			in1 = to_int_size(MEM_SIZE + (car->pc + in1 % IDX_MOD) % MEM_SIZE,
			4);
	}
	else if (code == 0x20)
		in1 = to_int(g_arena[car->pc + i], g_arena[car->pc + i + 1]);
	else if (code == 0x10)
	{
		if (g_arena[car->pc + i] > 0 && g_arena[car->pc + i] <= REG_NUMBER)
			in1 = to_int_from_reg(car, g_arena[car->pc + i]);
	}
	return (in1);
}

t_car	*ft_ldi(t_car *car)
{
	int		*arg;
	int		i;
	int		in1;
	int		in2;

	i = 2;
	arg = ft_memalloc(sizeof(int) * 3);
	arg = read_arg(arg, g_arena[car->pc + 1], 2);
	in1 = ret_asm_in1(g_arena[car->pc + 1] & 0xc0, i, car);
	i = i + arg[0];
	in2 = 0;
	if ((g_arena[car->pc + 1] & 0x30) == 0x20)
		in2 = to_int(g_arena[car->pc + i], g_arena[car->pc + i + 1]);
	if ((g_arena[car->pc + 1] & 0x30) == 0x10 && g_arena[car->pc + i] > 0
	&& g_arena[car->pc + i] <= REG_NUMBER)
		in2 = to_int_from_reg(car, g_arena[car->pc + i]);
	i = i + arg[1];
	in1 = (car->pc + (in1 + in2) % IDX_MOD) % MEM_SIZE >= 0 ?
	to_int_size((car->pc + (in1 + in2) % IDX_MOD) % MEM_SIZE, 4) :
	to_int_size(MEM_SIZE + (car->pc + (in1 + in2) % IDX_MOD) % MEM_SIZE, 4);
	if (g_arena[car->pc + i] > 0 && g_arena[car->pc + i] <= REG_NUMBER)
		car = to_reg_from_int(car, g_arena[car->pc + i], in1);
	car->pc = (car->pc + 2 + arg[0] + arg[1] + arg[2]) % MEM_SIZE;
	free(arg);
	return (car);
}

int		sti_in(t_car *car, int i)
{
	int		in2;

	in2 = 0;
	if ((g_arena[car->pc + 1] & 0x0c) == 0x08)
		in2 = to_int(g_arena[car->pc + i], g_arena[car->pc + i + 1]);
	else if ((g_arena[car->pc + 1] & 0x0c) == 0x04 && g_arena[car->pc + i] > 0
	&& g_arena[car->pc + i] <= REG_NUMBER)
		in2 = to_int_from_reg(car, g_arena[car->pc + i]);
	return (in2);
}

t_car	*ft_sti(t_car *car)
{
	int		*arg;
	int		in1;
	int		in2;
	int		reg1;
	int		i;

	arg = ft_memalloc(sizeof(int) * 3);
	arg = read_arg(arg, g_arena[car->pc + 1], 2);
	in1 = ret_asm_in2(g_arena[car->pc + 1] & 0x30, 3, car);
	i = 3 + arg[1];
	in2 = sti_in(car, i);
	if (g_arena[car->pc + 2] > 0 && g_arena[car->pc + 2] <= REG_NUMBER
	&& (g_arena[car->pc + 1] & 0x0c) != 0x0c)
	{
		reg1 = to_int_from_reg(car, g_arena[car->pc + 2]);
		((car->pc + (in1 + in2) % IDX_MOD) % MEM_SIZE >= 0) ?
		copy_to_arena((car->pc + (in1 + in2) % IDX_MOD) % MEM_SIZE, reg1) :
		copy_to_arena(MEM_SIZE + (car->pc + (in1 + in2) % IDX_MOD), reg1);
	}
	car->pc = (car->pc + 2 + arg[0] + arg[1] + arg[2]) % MEM_SIZE;
	free(arg);
	return (car);
}

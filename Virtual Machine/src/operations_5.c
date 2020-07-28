/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <mriley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 17:57:02 by mriley            #+#    #+#             */
/*   Updated: 2020/07/28 19:56:37 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual.h"

int		ret_asm_in1_four(int code, int i, t_car *car)
{
	int		in1;

	if (code == 0x40 && g_arena[car->pc + i] > 0 &&
	g_arena[car->pc + i] <= REG_NUMBER)
		in1 = to_int_from_reg(car, g_arena[car->pc + i]);
	else if (code == 0x80)
		in1 = to_int_size(car->pc + i, 4);
	else if (code == 0xc0)
	{
		in1 = to_int(g_arena[car->pc + i], g_arena[car->pc + i + 1]);
		if ((car->pc + in1 % IDX_MOD) % MEM_SIZE >= 0)
			in1 = to_int_size((car->pc + in1 % IDX_MOD) % MEM_SIZE, 4);
		else
			in1 = to_int_size(MEM_SIZE + (car->pc + in1 % IDX_MOD) % MEM_SIZE,
			4);
	}
	else
		in1 = 0;
	return (in1);
}

int		ret_asm_in2_four(int code, int i, t_car *car)
{
	int		in2;

	if (code == 0x10 && g_arena[car->pc + i] > 0
	&& g_arena[car->pc + i] <= REG_NUMBER)
		in2 = to_int_from_reg(car, g_arena[car->pc + i]);
	else if (code == 0x20)
		in2 = to_int_size(car->pc + i, 4);
	else if (code == 0x30)
	{
		in2 = to_int(g_arena[car->pc + i], g_arena[car->pc + i + 1]);
		in2 = (car->pc + in2 % IDX_MOD) % MEM_SIZE >= 0 ?
		to_int_size((car->pc + in2 % IDX_MOD) % MEM_SIZE, 4) :
		to_int_size(MEM_SIZE + (car->pc + in2 % IDX_MOD) % MEM_SIZE, 4);
	}
	else
		in2 = 0;
	return (in2);
}

t_car	*ft_and(t_car *car)
{
	int		*arg;
	int		in1;
	int		in2;
	int		i;

	arg = ft_memalloc(sizeof(int) * 3);
	arg = read_arg(arg, g_arena[car->pc + 1], 4);
	in1 = ret_asm_in1_four(g_arena[car->pc + 1] & 0xc0, 2, car);
	i = 2 + arg[0];
	in2 = ret_asm_in2_four(g_arena[car->pc + 1] & 0x30, i, car);
	i = i + arg[1];
	in1 = in1 & in2;
	car->carry = in1 == 0 ? 1 : 0;
	if ((g_arena[car->pc + 1] & 0x0c) == 0x04 && g_arena[car->pc + i] > 0
	&& g_arena[car->pc + i] <= REG_NUMBER)
		car = to_reg_from_int(car, g_arena[car->pc + i], in1);
	car->pc = (car->pc + 2 + arg[0] + arg[1] + arg[2]) % MEM_SIZE;
	free(arg);
	return (car);
}

t_car	*ft_or(t_car *car)
{
	int		*arg;
	int		i;
	int		in1;
	int		in2;

	arg = ft_memalloc(sizeof(int) * 3);
	arg = read_arg(arg, g_arena[car->pc + 1], 4);
	in1 = ret_asm_in1_four(g_arena[car->pc + 1] & 0xc0, 2, car);
	i = 2 + arg[0];
	in2 = ret_asm_in2_four(g_arena[car->pc + 1] & 0x30, i, car);
	i = i + arg[1];
	in1 = in1 | in2;
	car->carry = in1 == 0 ? 1 : 0;
	if ((g_arena[car->pc + 1] & 0x0c) == 0x04 && g_arena[car->pc + i] > 0
	&& g_arena[car->pc + i] <= REG_NUMBER)
		car = to_reg_from_int(car, g_arena[car->pc + i], in1);
	car->pc = (car->pc + 2 + arg[0] + arg[1] + arg[2]) % MEM_SIZE;
	free(arg);
	return (car);
}

t_car	*ft_xor(t_car *car)
{
	int *arg;
	int i;
	int in1;
	int in2;

	arg = ft_memalloc(sizeof(int) * 3);
	arg = read_arg(arg, g_arena[car->pc + 1], 4);
	in1 = ret_asm_in1_four(g_arena[car->pc + 1] & 0xc0, 2, car);
	i = 2 + arg[0];
	in2 = ret_asm_in2_four(g_arena[car->pc + 1] & 0x30, i, car);
	i = i + arg[1];
	in1 = in1 ^ in2;
	car->carry = in1 == 0 ? 1 : 0;
	if ((g_arena[car->pc + 1] & 0x0c) == 0x04 && g_arena[car->pc + i] > 0
	&& g_arena[car->pc + i] <= REG_NUMBER)
		car = to_reg_from_int(car, g_arena[car->pc + i], in1);
	car->pc = (car->pc + 2 + arg[0] + arg[1] + arg[2]) % MEM_SIZE;
	free(arg);
	return (car);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <mriley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 16:53:48 by mriley            #+#    #+#             */
/*   Updated: 2020/07/29 15:15:29 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual.h"

int		lldi_in(t_car *car, int in1, int in2)
{
	in1 = (car->pc + (in1 + in2)) % MEM_SIZE >= 0 ?
	to_int_size((car->pc + (in1 + in2)) % MEM_SIZE, 4) :
	to_int_size(MEM_SIZE + (car->pc + (in1 + in2)) % MEM_SIZE, 4);
	return (in1);
}

int		lldi_in2(t_car *car, int i)
{
	int		in2;

	in2 = 0;
	if ((g_arena[car->pc + 1] & 0x30) == 0x20)
		in2 = to_int(g_arena[car->pc + i], g_arena[car->pc + i + 1]);
	if ((g_arena[car->pc + 1] & 0x30) == 0x10 &&
	g_arena[car->pc + i] > 0 && g_arena[car->pc + i] <= REG_NUMBER)
		in2 = to_int_from_reg(car, g_arena[car->pc + i]);
	return (in2);
}

t_car	*ft_lldi(t_car *car)
{
	int		*arg;
	int		in1;
	int		in2;
	int		i;

	arg = ft_memalloc(sizeof(int) * 3);
	arg = read_arg(arg, g_arena[car->pc + 1], 4);
	in1 = ret_asm_in1(g_arena[car->pc + 1] & 0xc0, 2, car);
	i = 2 + arg[0];
	in2 = lldi_in2(car, i);
	i = i + arg[1];
	in1 = lldi_in(car, in1, in2);
	if (g_arena[car->pc + i] > 0 && g_arena[car->pc + i] <= REG_NUMBER
	&& (g_arena[car->pc + 1] & 0x30) != 0x30 && arg[2] == 1)
	{
		car = to_reg_from_int(car, g_arena[car->pc + i], in1);
		car->carry = in1 == 0 ? 1 : 0;
	}
	car->pc = (car->pc + 2 + arg[0] + arg[1]) % MEM_SIZE;
	free(arg);
	return (car);
}

t_car	*ft_lfork(t_car *car)
{
	t_car	*start;
	t_car	*copy;
	int		i;
	int		j;
	int		in1;

	copy = ft_memalloc(sizeof(t_car));
	start = car;
	i = 0;
	j = 0;
	in1 = to_int(g_arena[car->pc + 1], g_arena[car->pc + 2]);
	copy = copy_car(copy, car);
	if ((car->pc + in1) % MEM_SIZE >= 0)
		copy->pc = (car->pc + in1) % MEM_SIZE;
	else
		copy->pc = MEM_SIZE + (car->pc + in1) % MEM_SIZE;
	car->pc = (car->pc + 3) % MEM_SIZE;
	while (car && car->next)
		car = car->next;
	copy->next = NULL;
	car->next = copy;
	return (start);
}

t_car	*ft_fork(t_car *car)
{
	t_car	*start;
	t_car	*copy;
	int		i;
	int		j;
	int		in1;

	copy = ft_memalloc(sizeof(t_car));
	start = car;
	i = 0;
	j = 0;
	in1 = to_int(g_arena[car->pc + 1], g_arena[car->pc + 2]);
	copy = copy_car(copy, car);
	if ((car->pc + in1 % IDX_MOD) % MEM_SIZE >= 0)
		copy->pc = (car->pc + in1 % IDX_MOD) % MEM_SIZE;
	else
		copy->pc = MEM_SIZE + (car->pc + in1 % IDX_MOD) % MEM_SIZE;
	car->pc = (car->pc + 3) % MEM_SIZE;
	while (car && car->next)
		car = car->next;
	copy->next = NULL;
	car->next = copy;
	return (start);
}

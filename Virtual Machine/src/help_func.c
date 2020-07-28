/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <mriley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 20:02:30 by mriley            #+#    #+#             */
/*   Updated: 2020/07/28 18:18:37 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual.h"

int		to_int(char a, char b)
{
	int		sum;

	sum = 0;
	sum = a;
	sum = sum & 0x000000ff;
	sum = sum << 8;
	sum = sum | (b & 0x000000ff);
	if (sum > 0x00007fff)
		sum = sum | 0xfffff000;
	return (sum);
}

t_car	*copy_car(t_car *copy, t_car *car)
{
	int		i;
	int		j;

	copy->num = car->num;
	copy->carry = car->carry;
	copy->cycle_live = car->cycle_live;
	copy->time = -1;
	i = 0;
	j = 0;
	while (i <= REG_NUMBER)
	{
		while (j < REG_SIZE)
		{
			copy->reg[i].reg[j] = car->reg[i].reg[j];
			j++;
		}
		j = 0;
		i++;
	}
	copy->next = NULL;
	return (copy);
}

int		*read_arg(int *arg, char mem, int size_dir)
{
	if ((mem & 0xc0) == 0x80)
		arg[0] = size_dir;
	if ((mem & 0xc0) == 0x40)
		arg[0] = T_REG;
	if ((mem & 0xc0) == 0xc0)
		arg[0] = IND_SIZE;
	if ((mem & 0x30) == 0x20)
		arg[1] = size_dir;
	if ((mem & 0x30) == 0x10)
		arg[1] = T_REG;
	if ((mem & 0x30) == 0x30)
		arg[1] = IND_SIZE;
	if ((mem & 0x0c) == 0x08)
		arg[2] = size_dir;
	if ((mem & 0x0c) == 0x04)
		arg[2] = T_REG;
	if ((mem & 0x0c) == 0x0c)
		arg[2] = IND_SIZE;
	return (arg);
}

t_car	*to_reg_from_int(t_car *car, int reg, int tr)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		car->reg[reg].reg[REG_SIZE - i - 1] = tr & 0x000000ff;
		i++;
		tr = tr >> 8;
	}
	return (car);
}

int		to_int_size(int start, int size)
{
	int		i;
	int		solve;
	int		n;

	i = 0;
	solve = 0;
	n = 0;
	while (i < size)
	{
		n = (int)g_arena[(start + i) % MEM_SIZE];
		n = n & 0x000000ff;
		solve = solve | n;
		i++;
		if (i < size)
			solve = solve << 8;
	}
	return (solve);
}

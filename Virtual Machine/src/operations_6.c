/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <mriley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 15:14:01 by mriley            #+#    #+#             */
/*   Updated: 2020/07/29 15:15:25 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual.h"

void	show(t_core *champ)
{
	champ->s_dump = -1;
	print_arena(64);
	ft_printf("\n");
}

t_car	*ft_lld(t_car *car)
{
	int		*arg;
	int		in1;

	arg = ft_memalloc(sizeof(int) * 3);
	arg = read_arg(arg, g_arena[car->pc + 1], 4);
	in1 = 0;
	if (arg[0] == 4)
		in1 = to_int_size(car->pc + 2, 4);
	else if (arg[0] == 2)
	{
		in1 = to_int(g_arena[car->pc + 2], g_arena[car->pc + 3]);
		in1 = (car->pc + in1) % MEM_SIZE >= 0 ?
		to_int_size((car->pc + in1) % MEM_SIZE, 4) :
		to_int_size(MEM_SIZE + (car->pc + in1) % MEM_SIZE, 4);
	}
	if (g_arena[car->pc + 2 + arg[0]] > 0 &&
	g_arena[car->pc + 2 + arg[0]] <= REG_NUMBER && arg[0] != 1)
	{
		car = to_reg_from_int(car, g_arena[car->pc + 2 + arg[0]], in1);
		car->carry = in1 == 0 ? 1 : 0;
	}
	car->pc = (car->pc + 2 + arg[0] + arg[1]) % MEM_SIZE;
	free(arg);
	return (car);
}

t_car	*ft_aff(t_car *car)
{
	int		i;
	int		num;
	char	*s;

	i = 0;
	if (g_arena[car->pc + 2] <= REG_NUMBER && g_arena[car->pc + 2] > 0)
	{
		num = to_int_from_reg(car, g_arena[car->pc + 2]);
		s = ft_itoa(num);
		write(1, s, ft_strlen(s));
		free(s);
	}
	car->pc = (car->pc + 3) % MEM_SIZE;
	return (car);
}

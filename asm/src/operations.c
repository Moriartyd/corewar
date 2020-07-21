/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 20:32:29 by student           #+#    #+#             */
/*   Updated: 2020/07/20 17:00:04 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "./vldlib/inc/vldlib.h"
#include "asm.h"

int			op_live(t_op *op, int i, t_hero *hero)
{
	//unsigned char bc[1];
	char live;

	live = 01;
	write(1, &live, 1);//fd
	hero->excode[hero->p++] = live;
	if (op->code != 9 && op->code != 12 && op->code != 15)
		get_types(op, i, hero);
	get_args(op);
	return (0);
}

int			detect_op(t_op *op, int i, t_hero *hero, t_op *sec)
{
//	if (op->code == 1)
//	{
		op_live(op, i, hero);
//	}
	if (op->code == 2)
	{
		//op_ld();
	}
	if (op->code == 3)
	{
		//op_st();
	}
	if (op->code == 4)
	{
		//op_add();
	}
	if (op->code == 5)
	{
		//op_sub();
	}
	return (0);
}


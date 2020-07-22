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

	live = (char)op->code;
	write(1, &live, 1);//fd
	hero->excode[hero->p++] = live;
	printf("OPCODE=%d ", live);
	if (op->code != 1 && op->code != 9 && op->code != 12 && op->code != 15)
		get_types(op, i, hero);
	get_args(op);
	return (0);
}

int			detect_op(t_op *op, int ip, t_hero *hero, t_op *sec)
{
	t_op *tmp;
	int	i;

	tmp = op;
	/*while (tmp)
	{
		i = -1;
		while (tmp->labels[++i])
			printf("op->labels=%s\n", tmp->labels[i]);
		tmp = tmp->next;
	}*/
//	if (op->code == 1)
//	{
		op_live(op, i, hero);
//	}
/*	if (op->code == 2)
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
	}*/
	return (0);
}


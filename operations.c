/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 20:32:29 by student           #+#    #+#             */
/*   Updated: 2020/07/19 20:33:36 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vldlib/inc/vldlib.h"

int			op_live(t_op *op, int fd, unsigned char bc[2192])
{
	//unsigned char bc[1];
	char live;

	live = 01;
	write(fd, &live, 1);
	if (op->code != 9 && op->code != 12 && op->code != 15)
		get_types(op);
	get_args(op);
	return (0);
}

int			detect_op(t_op *op, int fd, unsigned char bc[2192])
{
	if (op->code == 1)
	{
		op_live(op, fd, bc);
	}
	if (op->code == 2)
	{
		op_ld();
	}
	if (op->code == 3)
	{
		op_st();
	}
	if (op->code == 4)
	{
		op_add();
	}
	if (op->code == 5)
	{
		op_sub();
	}
	return (0);
}


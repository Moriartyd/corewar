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

/*
** if label pts to next op - count prevsize,
** if label points to prev - count cur + next sz;
*/

int			search_label(t_op *op, t_hero *hero, char *label, t_op *cur)
{
	int		i;
	t_op	*beg;
	int		sz;

	i = -1;
	beg = hero->op;
	while (op->labels[++i])
	{
		if (!ft_strcmp(op->labels[i], label))
		{
			if (cur->idop > op->idop)
			{
				beg = op;
				while (beg)
				{
					if (beg->idop == cur->idop)
						break ;
					sz += beg->bytes;
					beg = beg->next;
				}
			}
			if (op->idop > cur->idop)
			{
				beg = cur;
				while (beg)
				{
					if (beg->idop == op->idop)
						break ;
					sz += beg->bytes;
					beg = beg->next;
				}
			}
			op->nargs[0] = op->code;//count size of op and location
		}
	}
}

int			is_arg_labels(t_op *op, t_hero *hero)
{
	int i;
	t_op	*beg;

	i = -1;
	while (++i < 3)
	{
		if (op->curlabels[i])
		{
			beg = hero->op;
			while (beg)
			{
				if (beg->idop != op->idop)
				{
					search_label(beg, hero, op->curlabels[i], op);
				}
				beg = beg->next;
			}
		}
	}
	return (0);
}

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
	is_arg_labels(op, hero);
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


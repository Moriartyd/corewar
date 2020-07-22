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
 * beg - compared op, la - op with labeled arg
*/

int			count_label(t_op *op, int i, t_op *la)
{
	int sz;
	t_op *beg;
	t_op *stop;

	if (la->idop > op->idop)
	{
		beg = op;
		stop = la;
		sz = -1;
	}
	else
		return (0);
	sz = 0;
	while (beg)
	{
		if (beg->idop == stop->idop)
			break ;
		sz -= beg->bytes;
		beg = beg->next;
	}
	la->nargs[i] = sz;//op->code;//count size of op and location
	return (1);
}

int			search_label(t_op *op, int ip, char *label, t_op *la)
{
	int		i;
	t_op	*beg;
	int		sz;
	t_op	*stop;

	i = -1;
	while (op->labels[++i])
	{
		if (!ft_strcmp(op->labels[i], label))
		{
			la->nargs[ip] = 0;
			if (op->idop > la->idop)///+
			{
				beg = la;
				stop = op;
				while (beg)
				{
					if (beg->idop == stop->idop)
						break;
					la->nargs[ip] += beg->bytes;
					beg = beg->next;
				}
				return (1);
			}
			else if (la->idop > op->idop)
				return (count_label(op, ip, la));
		}
	}
	return (0);
}

int			is_arg_labels(t_op *la, t_hero *hero)
{
	int i;
	t_op	*beg;

	i = -1;
	while (++i < 3)
	{
		if (la->curlabels[i])
		{
			beg = hero->op;
			while (beg)
			{
				if (beg->idop != la->idop)
				{
					if (search_label(beg, i, la->curlabels[i], la))
						return (1);//success
				}
				beg = beg->next;
			}
			return (0);//label does not exist
		}
	}
	return (2);//nolabels
}

int			write_labels(t_hero *hero, t_op *op)//nm args in byte code
{
	int i;

	i = -1;
	while (++i < 3)
	{
		if (op->types[i] == 1)
			hero->excode[hero->p];
}

int			op_live(t_op *op, int i, t_hero *hero)
{
	char live;

	live = (char)op->code;
	write(1, &live, 1);//fd
	hero->excode[hero->p++] = live;
	printf("OPCODE=%d ", live);
	if (op->code != 1 && op->code != 9 && op->code != 12 && op->code != 15)
		get_types(op, i, hero);
	get_args(op);
	if (!(is_arg_labels(op, hero)))
		return (0);
	write_labels(hero, op);
	return (1);
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
	op_live(op, i, hero);
	return (0);
}


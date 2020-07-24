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
	int	d;

	i = -1;
	d = op->code;
	while (++i < 3 && op->types[i])
	{
		if (op->types[i] == T_REG)
		{
			hero->excode[hero->p++] = (char) op->nargs[i];
		}
		else if (op->types[i] == T_IND || d == 9 || d == 10 || d == 11 || d == 12 || d == 14 || d == 15)
		{
			hero->excode[hero->p++] = (unsigned)op->nargs[i] >> 8;
			hero->excode[hero->p++] = op->nargs[i];
		}
		else if (op->types[i] == T_DIR)
		{
			hero->excode[hero->p++] = (unsigned)op->nargs[i] >> 24;
			hero->excode[hero->p++] = (unsigned)op->nargs[i] >> 16;
			hero->excode[hero->p++] = (unsigned)op->nargs[i] >> 8;
			hero->excode[hero->p++] = (unsigned)op->nargs[i];
		}
	}
	return (1);
}

int			op_code(t_op *op, t_hero *hero)
{
	hero->excode[hero->p++] = (char)op->code;
	if (op->code != 1 && op->code != 9 && op->code != 12 && op->code != 15)
		get_types(op, hero);
	get_args(op);
	if (!(is_arg_labels(op, hero)))
		return (0);
	write_labels(hero, op);
	return (1);
}

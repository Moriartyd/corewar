/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 19:21:34 by ddratini          #+#    #+#             */
/*   Updated: 2020/07/24 15:06:52 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			get_args(t_op *op)
{
	int i;
	int j;

	i = 0;
	while (i < 3 && op->args[i])
	{
		j = 0;
		if (op->args[i][j] == 'r')
		{
			op->nargs[i] = atoli(op->args[i] + j + 1);
			++i;
			continue ;//return (0);
		}
		if (op->args[i] && op->args[i][j] == '%')
			++j;
		if (op->args[i] && op->args[i][j] == ':')//congrats you have a str!
			op->curlabels[i] = op->args[i] + j + 1;
		else
			op->nargs[i] = atoli(op->args[i] + j);
		++i;
	}
	return (0);
}

int			get_types(t_op *op, t_hero *hero)
{
	int 			i;
	unsigned char	type;
	unsigned int	offset;

	i = -1;
	type = 0;
	offset = 64;
	while (++i < 3)
	{
		if (op->types[i] == T_REG)
			type |= offset;
		else if (op->types[i] == T_DIR)
			type |= offset * 2;
		else if (op->types[i] == T_IND)
		{
			type |= offset;
			type |= offset * 2;
		}
		offset /= 2 * 2;
	}
	hero->excode[hero->p++] = type;
	return (1);
}

unsigned int	index_count(t_hero *hero)
{
	unsigned int bcsz;
	int i;
	t_op	*beg;

	beg = hero->op;
	i = 0;
	bcsz = 0;
	while (beg)
	{
		bcsz += beg->bytes;
		beg->idop = ++i;
		beg = beg->next;
	}
	return (bcsz);
}

int				translator(t_hero *hero, char **av)
{
	unsigned char 	bc[2192] = {0};
	t_op			*beg;
	unsigned int	bcsz;

	bcsz = index_count(hero);
	beg = hero->op;
	while (beg)
	{
		if (!(op_code(beg, hero)))
		{
			printf("LABEL_ERROR_DOUBLE\n");
			return (12);
		}
		beg = beg->next;
	}
	write_filler(bc, hero, bcsz, av);
	return (0);
}

void		init_op_add(t_op *op)
{
	int i;

	i = -1;
	while (++i < 3)
	{
		op->curlabels[i] = 0;
		op->nargs[i] = INT64_MAX;
	}
}


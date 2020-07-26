/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 20:21:24 by cpollich          #+#    #+#             */
/*   Updated: 2020/07/26 15:30:35 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	init_op_add(t_op *op)
{
	int i;

	i = -1;
	while (++i < 3)
	{
		op->curlabels[i] = 0;
		op->nargs[i] = INT64_MAX;
	}
}

t_op		*new_op(void)
{
	t_op	*res;
	int		i;

	res = (t_op *)malloc(sizeof(t_op));
	if (!res)
		quit(EN_MALLOC, NULL, NULL);
	res->code = 0;
	i = 0;
	while (i < 3)
	{
		res->types[i] = 0;
		res->args[i] = 0;
		i++;
	}
	init_op_add(res);
	i = -1;
	while (++i < LABELS)
		res->labels[i] = NULL;
	res->prev = 0;
	res->next = 0;
	return (res);
}

void		del_ops(t_op *op)
{
	t_op	*tmp;
	int		i;

	if (op)
	{
		while (op)
		{
			i = 0;
			while (op->labels[i])
			{
				ft_strdel(&(op->labels[i]));
				i++;
			}
			i = -1;
			while (++i < 3)
				if (op->args[i])
					ft_strdel(&(op->args[i]));
			tmp = op->next;
			free(op);
			op = tmp;
		}
	}
}

/*
**	Добавляет в конец списка новую инструкцию
*/

t_op		*add_op(t_op *op)
{
	t_op	*res;

	res = op;
	while (op && op->next)
		op = op->next;
	if (op)
	{
		op->next = new_op();
		op->next->prev = op;
		op->next->next = NULL;
	}
	else
	{
		op = new_op();
		res = op;
	}
	return (res);
}

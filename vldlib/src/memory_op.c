/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 20:21:24 by cpollich          #+#    #+#             */
/*   Updated: 2020/07/15 18:33:37 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vldlib.h"

t_op	*new_op(void)
{
	t_op	*res;
	int		i;

	res = (t_op *)malloc(sizeof(t_op));
	if (!res)
		exit(-1);//Malloc Error
	res->code = 0;
	i = 0;
	while (i < 3)
	{
		res->types[i] = 0;
		res->args[i] = 0;
	}
	res->labels = NULL;
	res->prev = 0;
	res->next = 0;
	return (res);
}

void	del_ops(t_op *op)
{
	t_op	*tmp;

	if (op)
	{
		while (op)
		{
			ft_doublestrdel(&(op->labels));
			tmp = op->next;
			free(op);
			op = tmp;
		}
	}
}

/*
** Парсит строку на инструкцию
*/

static void	fill_op(t_op *op, const char *str)
{
	
}

/*
**	Добавляет в конец списка новую инструкцию
*/

void	add_op(t_op *op, const char *str)
{
	while (op->next)
		op = op->next;
	op->next = new_op();
	op->next->prev = op;
	op->next->next = NULL;
	// fill_op(op->next, str);
}
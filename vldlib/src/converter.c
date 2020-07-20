/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 19:39:05 by cpollich          #+#    #+#             */
/*   Updated: 2020/07/20 16:58:27 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vldlib.h"

static int		get_bytes(t_vldop *op)
{
	int	i;
	int	bytes;

	i = 0;
	bytes = 1;
	if (get_argt(op->code))
		bytes += 1;
	while (i < 3 && op->args[i])
	{
		if (op->args[i] == T_DIR)
			bytes += get_dirsize(op->code);
		else if (op->args[i] == T_IND)
			bytes += 2;
		else if (op->args[i] == T_REG)
			bytes += 1;
		i++;
	}
	return (bytes);
}

static void		convert_charargs(t_vldop *op, t_op *p)
{
	if (op->args[0])
	{
		p->args[0] = ft_strnewncp(op->arg1, ft_strlen(op->arg1));
		if (!p->args[0])
			exit(-1); //Malloc error
	}
	if (op->args[1])
	{
		p->args[1] = ft_strnewncp(op->arg2, ft_strlen(op->arg2));
		if (!p->args[1])
			exit(-1); //Malloc error
	}
	if (op->args[2])
	{
		p->args[2] = ft_strnewncp(op->arg3, ft_strlen(op->arg3));
		if (!p->args[2])
			exit(-1); //Malloc error
	}
}

int				convert_vldop_op(t_vldop *op, t_hero **hero, int type)
{
	int		i;
	t_op	*p;

	(*hero)->op = add_op((*hero)->op);
	p = (*hero)->op;
	while (p && p->next)
		p = p->next;
	if (op->labels[0] && !op->code)
		exit(-1);// Labels without instructions
	check_args(op);
	p->bytes = get_bytes(op);
	p->code = op->code;
	i = 0;
	while (op->labels[i])
	{
		if (!(p->labels[i] = ft_strnewncp(op->labels[i], ft_strlen(op->labels[i]))))
			exit (-1); //Malloc error
		i++;
	}
	i = 3;
	while (--i >= 0)
		p->types[i] = op->args[i];
	convert_charargs(op, p);
	vldop_del(&op);
	return (type);
}
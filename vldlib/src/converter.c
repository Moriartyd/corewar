/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 19:39:05 by cpollich          #+#    #+#             */
/*   Updated: 2020/07/19 21:34:52 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vldlib.h"

static int		get_bytes(t_vldop *op)
{
	int	i;
	int	bytes;
	int	dirsize;

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

int				convert_vldop_op(t_vldop *op, t_hero **hero, int type)
{
	int		i;
	t_op	*p;

	p = (*hero)->op;
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
	while (--i >= 0)
		p->types[i] = op->args[i];
	return (1);
}
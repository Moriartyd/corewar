/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_vldop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 20:22:41 by cpollich          #+#    #+#             */
/*   Updated: 2020/07/20 17:13:05 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vldlib.h"

t_vldop *vldop_init(void)
{
	t_vldop	*op;
	int		i;

	if (!(op = (t_vldop *)malloc(sizeof(t_vldop))))
		return (NULL);
	i = -1;
	while (++i < LABELS)
		op->labels[i] = NULL;
	op->code = 0;
	ft_bzero(op->args, sizeof(int) * 3);
	op->arg1 = NULL;
	op->arg2 = NULL;
	op->arg3 = NULL;
	return(op);
}

void	vldop_del(t_vldop **op)
{
	int	i;

	if (op && *op)
	{
		i = 0;
		while (i < LABELS && (*op)->labels[i])
		{
			ft_strdel(&((*op)->labels[i]));
			i++;
		}
		ft_strdel(&((*op)->arg1));
		ft_strdel(&((*op)->arg2));
		ft_strdel(&((*op)->arg3));
		free(*op);
		*op = NULL;
	}
}
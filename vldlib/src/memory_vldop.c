/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_vldop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 20:22:41 by cpollich          #+#    #+#             */
/*   Updated: 2020/07/18 21:50:51 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vldlib.h"

t_vldop *op_init(void)
{
	t_vldop	*op;
	int		i;

	if (!(op = (t_vldop *)malloc(sizeof(t_vldop))))
		return (NULL);
	i = -1;
	while (++i < LABELS)
		op->labels[i] = NULL;
	op->code = 0;
	op->arg1 = NULL;
	op->arg2 = NULL;
	op->arg3 = NULL;
	return(op);
}
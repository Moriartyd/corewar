/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_inst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 19:56:11 by cpollich          #+#    #+#             */
/*   Updated: 2020/07/19 16:12:01 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vldlib.h"

void	read_inst(char *str, t_vldop *op)
{
	int	i;

	i = 0;
	while (str[i] && !need_char(str[i]))
		i++;
	op->code = check_opname(str);
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (!str[i] || str[i] == '\n')
		exit(-1); //Syntax Error
	read_arguments(&str[i], op);
}

void	parse_instruct(char *str, int type, int fd, t_hero **hero)
{
	int		i;
	t_vldop	*op;

	i = 0;
	if (!(op = op_init()))
		exit(-1);//Malloc error
	if (type == 3) //Metka
	{
		// while (is_label())
		
	}
	if (type == 4) //Instruction
	{
		read_inst(str, op);
	}
}
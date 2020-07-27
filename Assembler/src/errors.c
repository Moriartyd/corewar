/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 20:09:22 by cpollich          #+#    #+#             */
/*   Updated: 2020/07/27 18:12:35 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	write_inst2(int c)
{
	if (c == OP_LLD)
		write(ERRSTREAM, "lld", 3);
	else if (c == OP_LLDI)
		write(ERRSTREAM, "lldi", 4);
	else if (c == OP_LFORK)
		write(ERRSTREAM, "lfork", 5);
	else if (c == OP_AFF)
		write(ERRSTREAM, "aff", 3);
	else if (c == OP_FORK)
		write(ERRSTREAM, "fork", 4);
}

static void	write_inst(int c)
{
	if (c == OP_LIVE)
		write(ERRSTREAM, "live", 4);
	else if (c == OP_LD)
		write(ERRSTREAM, "ld", 2);
	else if (c == OP_ST)
		write(ERRSTREAM, "st", 2);
	else if (c == OP_ADD)
		write(ERRSTREAM, "add", 3);
	else if (c == OP_SUB)
		write(ERRSTREAM, "sub", 3);
	else if (c == OP_AND)
		write(ERRSTREAM, "and", 3);
	else if (c == OP_OR)
		write(ERRSTREAM, "or", 2);
	else if (c == OP_XOR)
		write(ERRSTREAM, "xor", 3);
	else if (c == OP_ZJMP)
		write(ERRSTREAM, "zjmp", 4);
	else if (c == OP_LDI)
		write(ERRSTREAM, "ldi", 3);
	else if (c == OP_STI)
		write(ERRSTREAM, "sti", 3);
	else
		write_inst2(c);
}

static void	exit_with_op(int e, t_vldop *op, char *str)
{
	if ((e >= EN_DIR && e <= EN_REG) || e == EN_INOP)
	{
		(e == EN_DIR) ? write(ERRSTREAM, E_DIR, ft_strlen(E_DIR)) : 0;
		(e == EN_IND) ? write(ERRSTREAM, E_IND, ft_strlen(E_IND)) : 0;
		if (e == EN_REG)
			write(ERRSTREAM, E_REG, ft_strlen(E_REG));
		if (e == EN_INOP)
			write(ERRSTREAM, E_INOP, ft_strlen(E_INOP));
		write(ERRSTREAM, str, ft_strlen(str));
		write(ERRSTREAM, "]\n", 2);
	}
	else
	{
		if (e == EN_ARGS1)
			write(ERRSTREAM, E_ARGS1, ft_strlen(E_ARGS1));
		if (e == EN_ARGS2)
			write(ERRSTREAM, E_ARGS2, ft_strlen(E_ARGS2));
		if (e == EN_ARGS3)
			write(ERRSTREAM, E_ARGS3, ft_strlen(E_ARGS3));
		if (e == EN_ARGS4)
			write(ERRSTREAM, E_ARGS4, ft_strlen(E_ARGS4));
		write_inst(op->code);
		write(ERRSTREAM, "]\n", 2);
	}
	exit(0);
}

void		quit(int e, t_vldop *op, char *arg)
{
	if (op || arg)
		exit_with_op(e, op, arg);
	if (e == EN_LASTSTR)
		write(ERRSTREAM, E_LASTSTR, ft_strlen(E_LASTSTR));
	else if (e == EN_TRASH)
		write(ERRSTREAM, E_TRASH, ft_strlen(E_TRASH));
	else if (e == EN_MORENAMES)
		write(ERRSTREAM, E_MORENAMES, ft_strlen(E_MORENAMES));
	else if (e == EN_READ)
		write(ERRSTREAM, E_READ, ft_strlen(E_READ));
	else if (e == EN_MALLOC)
		write(ERRSTREAM, E_MALLOC, ft_strlen(E_MALLOC));
	else if (e == EN_NAMECHARS)
		write(ERRSTREAM, E_NAMECHARS, ft_strlen(E_NAMECHARS));
	else if (e == EN_CHAMP)
		write(ERRSTREAM, E_CHAMP, ft_strlen(E_CHAMP));
	else if (e == EN_CHAMPMISS)
		write(ERRSTREAM, E_CHAMPMISS, ft_strlen(E_CHAMPMISS));
	else if (e == EN_INST)
		write(ERRSTREAM, E_INST, ft_strlen(E_INST));
	else if (e == EN_LABEL)
		write(ERRSTREAM, E_LABEL, ft_strlen(E_LABEL));
	else if (e == EN_NOINST)
		write(ERRSTREAM, E_NOINST, ft_strlen(E_NOINST));
	exit(0);
}

void		ft_quit(int e, char c)
{
	if (e == -2)
		quit(EN_MALLOC, NULL, NULL);
	else if (e == -1)
		perror(E_FILE);
	else if (e == -3)
	{
		write(ERRSTREAM, E_SYMBOL, ft_strlen(E_SYMBOL));
		if (c == '\n')
			write(ERRSTREAM, "\\n", 2);
		else
			write(ERRSTREAM, &c, 1);
		write(ERRSTREAM, "]\n", 2);
	}
	exit(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 20:09:22 by cpollich          #+#    #+#             */
/*   Updated: 2020/07/21 16:45:52 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	write_inst2(int c)
{
	if (c == OP_LLD)
		write(STDERR_FILENO, "lld", 3);
	else if (c == OP_LLDI)
		write(STDERR_FILENO, "lldi", 4);
	else if (c == OP_LFORK)
		write(STDERR_FILENO, "lfork", 5);
	else if (c == OP_AFF)
		write(STDERR_FILENO, "aff", 3);
	else if (c == OP_FORK)
		write(STDERR_FILENO, "fork", 4);
}

static void	write_inst(int c)
{
	if (c == OP_LIVE)
		write(STDERR_FILENO, "live", 4);
	else if (c == OP_LD)
		write(STDERR_FILENO, "ld", 2);
	else if (c == OP_ST)
		write(STDERR_FILENO, "st", 2);
	else if (c == OP_ADD)
		write(STDERR_FILENO, "add", 3);
	else if (c == OP_SUB)
		write(STDERR_FILENO, "sub", 3);
	else if (c == OP_AND)
		write(STDERR_FILENO, "and", 3);
	else if (c == OP_OR)
		write(STDERR_FILENO, "or", 2);
	else if (c == OP_XOR)
		write(STDERR_FILENO, "xor", 3);
	else if (c == OP_ZJMP)
		write(STDERR_FILENO, "zjmp", 4);
	else if (c == OP_LDI)
		write(STDERR_FILENO, "ldi", 3);
	else if (c == OP_STI)
		write(STDERR_FILENO, "sti", 3);
	else
		write_inst2(c);
}

static void	exit_with_op(int e, t_vldop *op, char *str)
{
	if (e >= EN_DIR && e <= EN_REG)
	{
		if (e == EN_DIR)
			write(STDERR_FILENO, E_DIR, ft_strlen(E_DIR));
		if (e == EN_IND)
			write(STDERR_FILENO, E_IND, ft_strlen(E_IND));
		if (e == EN_REG)
			write(STDERR_FILENO, E_REG, ft_strlen(E_REG));
		write(STDERR_FILENO, str, ft_strlen(str));
		write(STDERR_FILENO, "]\n", 2);
	}
	else
	{
		if (e == EN_ARGS1)
			write(STDERR_FILENO, E_ARGS1, ft_strlen(E_ARGS1));
		if (e == EN_ARGS2)
			write(STDERR_FILENO, E_ARGS2, ft_strlen(E_ARGS2));
		if (e == EN_ARGS3)
			write(STDERR_FILENO, E_ARGS3, ft_strlen(E_ARGS3));
		if (e == EN_ARGS4)
			write(STDERR_FILENO, E_ARGS4, ft_strlen(E_ARGS4));
		write_inst(op->code);
		write(STDERR_FILENO, "]\n", 2);
	}
	exit(0);
}

void		quit(int e, t_vldop *op, char *arg)
{
	if (op)
		exit_with_op(e, op, arg);
	if (e == EN_LASTSTR)
		write(STDERR_FILENO, E_LASTSTR, ft_strlen(E_LASTSTR));
	else if (e == EN_TRASH)
		write(STDERR_FILENO, E_TRASH, ft_strlen(E_TRASH));
	else if (e == EN_MORENAMES)
		write(STDERR_FILENO, E_MORENAMES, ft_strlen(E_MORENAMES));
	else if (e == EN_READ)
		write(STDERR_FILENO, E_READ, ft_strlen(E_READ));
	else if (e == EN_MALLOC)
		write(STDERR_FILENO, E_MALLOC, ft_strlen(E_MALLOC));
	else if (e == EN_NAMECHARS)
		write(STDERR_FILENO, E_NAMECHARS, ft_strlen(E_NAMECHARS));
	else if (e == EN_CHAMP)
		write(STDERR_FILENO, E_CHAMP, ft_strlen(E_CHAMP));
	else if (e == EN_CHAMPMISS)
		write(STDERR_FILENO, E_CHAMPMISS, ft_strlen(E_CHAMPMISS));
	else if (e == EN_INST)
		write(STDERR_FILENO, E_INST, ft_strlen(E_INST));
	else if (e == EN_LABEL)
		write(STDERR_FILENO, E_LABEL, ft_strlen(E_LABEL));
	else if (e == EN_NOINST)
		write(STDERR_FILENO, E_NOINST, ft_strlen(E_NOINST));
	exit(0);
}

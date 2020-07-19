/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_patterns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 21:54:05 by cpollich          #+#    #+#             */
/*   Updated: 2020/07/19 17:11:24 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vldlib.h"

static void	get_patterns4(int code, int args[3])
{
	if (code == OP_LLD)
	{
		args[0] = A1_LLD;
		args[1] = A2_LLD;
		args[2] = A3_LLD;
	}
	else if (code == OP_LLDI)
	{
		args[0] = A1_LLDI;
		args[1] = A2_LLDI;
		args[2] = A3_LLDI;
	}
	else if (code == OP_LFORK)
	{
		args[0] = A1_LFORK;
		args[1] = A2_LFORK;
		args[2] = A3_LFORK;
	}
	else if (code == OP_AFF)
	{
		args[0] = A1_AFF;
		args[1] = A2_AFF;
		args[2] = A3_AFF;
	}
}

static void	get_patterns3(int code, int args[3])
{
	if (code == OP_ZJMP)
	{
		args[0] = A1_ZJMP;
		args[1] = A2_ZJMP;
		args[2] = A3_ZJMP;
	}
	else if (code == OP_LDI)
	{
		args[0] = A1_LDI;
		args[1] = A2_LDI;
		args[2] = A3_LDI;
	}
	else if (code == OP_STI)
	{
		args[0] = A1_STI;
		args[1] = A2_STI;
		args[2] = A3_STI;
	}
	else if (code == OP_FORK)
	{
		args[0] = A1_FORK;
		args[1] = A2_FORK;
		args[2] = A3_FORK;
	}
	else
		get_patterns4(code, args);
}

static void	get_patterns2(int code, int args[3])
{
	if (code == OP_SUB)
	{
		args[0] = A1_SUB;
		args[1] = A2_SUB;
		args[2] = A3_SUB;
	}
	else if (code == OP_AND)
	{
		args[0] = A1_AND;
		args[1] = A2_AND;
		args[2] = A3_AND;
	}
	else if (code == OP_OR)
	{
		args[0] = A1_OR;
		args[1] = A2_OR;
		args[2] = A3_OR;
	}
	else if (code == OP_XOR)
	{
		args[0] = A1_XOR;
		args[1] = A2_XOR;
		args[2] = A3_XOR;
	}
	else
		get_patterns3(code, args);
}

void	get_patterns(int code, int args[3])
{
	if (code == OP_LIVE)
	{
		args[0] = A1_LIVE;
		args[1] = A2_LIVE;
		args[2] = A3_LIVE;
	}
	else if (code == OP_LD)
	{
		args[0] = A1_LD;
		args[1] = A2_LD;
		args[2] = A3_LD;
	}
	else if (code == OP_ST)
	{
		args[0] = A1_ST;
		args[1] = A2_ST;
		args[2] = A3_ST;
	}
	else if (code == OP_ADD)
	{
		args[0] = A1_ADD;
		args[1] = A2_ADD;
		args[2] = A3_ADD;
	}
	else
		get_patterns2(code, args);
}
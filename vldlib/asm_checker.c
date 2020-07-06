/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 17:45:47 by cpollich          #+#    #+#             */
/*   Updated: 2020/07/06 17:23:23 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vldlib.h"

int	show_usage(void)
{
	write(1, USAGE_ASM_M, USAGE_ASM_L);
	return (-1);
}

int	invalid_asm(int code)
{
	if (code == INV_NAME)
		write(1, INV_NAME_M, INV_NAME_L);
	return (0);
}

int	check_base_asm(int ac, char **av)
{
	t_hero	*hero;

	if (!(hero = (t_hero *)malloc(sizeof(t_hero))))
		exit(-1);
	if (ac != 2)
		return (show_usage());
	else if (check_asm(av[1], hero) != 1)
		//Invalid name func
		return (invalid_asm(INV_NAME));
	// else if (check_asm_comment(av[1]) != 1)
	// 	//invalid comment
	// 	return (invalid_asm(INV_COMMENT));
	return (0);
}

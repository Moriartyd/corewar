/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vldlib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 17:37:16 by cpollich          #+#    #+#             */
/*   Updated: 2020/07/13 19:27:39 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef VLDLIB_H
#	define VLDLIB_H

#include "../../libft/inc/libft.h"
#include "../../inc/op.h"
#include <stdio.h>

#	define USAGE_VM_M "usage:"
#	define USAGE_VM_L 6

/*
**	ASM
*/
#	define USAGE_ASM_M	"usage: ./asm champion.s\n"
#	define USAGE_ASM_L	24
#	define INV_NAME		1
#	define INV_COMMENT	2
#	define INV_SOME		3

#	define INV_NAME_M	"name invalid\n"
#	define INV_NAME_L	13

typedef struct  s_hero
{
	char        *name;
	char        *comment;
}               t_hero;

typedef struct	s_op
{
	int			code;
	int			types[3];
	int			args[3];
	struct s_op	*prev;
	struct s_op	*next;
}				t_op;

int				check_base_asm(int ac, char **av);
int				check_asm(char *file, t_hero *hero);
int				ft_read_until_ch(int fd, int c, char **str);
int				get_type(char *str, int bytes, int fd);
int				check_namecomm(char *str, int type, int fd);

#	endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vldlib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 17:37:16 by cpollich          #+#    #+#             */
/*   Updated: 2020/07/15 23:25:59 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef VLDLIB_H
#	define VLDLIB_H

#include "libft.h"
#include "op.h"

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

#	define OP_LIVE	0x01
#	define OP_LD	0x02
#	define OP_ST	0x03
#	define OP_ADD	0x04
#	define OP_SUB	0x05
#	define OP_AND	0x06
#	define OP_OR	0x07
#	define OP_XOR	0x08
#	define OP_ZJMP	0x09
#	define OP_LDI	0x0a
#	define OP_STI	0x0b
#	define OP_FORK	0x0c
#	define OP_LLD	0x0d
#	define OP_LLDI	0x0e
#	define OP_LFORK	0x0f
#	define OP_AFF	0x10

#	define STR_LFORK	"lfork"
#	define STR_LIVE		"live"
#	define STR_FORK		"fork"
#	define STR_ZJMP		"zjmp"

/*
**	Bytes - сколько байт занимает данная операция
*/

typedef struct	s_op
{
	int			code;
	int			types[3];
	int			args[3];
	int			bytes;
	char		**labels;
	struct s_op	*prev;
	struct s_op	*next;
}				t_op;

typedef struct  s_hero
{
	char        *name;
	char        *comment;
	t_op		*op;
}               t_hero;

/*
**	* ft_read_until_ch	-	читает файл посимвольно до символа c, 
**							возвращает количество прочитанного.
**	* get_type			-	определяет тип считанной строки
**							(сам модет читать строки)
**	* need_char			-	проверка на DIRECT_CHAR, пробел, таб, минус
							возвращает 0, если другой символ
*/

int				ft_read_until_ch(int fd, int c, char **str);
int				get_type(char **str, int bytes, int fd, t_hero **hero);
int				check_namecomm(char *str, int type, int fd, t_hero **hero);
void			check_file(int fd, t_hero **hero);
void			fill_hero(int type, char **str, t_hero **hero);
int				need_char(char c);

/*
**	letter_check.c
*/

int				a_check(char *str);
int				l_check(char *str);
int				s_check(char *str);
int				fxoz_check(char *str);

/*
**	check_opname.c
*/

int				check_opname(char *str);

/*
**		MEMORY BLOCK
*/

t_hero			*init_hero(void);
void			del_hero(t_hero **hero);
t_op			*new_op(void);
void			del_ops(t_op *op);


#	endif

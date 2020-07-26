/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 20:10:58 by cpollich          #+#    #+#             */
/*   Updated: 2020/07/26 16:43:05 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef ASM_H
#	define ASM_H

#include "libft.h"
#include "op.h"
#include <stdio.h>

#	define USAGE_VM_M "usage:"
#	define USAGE_VM_L 6

/*
**	Errors
*/

#	define E_DIR		"Error in T_DIR argument ["
#	define E_IND		"Error in T_IND argument ["
#	define E_REG		"Error in T_REG argument ["
#	define E_LASTSTR	"It seems that you forgot \\n in the end of file\n"
#	define E_TRASH		"Some trash in file\n"
#	define E_MORENAMES	"You wrote more than one champion's name or comment\n"
#	define E_READ		"I can't read this file\n"
#	define E_MALLOC		"Malloc can't work anymore, sorry ;(\n"
#	define E_NAMECHARS	"Too much symbols in champion's name or comment\n"
#	define E_CHAMP		"You made a mistake in chamion's name or comment\n"
#	define E_CHAMPMISS	"You didn't write champion's name or comment\n"
#	define E_INST		"You forgot to write an instruction after the label\n"
#	define E_LABEL		"You made a mistake in label\n"
#	define E_ARGS1		"You forgot to write arguments after the instruction ["
#	define E_ARGS2		"I can't read some of the arguments of instruction ["
#	define E_ARGS3		"Some arguments are misplaced in instruction ["
#	define E_ARGS4		"You lost some arguments in instruction ["
#	define E_NOINST		"No instructions in file\n"
#	define E_FILE		"Can't read or open file"
#	define E_SYMBOL		"The file ended before I found a symbol ["

#	define EN_DIR		1
#	define EN_IND		2
#	define EN_REG		3
#	define EN_LASTSTR	4
#	define EN_TRASH		5
#	define EN_MORENAMES	6
#	define EN_READ		7
#	define EN_MALLOC	8
#	define EN_NAMECHARS	9
#	define EN_CHAMP		10
#	define EN_CHAMPMISS	11
#	define EN_INST		12
#	define EN_LABEL		13
#	define EN_ARGS1		14
#	define EN_ARGS2		15
#	define EN_ARGS3		16
#	define EN_ARGS4		17
#	define EN_NOINST	18

/*
**	ASM
*/
#	define LABELS		9999
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

/*
**	T_DIR	-	1
**	T_REG	-	2
**	T_INDIR	-	4
*/

#	define A1_LIVE	T_DIR
#	define A1_LD	T_DIR | T_IND
#	define A1_ST	T_REG
#	define A1_ADD	T_REG
#	define A1_SUB	T_REG
#	define A1_AND	T_REG | T_DIR | T_IND
#	define A1_OR	T_REG | T_DIR | T_IND
#	define A1_XOR	T_REG | T_DIR | T_IND
#	define A1_ZJMP	T_DIR
#	define A1_LDI	T_REG | T_DIR | T_IND
#	define A1_STI	T_REG
#	define A1_FORK	T_DIR
#	define A1_LLD	T_DIR | T_IND
#	define A1_LLDI	(T_REG | T_DIR | T_IND)
#	define A1_LFORK	T_DIR
#	define A1_AFF	T_REG

#	define A2_LIVE	0
#	define A2_LD	T_REG
#	define A2_ST	T_REG | T_IND
#	define A2_ADD	T_REG
#	define A2_SUB	T_REG
#	define A2_AND	T_REG | T_DIR | T_IND
#	define A2_OR	T_REG | T_DIR | T_IND
#	define A2_XOR	T_REG | T_DIR | T_IND
#	define A2_ZJMP	0
#	define A2_LDI	T_REG | T_DIR
#	define A2_STI	T_REG | T_DIR | T_IND
#	define A2_FORK	0
#	define A2_LLD	T_REG
#	define A2_LLDI	(T_REG | T_DIR)
#	define A2_LFORK	0
#	define A2_AFF	0

#	define A3_LIVE	0
#	define A3_LD	0
#	define A3_ST	0
#	define A3_ADD	T_REG
#	define A3_SUB	T_REG
#	define A3_AND	T_REG
#	define A3_OR	T_REG
#	define A3_XOR	T_REG
#	define A3_ZJMP	0
#	define A3_LDI	T_REG
#	define A3_STI	T_REG | T_DIR
#	define A3_FORK	0
#	define A3_LLD	0
#	define A3_LLDI	T_REG
#	define A3_LFORK	0
#	define A3_AFF	0

#	define STR_LFORK	"lfork"
#	define STR_LIVE		"live"
#	define STR_FORK		"fork"
#	define STR_ZJMP		"zjmp"

#	define BCSZ 10000
#	define NO_LABEL_PNT 0
#	define NO_LABEL_ARG 2

/*
**	Bytes - сколько байт занимает данная операция
*/

typedef struct	s_vldop
{
	char		*labels[LABELS];
	int			code;
	int			args[3];
	char		*arg1;
	char		*arg2;
	char		*arg3;

}				t_vldop;

typedef struct	s_op
{
	int			code;
	int			types[3];
	char		*args[3];
	int			bytes;
	char		*labels[LABELS];
	char 		*curlabels[3];
	long		nargs[3];
	int			idop;
	struct s_op	*prev;
	struct s_op	*next;
}				t_op;

typedef struct	s_hero
{
	char		*name;
	char		*comment;
	t_op		*op;
	unsigned char	excode[BCSZ];
	int 			p;
}				t_hero;

void		ft_print_bits(unsigned char octet);
int 		print_byte_int(int x);
void		init_op_add(t_op *op);
int			op_code(t_op *op, t_hero *h);
int			get_types(t_op *op, t_hero *h);
int			get_args(t_op *op);

int			translator(t_hero *hero, char *av);
long		atoli(char *str);
int			write_filler(unsigned char *b, t_hero *h, unsigned int s, char *f);

/*
**	* ft_read_until_ch	-	читает файл посимвольно до символа c,
**							возвращает количество прочитанного.
**	* get_type			-	определяет тип считанной строки
**							(сам модет читать строки)
**	* need_char			-	проверка на DIRECT_CHAR, пробел, таб, минус
**							возвращает 0, если другой символ
*/

int				ft_read_until_ch(int fd, int c, char **str);
int				get_type(char **str, int bytes, int fd, t_hero **hero);
int				check_namecomm(char **str, int type, int fd, t_hero **hero);
void			read_file(int fd, t_hero **hero);
void			fill_hero(int type, char **str, t_hero **hero);
int				need_char(char c);

/*
**	INSTRUCTION PARSE
*/
int				is_correct_label(char *str);
int				is_inst(char *str);
int				is_label(char *str);
int				is_blank(char *str);
int				sep_char(char c);
void			get_patterns(int code, int args[3]);
void			read_arguments(char *str, t_vldop *op);
int				parse_instruct(char *str, int type, int fd, t_hero **hero);
int				get_dirsize(int code);
int				get_argt(int code);
int				check_args(t_vldop *op);
int				convert_vldop_op(t_vldop *op, t_hero **hero, int type);

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
t_op			*add_op(t_op *op);
void			del_ops(t_op *op);
t_vldop			*vldop_init(void);
void			vldop_del(t_vldop **op);

void			quit(int e, t_vldop *op, char *arg);
void			ft_quit(int e, char c);

#	endif

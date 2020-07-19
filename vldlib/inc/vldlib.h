/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vldlib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Updated: 2020/07/13 21:48:09 by cpollich         ###   ########.fr       */
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

/*
**	Bytes - сколько байт занимает данная операция
*/

typedef struct	s_op
{
	int			code;
	int			types[3];
	int			nargs[3];
	char		*arg[3];//char **args;
	int			bytes;
	char		**labels;
	char 		*curlabels[3];
	struct s_op	*prev;
	struct s_op	*next;
}				t_op;

typedef struct  s_hero
{
	char        *name;
	char        *comment;
	t_op		*op;
	char		excode[CHAMP_MAX_SIZE + 1];//682 + 1
}               t_hero;

/*
**	* ft_read_until_ch	-	читает файл посимвольно до символа c, 
**							возвращает количество прочитанного.
**	* get_type			-	определяет тип считанной строки
**							(сам модет читать строки)
**	*
*/

int				ft_read_until_ch(int fd, int c, char **str);
int				get_type(char *str, int bytes, int fd);
int				check_namecomm(char *str, int type, int fd);

/*
**		MEMORY BLOCK
*/

t_hero			*init_hero(void);
void			del_hero(t_hero *hero);
t_op			*new_op(void);
void			del_ops(t_op *op);


void		ft_print_bits(unsigned char octet);
int 		print_byte_int(int x);
void		init_op_add(t_op *op);//for every op;
int			detect_op(t_op *op, int fd, unsigned char bc[2192]);
int			op_live(t_op *op, int fd, unsigned char bc[2192]);
int			get_types(t_op *op);
int			get_args(t_op *op);





#	endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 19:21:34 by ddratini          #+#    #+#             */
/*   Updated: 2020/07/14 18:17:37 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vldlib/inc/vldlib.h"

int		write_magicheader(unsigned char *bc, t_hero *hero)
{
	int fd;
	char *fname;
	int retw;

	//mh[0] = COREWAR_EXEC_MAGIC
//	bc[0] = 243;//3;
//	bc[1] = 131;//15;
//	bc[2] = 234;//3;
//	bc[3] = 0;//8;
	bc[0] = 0;//3;
	bc[1] = 234;//15;
	bc[2] = 131;//3;
	bc[3] = 243;//8;
	printf("MYSEGA\n");
	ft_memcpy(bc + 4, hero->name, PROG_NAME_LENGTH);
	ft_memcpy(bc + 140, hero->comment, COMMENT_LENGTH);
	printf("MYSEGA\n");
	//bc + 4 = &(*hero->name);
	//bc + 140 = (unsigned char *)hero->comment;
	fname = "x.cor";
//	fd = open("name1.cor", O_RDWR | O_TRUNC | O_CREAT , 0666);////O_RDWR);
	fd = open("name2.cor", O_CREAT| O_TRUNC | O_RDWR , 0666);////O_RDWR);
////	printf("FDopened some file CREAT=%d\n",fd);
//	fd = open("name1.cor", O_RDWR);
	/////printf("FDopened some file RDWR=%d\n",fd);
	//retw = write(fd, "0xea83f3", 4 * 2);
	retw = write(fd, bc, 4);
	retw = write(fd, bc + 4, 128);
	write(fd, bc + 132, 4);
	write(fd, bc + 136, 4);
	write(fd, bc + 140, 2048);
	write(fd, bc + 2188, 4);
	printf("RETW=%d\n", retw);
	return (fd);
}

int			get_args(t_op *op)
{
	int i;
	int j;

	i = 0;
	j = 0;
	printf("%s\n", op->arg[i]);
	while (	printf("%p\n", op->arg[i]) && op->arg[i])
	{
		printf("%s\n", op->arg[i]);
		if (op->arg[i][j] == 'r')
		{
			op->nargs[i] = ft_atoi(op->arg[i] + j + 1);
			++i;
			continue ;//return (0);
		}
		if (op->arg[i] && op->arg[i][j] == '%')
			++j;
		if (op->arg[i] && op->arg[i][j] == ':')//congrats you have a str!
			op->curlabels[i] = op->arg[i] + j + 1;
		else
			op->nargs[i] = ft_atoi(op->arg[i] + j);
		++i;
	}
	return (0);
}

int			get_types(t_op *op)
{
	int 			i;
	unsigned char	type;
	unsigned int				offset;

	i = -1;
	type = 0;
	offset = 64;
	op->types[0] = 1; op->types[1] = 3; op->types[2] = 2;
	while (++i < 3)
	{
		if (op->types[i] == 1)
			type |= offset;
		else if (op->types[i] == 2)
			type |= offset * 2;
		else if (op->types[i] == 3)
		{
			type |= offset;
			type |= offset * 2;
		}
		offset /= 2 * 2;
		ft_print_bits(type);
	}
	return (1);
}

int			op_live(t_op *op, int fd, unsigned char bc[2192])
{
	//unsigned char bc[1];
	char live;

	live = 01;
	write(fd, &live, 1);
	get_types(op);
	get_args(op);
	return (0);
}

int			detect_op(t_op *op, int fd, unsigned char bc[2192])
{
	if (op->code == 1)
	{
		op_live(op, fd, bc);
	}
	return (0);
}

int			translator(t_hero *hero)
{
	unsigned char bc[2192] = {0};
	unsigned char excode[CHAMP_MAX_SIZE + 1];//682 + 1
	int fd;
	int x;

	fd = write_magicheader(bc, hero);
	x = COREWAR_EXEC_MAGIC << 8;
	//x = 1;
	print_byte_int(x);
	hero->op->code = 1;
	detect_op(hero->op, fd, bc);
	printf("ASSMCHECK");
	return (0);
}

void		init_op_add(t_op *op)//for every op
{
	int i;

	i = -1;
	while (++i < 3)
	{
		op->curlabels[i] = 0;
		op->nargs[i] = INT32_MAX;
	}
}

int 		main(int ac, char **av)
{
	t_hero hero;
	t_op   costil;

	hero.name = ft_strdup("Batman");
	hero.comment = ft_strdup("BAT SPEAKS! NOCHAR01!");
	hero.op  = &costil;
	init_op_add(hero.op);
	printf("MSEGHERE\n");
	translator(&hero);
	return (0);
}

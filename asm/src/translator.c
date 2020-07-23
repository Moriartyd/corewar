/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 19:21:34 by ddratini          #+#    #+#             */
/*   Updated: 2020/07/20 17:03:52 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		write_filler(unsigned char *bc, t_hero *hero, int sz)
{
	int		fd;
	char	*fname;

	bc[0] = 0;
	bc[1] = 234;
	bc[2] = 131;
	bc[3] = 243;
	ft_memcpy(bc + 4, hero->name, PROG_NAME_LENGTH);
	ft_memcpy(bc + 140, hero->comment, COMMENT_LENGTH);
	fname = "x.cor";
//	fd = open("name1.cor", O_RDWR | O_TRUNC | O_CREAT , 0666);////O_RDWR);
	fd = open("name2.cor", O_CREAT| O_TRUNC | O_RDWR , 0666);////O_RDWR);
////	printf("FDopened some file CREAT=%d\n",fd);
//	fd = open("name1.cor", O_RDWR);
	/////printf("FDopened some file RDWR=%d\n",fd);
	write(fd, bc, 4);
	write(fd, bc + 4, 128);
	write(fd, bc + 132, 4);
	bc[136] = sz << 24;
	bc[137] = sz << 16;
	bc[138] = sz << 8;
	bc[139] = sz;
	write(fd, bc + 136, 4);//excodesize
	write(fd, bc + 140, 2048);
	write(fd, bc + 2188, 4);
	write(fd, hero->excode, sz);
	return (fd);
}

int			get_args(t_op *op)
{
	int i;
	int j;

	i = 0;
	while (i < 3 && op->args[i])
	{
		j = 0;
		if (op->args[i][j] == 'r')
		{
			op->nargs[i] = ft_atoi(op->args[i] + j + 1);
			++i;
			continue ;//return (0);
		}
		if (op->args[i] && op->args[i][j] == '%')
			++j;
		if (op->args[i] && op->args[i][j] == ':')//congrats you have a str!
			op->curlabels[i] = op->args[i] + j + 1;
		else
			op->nargs[i] = ft_atoi(op->args[i] + j);
		++i;
	}
	return (0);
}

int			get_types(t_op *op, t_hero *hero)
{
	int 			i;
	unsigned char	type;
	unsigned int	offset;

	i = -1;
	type = 0;
	offset = 64;
	while (++i < 3)
	{
		if (op->types[i] == T_REG)
			type |= offset;
		else if (op->types[i] == T_DIR)
			type |= offset * 2;
		else if (op->types[i] == T_IND)
		{
			type |= offset;
			type |= offset * 2;
		}
		offset /= 2 * 2;
	}
	hero->excode[hero->p++] = type;
	ft_print_bits(type);
	return (1);
}

int			translator(t_hero *hero)
{
	unsigned char 	bc[2192] = {0};
	int 			i;
	t_op			*beg;
	int				bcsz;
	int				id;

	//print_byte_int(x);
	beg = hero->op;
	bcsz = 0;
	id = 0;
	while (beg)
	{
		bcsz += beg->bytes;
		beg->idop = ++id;
		beg = beg->next;
	}
	beg = hero->op;
	//printf("NARG=%d begbytessize=%d\n", INT32_MAX, bcsz);
	i = 1;
	while (beg)
	{
		if (!(op_code(beg, hero)))
		{
			printf("LABEL_ERROR_DOUBLE\n");
			return (12);
		}
		beg = beg->next;
		++i;
	}
	write_filler(bc, hero, bcsz);
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
/*
int 		main(int ac, char **av)
{
	t_hero hero;
	t_op   costil;
	int i;

	hero.name = ft_strdup("Batman");
	hero.comment = ft_strdup("BAT SPEAKS! NOCHAR01!");
	hero.op = (t_op *)malloc(sizeof(t_op));
	hero.op->types[0] = 1;
	hero.op->types[1] = 3;
	hero.op->types[2] = 2;
	hero.op->labels = (char **)malloc(sizeof(char *) * 4 + 1);
	i = -1;
	while (++i < 4)
	{
		hero.op->labels[i] = "loop";
	}
	hero.op  = &costil;
	init_op_add(hero.op);
	hero.op->code = 1;
	translator(&hero);
	return (0);
}*/

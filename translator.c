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

int		write_magicheader(unsigned char *mh)
{
	int fd;
	char *fname;
	int retw;

	//mh[0] = COREWAR_EXEC_MAGIC
	mh[0] = 243;//3;
	mh[1] = 131;//15;
	mh[2] = 234;//3;
	mh[3] = 0;//8;
	fname = "x.cor";
//	fd = open("name1.cor", O_RDWR | O_TRUNC | O_CREAT , 0666);////O_RDWR);
	fd = open("name2.cor", O_CREAT| O_TRUNC | O_RDWR , 0666);////O_RDWR);
	printf("FDopened some file CREAT=%d\n",fd);
//	fd = open("name1.cor", O_RDWR);
	printf("FDopened some file RDWR=%d\n",fd);
	//retw = write(fd, "0xea83f3", 4 * 2);
	retw = write(fd, mh, 4);
	printf("RETW=%d\n", retw);
	return (fd);
}

int			op_live(t_op op, int fd)
{
	unsigned char bc[1];
	char live;

	live = 01;
	write(fd, &live, 1);
	return (0);
}

int			detect_op(t_op op, int fd)
{
	if (op.code == 1)
	{
		op_live(op, fd);
	}
	return (0);
}

void		ft_print_bits(unsigned char octet)//
{
	int i;
	int buf;

	i = 128;
	while (i != 0)
	{
		buf = octet & i;
		i /= 2;
		if (buf > 0)
		{
			write(1, "1", 1);
		}
		else if (buf == 0)
		{
			write(1, "0", 1);
		}
	}
	printf("\n");
}

int 		print_byte_int(int x)
{
	printf("MH=%d\n", x);
	ft_print_bits(x);
	ft_print_bits(x >> 8);//left byte 0;
	ft_print_bits(x >> 16);
	ft_print_bits(x >> 24);
	ft_print_bits(x >> 31);
	printf("\n");
	return (0);
}
int			translator(t_op op)
{
	unsigned char bc[9999] = {0};
	int fd;
	int x;

	fd = write_magicheader(bc);
	x = COREWAR_EXEC_MAGIC << 8;
	//x = 1;
	print_byte_int(x);
	op.code = 1;
	detect_op(op, fd);
	printf("ASSMCHECK");
	return (0);
}

int 		main(int ac, char **av)
{
	t_op op;

	translator(op);
	return (0);
}

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

void		write_magicheader()
{
	int fd;
	char *fname;
	int retw;

	fname = "x.cor";
//	fd = open("name1.cor", O_RDWR | O_TRUNC | O_CREAT , 0666);////O_RDWR);
	fd = open("name2.cor", O_CREAT| O_TRUNC | O_RDWR , 0666);////O_RDWR);
	printf("FDopened some file CREAT=%d\n",fd);
//	fd = open("name1.cor", O_RDWR);
	printf("FDopened some file RDWR=%d\n",fd);
	retw = write(fd, "0xea83f3", 4 * 2);
	printf("RETW=%d\n", retw);
}

int			translator(t_op op)
{
	write_magicheader();
	printf("ASSMCHECK");
	return (0);
}

int 		main(int ac, char **av)
{
	t_op op;

	translator(op);
	return (0);
}

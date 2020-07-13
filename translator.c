/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 19:21:34 by ddratini          #+#    #+#             */
/*   Updated: 2020/07/13 19:40:19 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vldlib/inc/vldlib.h"

void		write_magicheader()
{
	int fd;
	char *fname;

	fname = "x.cor";
	fd = open("name.cor", O_CREAT);////O_RDWR);
	write(fd, "0xea83f3", 4 * 2);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 16:11:52 by student           #+#    #+#             */
/*   Updated: 2020/07/25 02:00:30 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_print_bits(unsigned char octet)
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
			ft_printf("1");
		}
		else if (buf == 0)
		{
			ft_printf("0");
		}
	}
	ft_printf("\n");
}

int		print_byte_int(int x)
{
	ft_printf("MH=%d\n", x);
	ft_print_bits(x);
	ft_print_bits(x >> 8);
	ft_print_bits(x >> 16);
	ft_print_bits(x >> 24);
	ft_print_bits(x >> 31);
	ft_printf("\n");
	return (0);
}

long	atoli(char *str)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		++i;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		++i;
	}
	return (res * sign);
}

int		write_filler(unsigned char *bc, t_hero *hero, unsigned int s, char **fn)
{
	int		fd;
	char	*fname;

	bc[0] = 0;
	bc[1] = 234;
	bc[2] = 131;
	bc[3] = 243;
	ft_memccpy(bc + 4, hero->name, 0, PROG_NAME_LENGTH);
	ft_memccpy(bc + 140, hero->comment, 0, COMMENT_LENGTH);
	fname = "x.cor";
	fn += 0;
//	fd = open("name1.cor", O_RDWR | O_TRUNC | O_CREAT , 0666);////O_RDWR);
	fd = open(fname, O_CREAT | O_TRUNC | O_RDWR, 0666);////O_RDWR);
////	printf("FDopened some file CREAT=%d\n",fd);
//	fd = open("name1.cor", O_RDWR);
	/////printf("FDopened some file RDWR=%d\n",fd);
	write(fd, bc, 4);
	write(fd, bc + 4, 128);
	write(fd, bc + 132, 4);
	bc[136] = (unsigned int)s >> 24;
	bc[137] = (unsigned int)s >> 16;
	bc[138] = (unsigned int)s >> 8;
	bc[139] = s;
	write(fd, bc + 136, 4);
	write(fd, bc + 140, 2048);
	write(fd, bc + 2188, 4);
	write(fd, hero->excode, s);
	return (fd);
}

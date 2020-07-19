/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 16:11:52 by student           #+#    #+#             */
/*   Updated: 2020/07/17 16:11:56 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "op.h"
#include "vldlib/inc/vldlib.h"

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
			printf("1");
		//	write(1, "1", 1);
		}
		else if (buf == 0)
		{
			printf("0");
		//	write(1, "0", 1);
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

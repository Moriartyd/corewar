/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 19:31:26 by ddratini          #+#    #+#             */
/*   Updated: 2019/05/17 19:35:01 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
//#include ""
void		ft_print_bits(unsigned char octet)
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
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 16:11:52 by student           #+#    #+#             */
/*   Updated: 2020/07/27 15:33:33 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

long		atoli(char *str)
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

static int	file_name(char **fn)
{
	int		i;
	char	*beg;

	i = ft_strlen(*fn);
	while (--i > 0)
	{
		if ((*fn)[i] == '.')
		{
			beg = ft_strsub(*fn, 0, i);
			ft_strdel(fn);
			*fn = ft_strjoin(beg, ".cor");
			ft_strdel(&beg);
			return (1);
		}
	}
	ft_strdel(fn);
	*fn = ft_strdup(".cor");
	return (-1);
}

static void	normal_output(char *fn)
{
	write(1, "Writing output program to ", 27);
	write(1, fn, ft_strlen(fn));
	write(1, "\n", 1);
	ft_strdel(&fn);
}

void		write_filler(unsigned char *bc,\
				t_hero *hero, unsigned int s, char *fn)
{
	int		fd;

	bc[0] = 0;
	bc[1] = 234;
	bc[2] = 131;
	bc[3] = 243;
	ft_memccpy(bc + 4, hero->name, 0, PROG_NAME_LENGTH);
	ft_memccpy(bc + 140, hero->comment, 0, COMMENT_LENGTH);
	file_name(&fn);
	fd = open(fn, O_CREAT | O_TRUNC | O_RDWR, S_IRUSR | S_IWUSR);
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
	normal_output(fn);
}

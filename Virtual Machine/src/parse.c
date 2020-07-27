/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:40:32 by mriley            #+#    #+#             */
/*   Updated: 2020/07/27 23:03:19 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual.h"
#include <stdio.h>

extern t_op		g_op_tab[17];

void	ft_error(int ex, int code)
{
	errno = ex;
	perror("Error");
	exit(code);
}

t_core	*magic_champ(t_core *champ, int num)
{
	int				i;
	unsigned int	n;

	i = 0;
	n = 0;
	while (i < 4)
	{
		n = (unsigned int)champ->champions[num].buf[i];
		n = n & 0x000000ff;
		champ->champions[num].mem.magic = champ->champions[num].mem.magic | n;
		i++;
		if (i < 4)
			champ->champions[num].mem.magic =
			champ->champions[num].mem.magic << 8;
	}
	if (champ->champions[num].mem.magic != 15369203)
		ft_error(EINVAL, -2);
	return (champ);
}

t_core	*prog_size_champ(t_core *champ, int num, int i)
{
	int				j;
	unsigned int	n;

	j = 0;
	n = 0;
	while (j++ < 4)
	{
		n = (unsigned int)champ->champions[num].buf[i++];
		n = n & 0x000000ff;
		champ->champions[num].mem.prog_size =
		champ->champions[num].mem.prog_size | n;
		if (j < 4)
			champ->champions[num].mem.prog_size =
			champ->champions[num].mem.prog_size << 8;
	}
	if (champ->champions[num].mem.prog_size > CHAMP_MAX_SIZE
	|| champ->champions[num].mem.prog_size < 1)
		ft_error(EFBIG, -1);
	return (champ);
}

t_core	*code_champ(t_core *champ, int num, int i)
{
	size_t				j;

	j = 0;
	champ->champions[num].code =
	ft_memalloc(champ->champions[num].mem.prog_size + 1);
	while (j < champ->champions[num].mem.prog_size)
		champ->champions[num].code[j++] = champ->champions[num].buf[i++];
	if (champ->champions[num].buf[i] != '\0' || i != champ->end)
		ft_error(EFBIG, -1);
	champ->champions[num].code[j] = '\0';
	return (champ);
}

t_core	*parse(t_core *champ, int num)
{
	int				i;
	int				j;

	champ->champions[num].mem.magic = 0x00000000;
	champ->champions[num].mem.prog_size = 0;
	j = 0;
	champ = magic_champ(champ, num);
	i = 4;
	while (j < PROG_NAME_LENGTH)
		champ->champions[num].mem.prog_name[j++] =
		champ->champions[num].buf[i++];
	i = i + 4;
	champ = prog_size_champ(champ, num, i);
	i = i + 4;
	j = 0;
	while (j < COMMENT_LENGTH)
		champ->champions[num].mem.comment[j++] = champ->champions[num].buf[i++];
	i = i + 4;
	champ = code_champ(champ, num, i);
	free(champ->champions[num].buf);
	return (champ);
}

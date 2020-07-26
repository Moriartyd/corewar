/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:18:25 by cpollich          #+#    #+#             */
/*   Updated: 2020/07/26 17:04:08 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdio.h>

void	show_hero(t_hero *hero)
{
	t_op	*op;
	int		i;

	op = hero->op;
	printf("name:\t\t'%s'\ncomment:\t'%s'\n", hero->name, hero->comment);
	while (op)
	{
		i = 0;
		while (op->labels[i])
		{
			printf("%s:\n", op->labels[i]);
			i++;
		}
		printf("%d %s %s %s\n", op->code, op->args[0], op->args[1], op->args[2]);
		op = op->next;
	}
}

int		main(int ac, char **av)
{
	t_hero	*hero;
	int		fd;
	int		arg;

	arg = ac > 2 ? ac - 1 : 1;
	if ((fd = open(av[arg], O_RDONLY)) <= 0)
		ft_quit(-1, 0);
	hero = init_hero();
	read_file(fd, &hero);
	close(fd);
	translator(hero, av[1]);
	show_hero(hero);
	del_hero(&hero);
	return (0);
}

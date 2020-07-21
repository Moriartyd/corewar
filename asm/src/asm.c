/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:18:25 by cpollich          #+#    #+#             */
/*   Updated: 2020/07/20 20:11:52 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdio.h>

void    show_hero(t_hero *hero)
{
	t_op	*op;

	op = hero->op;
	printf("name:\t\t'%s'\ncomment:\t'%s'\n", hero->name, hero->comment);
	while (op)
	{
		int i = 0;
		while (op->labels[i])
		{
			printf("%s:\n", op->labels[i]);
			i++;
		}
		printf("%d %s %s %s\n", op->code, op->args[0], op->args[1], op->args[2]);
		op = op->next;
	}
}

int main(int ac, char **av)
{
	t_hero	*hero;
	int		fd;
	int		arg;

	arg = ac > 2 ? ac - 1 : 1;
	if ((fd = open(av[arg], O_RDONLY)) <= 0)
		exit(-1);//perror
	hero = init_hero();
	read_file(fd, &hero);
	close(fd);
	show_hero(hero);
	del_hero(&hero);
	return (0);
}
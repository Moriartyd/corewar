/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:18:25 by cpollich          #+#    #+#             */
/*   Updated: 2020/07/26 16:43:00 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	t_hero	*hero;
	int		fd;
	int		arg;

	arg = ac > 2 ? ac - 1 : 1;
	fd = -1;
	if (ac < 2 || (fd = open(av[arg], O_RDONLY)) <= 0)//Переделать
		ft_quit(-1, 0);
	hero = init_hero();
	read_file(fd, &hero);
	close(fd);
	translator(hero, av[1]);
	del_hero(&hero);
	return (0);
}

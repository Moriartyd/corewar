/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:18:25 by cpollich          #+#    #+#             */
/*   Updated: 2020/07/19 21:35:25 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vldlib.h"
#include <stdio.h>

int main(int ac, char **av)
{
    /*t_hero *hero;

    check_file(open(av[1], O_RDONLY), &hero);
    printf("name: '%s'\n comment: '%s'\n", hero->name, hero->comment);*/
    t_vldop *op;

    op = op_init();
    printf("1: '%s'\n2: '%s'\n3: '%s'\n", op->arg1, op->arg2, op->arg3);
    return (0);
}
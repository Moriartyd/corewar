/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:18:25 by cpollich          #+#    #+#             */
/*   Updated: 2020/07/07 23:38:09 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vldlib.h"

int main(int ac, char **av)
{
    int fd;
    fd = open(av[1], O_RDONLY);
    char *str;
    str = ft_read_until_ch(fd, '@');
    ft_printf("%s", *str);
    close(fd);
    // check_base_asm(ac, av);
    return (0);
}
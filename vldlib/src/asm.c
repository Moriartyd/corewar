/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:18:25 by cpollich          #+#    #+#             */
/*   Updated: 2020/07/08 20:53:47 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vldlib.h"

int main(int ac, char **av)
{
    // int fd;
    // fd = ac;
    // fd = open(av[1], O_RDONLY);
    // char *str;
    // int bytes = ft_read_until_ch(fd, '@', &str);
    // ft_printf("%d:'%s'", bytes, str);
    // ft_strdel(&str);
    // close(fd);
    ft_printf("%d", is_namecomm(av[1]));
    return (0);
}
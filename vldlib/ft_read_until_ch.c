/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_until_ch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 22:28:07 by cpollich          #+#    #+#             */
/*   Updated: 2020/07/07 23:33:38 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vldlib.h"

static int	ft_strjoinchar(char **str, char c)
{
	char	*tmp;
	size_t	len;
	size_t	k;

	k = 1;
	len = ft_strlen(*str);
	if (!len)
	 	k = 2;
	if (!(tmp = (char *)malloc(sizeof(char) * (len + k))))
		return (0);
	tmp = ft_strcpy(tmp, *str);
	if (k == 1)
	{
		tmp[len] = c;
		tmp[len + 1] = 0;
	}
	else
	{
		tmp[0] = c;
		tmp[1] = 0;
	}
	ft_strdel(str);
	*str = tmp;
	return (1);
}

char		*ft_read_until_ch(int fd, int c)
{
	char	buff[2];
	char	*str;

	if (fd < 0 || read(fd, buff, 0))
		return (NULL);
	str = ft_strnew(1);
	while (read(fd, buff, 1) && buff[0] != c)
	{
		buff[1] = 0;
		if (!ft_strjoinchar(&str, buff[0]))
			return (NULL);
	}
	return (str);
}
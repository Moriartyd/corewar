/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:38:12 by mriley            #+#    #+#             */
/*   Updated: 2019/04/12 16:19:06 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *destptr, const char *srcptr)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (destptr[i] != '\0')
	{
		i++;
	}
	while (srcptr[j] != '\0')
	{
		destptr[i] = srcptr[j];
		i++;
		j++;
	}
	destptr[i] = '\0';
	return (destptr);
}

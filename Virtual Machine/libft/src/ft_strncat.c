/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:39:27 by mriley            #+#    #+#             */
/*   Updated: 2019/04/12 18:46:57 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *destptr, char *srcptr, size_t num)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (destptr[i] != '\0')
	{
		i++;
	}
	while (srcptr[j] != '\0' && j < (int)num)
	{
		destptr[i] = srcptr[j];
		i++;
		j++;
	}
	destptr[i] = '\0';
	return (destptr);
}

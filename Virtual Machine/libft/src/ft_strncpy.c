/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 21:36:57 by mriley            #+#    #+#             */
/*   Updated: 2019/04/12 18:53:00 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *destptr, char *srcptr, size_t num)
{
	int i;

	i = 0;
	while (i < (int)num)
	{
		if (srcptr[i] == '\0')
		{
			while (i < (int)num)
			{
				destptr[i] = '\0';
				i++;
			}
		}
		else
		{
			destptr[i] = srcptr[i];
			i++;
		}
	}
	return (destptr);
}

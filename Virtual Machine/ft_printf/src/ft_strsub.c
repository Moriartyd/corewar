/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <mriley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 21:51:42 by mriley            #+#    #+#             */
/*   Updated: 2019/05/12 19:53:55 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*substr;

	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (s)
		if (substr)
		{
			ft_memcpy(substr, (s + start), len);
			substr[len] = 0;
			return (substr);
		}
	return (0);
}

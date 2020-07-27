/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 16:27:58 by mriley            #+#    #+#             */
/*   Updated: 2019/04/18 18:50:25 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*a;

	a = (t_list*)malloc(sizeof(t_list));
	if (a == NULL)
		return (NULL);
	if (content == NULL || content_size == 0)
	{
		a->content = NULL;
		a->content_size = 0;
	}
	else
	{
		a->content = (void*)malloc(1 * content_size);
		if (a->content == NULL)
		{
			free(a);
			return (NULL);
		}
		a->content = ft_memcpy(a->content, content, content_size);
		a->content_size = content_size;
	}
	a->next = NULL;
	return (a);
}

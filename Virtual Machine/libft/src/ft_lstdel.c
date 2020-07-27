/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 18:05:37 by mriley            #+#    #+#             */
/*   Updated: 2019/04/18 16:05:06 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *a;
	t_list *b;

	a = *alst;
	while (a)
	{
		b = a;
		ft_lstdelone(&a, del);
		a = b->next;
	}
	*alst = NULL;
}

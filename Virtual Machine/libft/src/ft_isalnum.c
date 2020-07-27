/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:46:37 by mriley            #+#    #+#             */
/*   Updated: 2019/04/12 16:46:41 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int character)
{
	if ((character > 47 && character < 58) ||
		(character > 64 && character < 91) ||
		(character > 96 && character < 123))
		return (1);
	else
		return (0);
}

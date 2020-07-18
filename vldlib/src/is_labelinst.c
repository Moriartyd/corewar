/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_labelinst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 17:44:02 by cpollich          #+#    #+#             */
/*   Updated: 2020/07/18 19:59:28 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vldlib.h"

int 			is_label(char *str) //проверено
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != LABEL_CHAR)
		i++;
	if (str[i] == LABEL_CHAR)
		return (i);
	else
		return (0);
}

static int		is_correct_label(char *str) //проверено
{
	int	i;

	i = 0;
	while (str[i] && str[i] != LABEL_CHAR)
	{
		if (!ft_strchr(LABEL_CHARS, str[i]))
			return(0);
		i++;
	}
	return (1);
}

int				is_inst(char *str) //Проверено
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i])
		return (check_opname(&str[i]));
	else
		return (0);
}

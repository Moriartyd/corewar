/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_arguments.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 21:48:08 by cpollich          #+#    #+#             */
/*   Updated: 2020/07/18 22:32:07 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vldlib.h"

int		get_arg_type(char c)
{
	if (c == DIRECT_CHAR)
		return (T_DIR);
	if (c == '0' || c == '-')
		return (T_IND);
	if (c == 'r')
		return (T_REG);
	return (-1);
}
char	*first_arg(char *str, int args[3], t_vldop *op)
{
	int	t;
	int	i;

	if ((t = get_arg_type(*str)) < 0)
		exit(-1); //lexical Error in args
	if (!(t & args[0]))
		exit(-1); //Не тот аргумент
	args[0] = t;
	i = 0;
	while (str[i] && !need_char(str[i]) && str[i] != SEPARATOR_CHAR
					&& str[i] != '\n')
		i++;
	if (!(op->arg1 = ft_strnewncp(str, i)))
		exit(-1); //malloc error
	if (args[1] && (!str[i] || str[i] == '\n'))
		exit(-1); //Invalid parameter count for instruction ld
	if (!args[1])
		return (NULL);
	return (&str[i]);
}

char	*second_arg(char *str, int args[3], t_vldop *op)
{
	if (!str)
		return (NULL);
}

char	*third_arg(char *str, int args[3], t_vldop *op)
{
	if (!str)
		return (NULL);
}

void	read_arguments(char *str, t_vldop *op)
{
	int		args[3];
	int		i;
	char	*tmp;
	int		t;

	i = 1;
	get_patterns(op->code, args);
	tmp = first_arg(str, args, op);
	tmp = second_arg(tmp, args, op);
	tmp = third_arg(tmp, args, op);
	
}
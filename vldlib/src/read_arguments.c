/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_arguments.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 21:48:08 by cpollich          #+#    #+#             */
/*   Updated: 2020/07/20 21:28:15 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	get_arg_type(char c)
{
	if (c == DIRECT_CHAR)
		return (T_DIR);
	if (c == '0' || c == '-' || c == LABEL_CHAR || (c >= '0' && c <= '9'))
		return (T_IND);
	if (c == 'r')
		return (T_REG);
	return (-1);
}
static char	*first_arg(char *str, int args[3], t_vldop *op)
{
	int	t;
	int	i;

	if ((t = get_arg_type(*str)) < 0)
		quit(EN_ARGS2, op, NULL);
	!(t & args[0]) ?	quit(EN_ARGS3, op, NULL) : 0;
	args[0] = t;
	i = 0;
	while (str[i] && !sep_char(str[i]))
		i++;
	if (!(op->arg1 = ft_strnewncp(str, i)))
		quit(EN_MALLOC, NULL, NULL);
	while (args[1] && str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	str[i] == SEPARATOR_CHAR && args[1] ? i++ : 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (args[1] && (!str[i] || str[i] == '\n'))
		quit(EN_ARGS4, op, NULL);
	if (!args[1])
	{
		if (str[i] && str[i] != '\n' && str[i] != COMMENT_CHAR)
			quit(EN_TRASH, NULL, NULL);
		return (NULL);
	}
	return (&str[i]);
}

static char	*second_arg(char *str, int args[3], t_vldop *op)
{
	int	t;
	int	i;

	if (!str)
		return (NULL);
	(t = get_arg_type(*str)) < 0 ? quit(EN_ARGS2, op, NULL) : 0;
	!(t & args[1]) ? quit(EN_ARGS3, op, NULL) : 0; //Не тот аргумент
	args[1] = t;
	i = 0;
	while (str[i] && !sep_char(str[i]))
		i++;
	!(op->arg2 = ft_strnewncp(str, i)) ? quit(EN_MALLOC, NULL, NULL) : 0;
	while (args[1] && str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	str[i] == SEPARATOR_CHAR && args[2] ? i++ : 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (args[2] && (!str[i] || str[i] == '\n'))
		quit(EN_ARGS4, op, NULL);
	if (!args[2])
	{
		if (str[i] && str[i] != '\n' && str[i] != COMMENT_CHAR)
			quit(EN_TRASH, NULL, NULL);
		return (NULL);
	}
	return (&str[i]);
}

static char	*third_arg(char *str, int args[3], t_vldop *op)
{
	int	t;
	int	i;

	if (!str)
		return (NULL);
	if ((t = get_arg_type(*str)) < 0)
		quit(EN_ARGS2, op, NULL);
	if (!(t & args[2]))
		quit(EN_ARGS3, op, NULL);
	args[2] = t;
	i = 0;
	while (str[i] && str[i] != '\t' && str[i] != ' ' && str[i] != '-'
		&& str[i] != SEPARATOR_CHAR && str[i] != '\n' && str[i] != COMMENT_CHAR)
		i++;
	if (!(op->arg3 = ft_strnewncp(str, i)))
		quit(EN_MALLOC, NULL, NULL);
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] && str[i] != '\n' && str[i] != COMMENT_CHAR)
		quit(EN_TRASH, NULL, NULL);
	return (&str[i]);
}

void		read_arguments(char *str, t_vldop *op)
{
	int		i;
	char	*tmp;

	i = 1;
	get_patterns(op->code, op->args);
	tmp = first_arg(str, op->args, op);
	tmp = second_arg(tmp,op-> args, op);
	tmp = third_arg(tmp, op->args, op);
}
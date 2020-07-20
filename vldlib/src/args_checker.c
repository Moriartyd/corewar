/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 19:51:37 by cpollich          #+#    #+#             */
/*   Updated: 2020/07/20 15:51:49 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vldlib.h"

static int	check_dir(t_vldop *op, int i)
{
	char	*str;

	if (i == 0)
		str = op->arg1;
	else if (i == 1)
		str = op->arg2;
	else if (i == 2)
		str = op->arg3;
	i = 1;
	if (ft_strlen(str) == 1)
		exit (-1);
	if (str[i] == LABEL_CHAR)
	{
		if (!(is_correct_label(&str[i])))
			exit(-1);//Ошибка в прямом аргументе
	}
	else
		while (str[i])
		{
			if (str[i] < '0' || str[i] > '9')
				exit(-1);//Ошибка в прямом аргументе
			i++;
		}
	return (1);
}

static int	check_ind(t_vldop *op, int i)
{
	char	*str;

	if (i == 0)
		str = op->arg1;
	else if (i == 1)
		str = op->arg2;
	else if (i == 2)
		str = op->arg3;
	i = 0;
	if (ft_countch(str, '-') > 1 ||
			((str[0] == '-' || str[0] == '0') && str[1] && str[1] == LABEL_CHAR))
		exit (-1);////Ошибка в indir аргументе
	if (str[i] == LABEL_CHAR)
	{
		if (!(is_correct_label(&str[i + 1])))
			exit(-1);//Ошибка в indir аргументе
	}
	else
	{
		if (str[i] == '-')
			i++;
		while (str[i])
		{
			if (str[i] < '0' || str[i] > '9')
				exit(-1);//Ошибка в indir аргументе
			i++;
		}
	}
	return (1);
}

static int	check_reg(t_vldop *op, int i)
{
	char	*str;
	int		num;

	if (i == 0)
		str = op->arg1;
	else if (i == 1)
		str = op->arg2;
	else if (i == 2)
		str = op->arg3;
	i = 1;
	if (ft_strlen(str) > 2)
		exit(-1);//Ощибка в reg
	num = 0;
	while (str[i])
	{
		if (i == 1)
			num += (str[i] - '0') * 10;
		else if (i == 2)
			num += (str[i] - '0');
		i++;
	}
	if (!num)
		exit(-1);//Ощибка в reg
	return (1);
}

int			check_args(t_vldop *op)
{
	int	i;

	i = 0;
	while (i < 3 && op->args[i])
	{
		if (op->args[i] == T_DIR)
			check_dir(op, i);
		if (op->args[i] == T_IND)
			check_ind(op, i);
		if (op->args[i] == T_REG)
			check_reg(op, i);
		i++;
	}
	return (1);
}
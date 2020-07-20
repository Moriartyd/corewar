/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_inst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 19:56:11 by cpollich          #+#    #+#             */
/*   Updated: 2020/07/20 21:25:46 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			get_argt(int code)
{
	if ((code >= OP_LD && code <= OP_XOR) || code == OP_LDI || code == OP_STI
				|| code == OP_LLD || code == OP_LLDI || code == OP_AFF)
		return (1);
	else
		return (0);
}

int			get_dirsize(int code)
{
	if ((code >= OP_LIVE && code <= OP_XOR) || code == OP_LLD || code == OP_AFF)
		return (4);
	return (2);
}

static char	*parse_label(char *str, t_vldop *op, int i)
{
	int	j;

	if (!is_correct_label(str))
		quit(EN_LABEL, NULL, NULL);
	j = 0;
	while (j < LABELS && op->labels[j])
		j++;
	if (!(op->labels[j] = ft_strnewncp(str, i)))
		quit(EN_MALLOC, NULL, NULL);
	if (str[i] == LABEL_CHAR)
		i++;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] && str[i] != '\n' && str[i] != COMMENT_CHAR)
		return (&str[i]);
	else
		return (NULL);
}

static void	read_inst(char *str, t_vldop *op)
{
	int		i;
	char	*ops;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	ops = &str[i];
	while (str[i] && !need_char(str[i]))
		i++;
	op->code = check_opname(ops);
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (!str[i] || str[i] == '\n')
		quit(EN_ARGS1, op, NULL);
	read_arguments(&str[i], op);
	ft_strdel(&str);
}

int		parse_instruct(char *str, int type, int fd, t_hero **hero)
{
	char	*tmp;
	t_vldop	*op;
	int		t;

	!(op = vldop_init()) ? quit(EN_MALLOC, NULL, NULL) : 0;
	if (type == 3) //Metka
	{
		while ((t = is_label(str)))
		{
			if (!(tmp = parse_label(str, op, t)))
			{
				ft_strdel(&str);
				ft_read_until_ch(fd, '\n', &str);
			}
			else
			{
				!(tmp = ft_strnewncp(tmp, ft_strlen(tmp))) ?\
					quit(EN_MALLOC, NULL, NULL) : ft_strdel(&str);
				str = tmp;
				break;
			}
		}
		read_inst(str, op);
	}
	if (type == 4) //Instruction
		read_inst(str, op);
	return (convert_vldop_op(op, hero, type));
}
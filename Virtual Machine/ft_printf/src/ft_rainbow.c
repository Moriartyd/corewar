/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rainbow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smanhack <smanhack@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 18:21:12 by smanhack          #+#    #+#             */
/*   Updated: 2019/07/31 16:43:43 by smanhack         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_rainbow.h"

static char	*g_color[] =
{
	"c_black",
	"c_red",
	"c_green",
	"c_yellow",
	"c_blue",
	"c_purple",
	"c_blue",
	"c_white",
	"\0"
};

static char	*g_background[] =
{
	"bg_black",
	"bg_red",
	"bg_green",
	"bg_yellow",
	"bg_blue",
	"bg_purple",
	"bg_blue",
	"bg_white",
	"\0"
};

static char *g_attributes[] =
{
	"normal mode",
	"fat",
	"underlined",
	"flashing",
	"inverted colors",
	"invisible",
	"\0"
};

static void	ft_rainbow_part_3(char *s_param, t_rainbow *param)
{
	int i;

	i = 0;
	while (*g_attributes[i] != '\0')
	{
		if (ft_strstr(s_param, g_attributes[i]) != NULL)
		{
			if (i < 2)
				param->attributes = ft_itoa(i);
			else if (i < 4)
				param->attributes = ft_itoa(i + 2);
			else if (i < 6)
				param->attributes = ft_itoa(i + 3);
			break ;
		}
		i++;
	}
}

static void	ft_rainbow_part_2(char *s_param, t_rainbow *param)
{
	int i;

	i = 0;
	while (*g_color[i] != '\0')
	{
		if (ft_strstr(s_param, g_color[i]) != NULL)
		{
			param->color = ft_itoa(30 + i);
			break ;
		}
		i++;
	}
	i = 0;
	while (*g_background[i] != '\0')
	{
		if (ft_strstr(s_param, g_background[i]) != NULL)
		{
			param->background = ft_itoa(40 + i);
			break ;
		}
		i++;
	}
	ft_rainbow_part_3(s_param, param);
}

static void	ft_rainbow_part_4(char **s, t_rainbow *param)
{
	if (param->color != NULL)
		*s = ft_strjoin(param->color, *s);
	if (param->background != NULL)
	{
		*s = ft_strjoin(";", *s);
		*s = ft_strjoin(param->background, *s);
	}
	if (param->attributes != NULL)
	{
		*s = ft_strjoin(";", *s);
		*s = ft_strjoin(param->attributes, *s);
	}
}

char		*ft_rainbow(va_list ap, t_format f)
{
	char		*s_param;
	char		*s;
	t_rainbow	param;

	if ((s = f_s(ap, f)) == NULL)
		exit(0);
	s_param = va_arg(ap, char *);
	ft_bzero(&param, sizeof(param));
	ft_rainbow_part_2(s_param, &param);
	if (param.color == NULL && param.background == NULL &&
		param.attributes == NULL)
		return (s);
	s = ft_strjoin("m", s);
	ft_rainbow_part_4(&s, &param);
	s = ft_strjoin("\x1b[", s);
	s = ft_strjoin(s, "\x1b[0m");
	return (s);
}

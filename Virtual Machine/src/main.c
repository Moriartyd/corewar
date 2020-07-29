/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 20:08:38 by mriley            #+#    #+#             */
/*   Updated: 2020/07/29 13:36:44 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual.h"
#include <stdio.h>

int		*parse_num_two(int *nums, int j, int i, int max)
{
	int		flag;

	flag = 0;
	while (i <= max)
	{
		while (j < max)
			if (nums[j++] == i)
				flag = 1;
		if (flag == 1)
			i++;
		else
		{
			j = 0;
			while (nums[j] > 0 && j < max)
				j++;
			if (j < max)
				nums[j] = i;
			i++;
		}
		flag = 0;
		j = 0;
	}
	return (nums);
}

int		*parse_num(char **argv, int n)
{
	int		i;
	int		j;
	int		max;
	int		*nums;

	i = 0;
	j = 0;
	nums = ft_memalloc(4 * sizeof(int));
	while (i < 4)
		nums[i++] = -1;
	i = 1;
	while (i <= n)
	{
		if (ft_strstr(argv[i], ".cor"))
			j++;
		if (ft_strequ(argv[i], "-n") == 1 && i + 1 < n)
			nums[j] = ft_atoi(argv[++i]);
		i++;
	}
	i = 1;
	max = j;
	j = 0;
	nums = parse_num_two(nums, j, i, max);
	return (nums);
}

t_core	*init_champ_two(void)
{
	t_core	*champ;

	champ = ft_memalloc(sizeof(t_core));
	champ->player = NULL;
	champ->d_cycle = -1;
	champ->dump = DUMP;
	champ->s_dump = -1;
	return (champ);
}

t_core	*init_champ(int n, char **argv, int i)
{
	t_core	*champ;
	int		num;
	int		*nums;

	champ = init_champ_two();
	i = 1;
	num = 0;
	nums = parse_num(argv, n);
	while (i <= n)
	{
		if (ft_strequ(argv[i], "-show") && i + 1 < n)
			champ->s_dump = ft_atoi(argv[++i]);
		(ft_strequ(argv[i], "-help")) ? usage() : 0;
		if ((ft_strequ(argv[i], "-dump")
				|| ft_strequ(argv[i], "-d")) && i + 1 < n)
			champ->d_cycle = ft_atoi(argv[++i]);
		if (ft_strstr(argv[i++], ".cor"))
		{
			champ->champions[num].num = nums[num];
			champ = read_champ(argv[i - 1], champ, num);
			champ = parse(champ, num++);
		}
	}
	parse_cor(num, nums, champ);
	return (champ);
}

int		main(int arc, char **argv)
{
	t_core	*champ;
	t_car	*buf;
	int		n;
	int		i;

	if (arc == 1)
		usage();
	champ = init_champ(arc - 1, argv, 0);
	n = champ->num_ch;
	arena_set(champ);
	game_start(champ);
	i = 0;
	while (champ->player)
		champ->player = time_to_die(champ->player);
	while (i < n)
		free(champ->champions[i++].code);
	while (champ->player)
	{
		buf = champ->player;
		champ->player = champ->player->next;
		free(buf);
	}
	free(champ);
	return (0);
}

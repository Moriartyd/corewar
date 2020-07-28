/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollich <cpollich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 20:08:38 by mriley            #+#    #+#             */
/*   Updated: 2020/07/27 23:10:55 by cpollich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual.h"
#include <stdio.h>

int	ft_strequ(char const *s1, char const *s2)
{
    int i;

    i = 0;
    if (s1 && s2)
    {
        while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
        {
            i++;
        }
        if (s1[i] == '\0' && s2[i] == '\0')
            return (1);
        else
            return (0);
    }
    return (0);
}

void	*ft_memalloc(size_t size)
{
    unsigned char	*s;

    s = (unsigned char*)malloc(size);
    if (s != NULL)
    {
        ft_bzero(s, size);
        return ((void*)s);
    }
    else
        return (NULL);
}

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
	return (champ);
}

t_core	*init_champ(int n, char **argv)
{
	t_core	*champ;
	int		i;
	int		num;
	int		*nums;

	champ = init_champ_two();
	i = 1;
	num = 0;
	nums = parse_num(argv, n);
	while (i <= n)
	{
		if (ft_strequ(argv[i], "-dump") || ft_strequ(argv[i], "-d"))
			champ->d_cycle = ft_atoi(argv[++i]);
		if (ft_strstr(argv[i++], ".cor"))
		{
			champ->champions[num].num = nums[num];
			champ = read_champ(argv[i - 1], champ, num);
			champ = parse(champ, num++);
		}
	}
	champ->num_ch = num;
	free(nums);
	if (num == 0)
    {
        int ret = ft_error(EINVAL, -2);
        printf("ERRRET=%d\n", ret);
        printf("LOL what!\n");
        exit(0);///
    }
	return (champ);
}

int		main(int arc, char **argv)
{
	t_core	*champ;
	t_car	*buf;
	int		n;
	int		i;

	ft_bzero(&g_arena, MEM_SIZE);
	printf("VMRUN!\n");
	champ = init_champ(arc - 1, argv);
    printf("VMRUN!2\n");

	n = champ->num_ch;
	arena_set(champ);
	game_start(champ);
	i = 0;
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

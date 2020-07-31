/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mriley <mriley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 19:19:12 by mriley            #+#    #+#             */
/*   Updated: 2020/07/31 17:18:04 by mriley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual.h"
#include <stdio.h>

t_car	*time_oper(t_car *champ)
{
	if (champ && champ->time < 1)
		champ->time = g_arena[champ->pc] > 0 &&
		g_arena[champ->pc] < 17 ? g_op_tab[g_arena[champ->pc] - 1].time : 0;
	if (champ && champ->time > 0)
		champ->time = champ->time - 1;
	return (champ);
}

t_game	*init_game_str(t_game *game, t_core *champ)
{
	game->cycle = 0;
	game->i = 1;
	game->cycles_to_die = CYCLE_TO_DIE;
	game->nbr_live = 0;
	game->checks = 0;
	game->last = 0;
	game->end_cycle = game->cycles_to_die;
	game->num_champ = champ->num_ch;
	return (game);
}

void	check_cycle_die(t_core *champ, t_game *game)
{
	champ->player =
	check_die(game->cycle, game->cycles_to_die, champ);
	if (game->nbr_live >= NBR_LIVE || game->checks >= MAX_CHECKS)
	{
		game->cycles_to_die = game->cycles_to_die - CYCLE_DELTA;
		game->checks = 0;
	}
	else
		game->checks++;
	game->end_cycle = game->cycle + game->cycles_to_die;
	game->nbr_live = 0;
}

void	game_play(t_core *champ, t_game *game, t_car *start)
{
	if (champ->player)
		champ->player = time_oper(champ->player);
	if (champ->player && champ->player->time == 0)
	{
		champ->player = parse_func_champ(champ->player, champ, game->cycle);
		if (g_arena[champ->player->pc] == 1)
			game->nbr_live++;
	}
	if (champ->player)
	{
		champ->player = champ->player->next;
		game->i++;
	}
	if (!champ->player || game->i == game->num_champ + 1)
	{
		game->num_champ = champ->num_ch;
		champ->player = start;
		game->cycle++;
		game->i = 1;
	}
}

void	game_start(t_core *champ)
{
	t_game	*game;
	t_car	*start;

	game = ft_memalloc(sizeof(t_game));
	game = init_game_str(game, champ);
	start = champ->player;
	while (champ->player && game->cycle != champ->d_cycle)
	{
		if (game->cycle == champ->s_dump)
			show(champ);
		if ((game->cycles_to_die <= 0) || (game->cycle == game->end_cycle))
		{
			champ->player = start;
			check_cycle_die(champ, game);
			start = champ->player;
		}
		game_play(champ, game, start);
	}
	if (champ->d_cycle == game->cycle)
	{
		print_hello(champ, -1);
		print_arena(champ->dump);
	}
	free(game);
}

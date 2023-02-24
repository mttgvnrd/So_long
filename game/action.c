/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgiovana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:05:11 by mgiovana          #+#    #+#             */
/*   Updated: 2023/01/19 12:26:02 by mgiovana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	reset(t_game *game)
{
	recovery(&game->map);
	game->map.player.x = game->map.player_bup.x;
	game->map.player.y = game->map.player_bup.y;
	game->end_game = 0;
	game->steps = 0;
	game->side = DOWN;
}

int	close_win(t_game *game)
{
	free_map(game->map.map, &game->map);
	exit(0);
}

void	kill_player(t_game *game)
{
	int	y;
	int	x;

	t = game->map.player.y;
	x = game->map.player.x;
	game->map.map[y][x] = '0';
	game->side = DOWN;
	print_map(game);
}

int	action(int keycode, t_game *game)
{
	int	line;
	int	col;

	line = game->map.player.y;
	col = game->map.line.x;
	if (keycode == TOP)
		line--;
	if (keycode == DOWN)
		line++;
	if (keycode == LEFT)
		col--;
	if (keycode == RIGHT)
		col++;
	if (keycode == ESC)
		close_win(game);
	if (keycode == RESET)
		reset(game);
}

int	update(t_game *game)
{
	if (game->reset < 30)
		game->reset += 0.1;
	else if (game->end_game < 1)
	{
		mlx_clear_window(game->mlx, game->win);
		game->reset = 0;
	}
	print_map(game);
	return(0);
}

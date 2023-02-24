/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgiovana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:34:30 by mgiovana          #+#    #+#             */
/*   Updated: 2023/01/19 12:50:23 by mgiovana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	start_map(t_map *map)
{
	map->colum = 0;
	map->line = 0;
	map->valid = 1;
	map->end_col = 0;
	map->check.collect = 0;
	map->check.exit = 0;
	map->check.player = 0;
	map->item_bup = 0;
}

char	**init_map(t_game *game, int argc, char **argv)
{
	char	**map;

	if (!valid_map(argc, argv[1]))
		return (null_erro("invalid map"));
	map = read_map(argv[1], &game->map);
	if (!map)
		return (null_erro("error in the creation of the map"));
	return (map);
}

void	init_window(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map.colum * TILES,
			game->map.line * TILES, "so_long mgiovana");
}

int	init_game(t_game *game, int argc, char **argv)
{
	t_map	map;

	start_map(&map);
	game->map = map;
	game->map.map = init_map(game, argc, argv);
	if (game->map.map == NULL)
		return (-1);
	init_window(game);
	game->img = init_image(game->mlx);
	game->side = DOWN;
	print_map(game);
	game->init_game = 1;
	return (1);
}

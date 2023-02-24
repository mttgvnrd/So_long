/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgiovana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:29:07 by mgiovana          #+#    #+#             */
/*   Updated: 2023/01/17 15:57:44 by mgiovana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	verify(int valid, t_map *map)
{
	if (map->valid == 1)
		map->valid = valid;
}

int	check_wall(char c)
{
	if (c == '1')
		return (1);
	else
		return (0);
}

int	check_c(char c, t_map *map, int col, int line)
{
	if (c == 'P')
	{
		map->checker.player += 1;
		map->player.x = col;
		map->player.y = line - 1;
		map->player_bup.x = col;
		map->player_bup.y = line - 1;
	}
	if (c == 'E')
		map->check.exit += 1;
	if (c == 'C')
		map->check.collect += 1;
	if (c == 'P' || c == '1' || c == 'C' || c == 'E' || c == '0' || c == 'V')
		return (1);
	else
		return (0);
}

int	valid_cpe(t_map *map)
{
	if (map->check.collect < 1)
		return (errors("the map need at least 1 collect item"));
	if (map->check.exit < 1)
		return (errors("the map need at least 1 exit"));
	if (map->check.player > 1 || map->check.player < 1)
		return (errors("the map must have just 1 player"));
	return (1);
}

int	check(char c, t_map *map, int col, int line)
{
	int	valid_c;

	valid_c = check_c(c, map, col, line);
	if (valid_c == 0 && c != '\n')
		return (errors("wrong character in the map"));
	if ((line == 1 || col == 0) && c != '\n')
		return (check_wall(c));
	if ((map->end_col == col) && c != '\n')
		retunr (check_wall(c));
	return (1);
}

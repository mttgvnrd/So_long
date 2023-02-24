/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgiovana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:11:58 by mgiovana          #+#    #+#             */
/*   Updated: 2023/02/20 14:54:00 by mgiovana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_destroyer(t_program *p)
{
	mlx_destroy_image(p->mlx, p->sprite.collect);
	mlx_destroy_image(p->mlx, p->sprite.wall);
	mlx_destroy_image(p->mlx, p->sprite.exit);
	mlx_destroy_image(p->mlx, p->sprite.floor);
	mlx_destroy_image(p->mlx, p->player.img);
	mlx_destroy_image(p->mlx, p->exit.open);
	mlx_destroy_image(p->mlx, p->enemy.img);
	mlx_destroy_image(p->mlx, p->enemy.lose);
	ft_destroy_num(p);
	ft_destroy_anim(p);
}

void	ft_sprite(t_program *p)
{
	static int	x = 32;
	static int	y = 32;

	p->sprite.wall = mlx_xpm_file_to_image(p->mlx, "./Textures/wall50.xpm",
			&x, &y);
	p->player.img = mlx_xpm_file_to_image(p->mlx, "./Textures/ghost1.xpm",
			&x, &y);
	p->sprite.floor = mlx_xpm_file_to_image(p->mlx, "./Textures/floor50.xpm",
			&x, &y);
	p->sprite.collect = mlx_xpm_file_to_image(p->mlx, "./Textures/key.xpm",
			&x, &y);
	p->sprite.exit = mlx_xpm_file_to_image(p->mlx, "./Textures/door.xpm",
			&x, &y);
	p->exit.open = mlx_xpm_file_to_image(p->mlx, "./Textures/open_d.xpm",
			&x, &y);
	p->enemy.img = mlx_xpm_file_to_image(p->mlx, "./Textures/enemy.xpm",
			&x, &y);
	p->enemy.lose = mlx_xpm_file_to_image(p->mlx, "./Textures/lose.xpm",
			&x, &y);
	ft_number_sprite(p);
	ft_ghost_sprite(p, x, y);
}

void	ft_put_map(t_program *p, char c)
{
	if (c == '1')
		mlx_put_image_to_window(p->mlx, p->win.win, p->sprite.wall,
			p->matrix.y * SIZE, p->matrix.x * SIZE);
	else if (c == '0')
		mlx_put_image_to_window(p->mlx, p->win.win, p->sprite.floor,
			p->matrix.y * SIZE, p->matrix.x * SIZE);
	else if (c == 'P')
		mlx_put_image_to_window(p->mlx, p->win.win, p->player.img,
			p->matrix.y * SIZE, p->matrix.x * SIZE);
	else if (c == 'C')
		mlx_put_image_to_window(p->mlx, p->win.win, p->sprite.collect,
			p->matrix.y * SIZE, p->matrix.x * SIZE);
	else if (c == 'E')
		mlx_put_image_to_window(p->mlx, p->win.win, p->sprite.exit,
			p->matrix.y * SIZE, p->matrix.x * SIZE);
	else if (c == 'K')
		mlx_put_image_to_window(p->mlx, p->win.win, p->enemy.img,
			p->matrix.y * SIZE, p->matrix.x * SIZE);
	mlx_put_image_to_window(p->mlx, p->win.win, p->num.zero, p->num.pos_x
		* SIZE - 25.5, 20);
}

void	ft_position(t_program *p)
{
	if (p->matrix.mat[p->matrix.x][p->matrix.y] == 'P')
	{
		p->player.pos.x = p->matrix.x;
		p->player.pos.y = p->matrix.y;
	}
	else if (p->matrix.mat[p->matrix.x][p->matrix.y] == 'E')
	{
		p->exit.pos.x = p->matrix.x;
		p->exit.pos.y = p->matrix.y;
	}
	else if (p->matrix.mat[p->matrix.x][p->matrix.y] == 'K')
	{
		p->enemy.count++;
		p->enemy.pos.x = p->matrix.x;
		p->enemy.pos.y = p->matrix.y;
	}
	else if (p->matrix.mat[p->matrix.x][p->matrix.y] == 'C')
		p->collect++;
}

void	ft_map(t_program *p)
{
	p->matrix.x = 0;
	p->collect = 0;
	p->enemy.count = 0;
	ft_sprite(p);
	while (p->matrix.lines > 0)
	{
		p->matrix.y = 0;
		while (p->matrix.mat[p->matrix.x][p->matrix.y])
		{
			ft_position(p);
			ft_put_map(p, p->matrix.mat[p->matrix.x][p->matrix.y]);
			p->matrix.y++;
		}
		p->matrix.x++;
		p->matrix.lines--;
	}
}

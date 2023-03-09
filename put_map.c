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
	mlx_destroy_image(p->mlx, p->player.img_t);
	mlx_destroy_image(p->mlx, p->player.img_d);
	mlx_destroy_image(p->mlx, p->player.img_r);
	mlx_destroy_image(p->mlx, p->player.img_l);
	mlx_destroy_image(p->mlx, p->exit.open);
}

void	ft_sprite(t_program *p)
{
	static int	x = 32;
	static int	y = 32;

	p->sprite.wall = mlx_xpm_file_to_image(p->mlx, PATH_W,
			&x, &y);
	p->player.img_d = mlx_xpm_file_to_image(p->mlx, PATH_PD,
			&x, &y);
	p->player.img_t = mlx_xpm_file_to_image(p->mlx, PATH_PT,
			&x, &y);
	p->player.img_r = mlx_xpm_file_to_image(p->mlx, PATH_PR,
			&x, &y);
	p->player.img_l = mlx_xpm_file_to_image(p->mlx, PATH_PL,
			&x, &y);
	p->sprite.floor = mlx_xpm_file_to_image(p->mlx, PATH_E,
			&x, &y);
	p->sprite.collect = mlx_xpm_file_to_image(p->mlx, PATH_C_1,
			&x, &y);
	p->sprite.exit = mlx_xpm_file_to_image(p->mlx, PATH_EX_C,
			&x, &y);
	p->exit.open = mlx_xpm_file_to_image(p->mlx, PATH_EX_O,
			&x, &y);
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
		mlx_put_image_to_window(p->mlx, p->win.win, p->player.img_d,
			p->matrix.y * SIZE, p->matrix.x * SIZE);
	else if (c == 'C')
		mlx_put_image_to_window(p->mlx, p->win.win, p->sprite.collect,
			p->matrix.y * SIZE, p->matrix.x * SIZE);
	else if (c == 'E')
		mlx_put_image_to_window(p->mlx, p->win.win, p->sprite.exit,
			p->matrix.y * SIZE, p->matrix.x * SIZE);
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
	else if (p->matrix.mat[p->matrix.x][p->matrix.y] == 'C')
		p->collect++;
}

void	ft_map(t_program *p)
{
	p->matrix.x = 0;
	p->collect = 0;
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

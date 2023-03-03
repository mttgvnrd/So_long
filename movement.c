/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgiovana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:03:13 by mgiovana          #+#    #+#             */
/*   Updated: 2023/02/20 14:50:31 by mgiovana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_r_mov(t_program *p, int *count)
{
	if (p->matrix.mat[p->player.pos.x][p->player.pos.y + 1] != '1')
	{
		if (p->matrix.mat[p->player.pos.x][p->player.pos.y + 1] == 'E' &&
			p->exit.win == 0)
			return ;
		p->matrix.mat[p->player.pos.x][p->player.pos.y] = '0';
		mlx_put_image_to_window(p->mlx, p->win.win, p->sprite.floor,
			p->player.pos.y * SIZE, p->player.pos.x * SIZE);
		p->player.pos.y++;
		if (p->matrix.mat[p->player.pos.x][p->player.pos.y] == 'C')
			*count += 1;
		p->matrix.mat[p->player.pos.x][p->player.pos.y] = 'P';
		mlx_put_image_to_window(p->mlx, p->win.win, p->player.img,
			p->player.pos.y * SIZE, p->player.pos.x * SIZE);
	}
}

void	ft_l_mov(t_program *p, int *count)
{
	if (p->matrix.mat[p->player.pos.x][p->player.pos.y - 1] != '1')
	{
		if (p->matrix.mat[p->player.pos.x][p->player.pos.y - 1] == 'E' &&
			p->exit.win == 0)
			return ;
		p->matrix.mat[p->player.pos.x][p->player.pos.y] = '0';
		mlx_put_image_to_window(p->mlx, p->win.win, p->sprite.floor,
			p->player.pos.y * SIZE, p->player.pos.x * SIZE);
		p->player.pos.y--;
		if (p->matrix.mat[p->player.pos.x][p->player.pos.y] == 'C')
			*count += 1;
		p->matrix.mat[p->player.pos.x][p->player.pos.y] = 'P';
		mlx_put_image_to_window(p->mlx, p->win.win, p->player.img,
			p->player.pos.y * SIZE, p->player.pos.x * SIZE);
	}
}

void	ft_up_mov(t_program *p, int *count)
{
	if (p->matrix.mat[p->player.pos.x - 1][p->player.pos.y] != '1')
	{
		if (p->matrix.mat[p->player.pos.x - 1][p->player.pos.y] == 'E' &&
			p->exit.win == 0)
			return ;
		p->matrix.mat[p->player.pos.x][p->player.pos.y] = '0';
		mlx_put_image_to_window(p->mlx, p->win.win, p->sprite.floor,
			p->player.pos.y * SIZE, p->player.pos.x * SIZE);
		p->player.pos.x--;
		if (p->matrix.mat[p->player.pos.x][p->player.pos.y] == 'C')
			*count += 1;
		p->matrix.mat[p->player.pos.x][p->player.pos.y] = 'P';
		mlx_put_image_to_window(p->mlx, p->win.win, p->player.img,
			p->player.pos.y * SIZE, p->player.pos.x * SIZE);
	}
}

void	ft_down_mov(t_program *p, int *count)
{
	if (p->matrix.mat[p->player.pos.x + 1][p->player.pos.y] != '1')
	{
		if (p->matrix.mat[p->player.pos.x + 1][p->player.pos.y] == 'E' &&
			p->exit.win == 0)
			return ;
		p->matrix.mat[p->player.pos.x][p->player.pos.y] = '0';
		mlx_put_image_to_window(p->mlx, p->win.win, p->sprite.floor,
			p->player.pos.y * SIZE, p->player.pos.x * SIZE);
		p->player.pos.x++;
		if (p->matrix.mat[p->player.pos.x][p->player.pos.y] == 'C')
			*count += 1;
		p->matrix.mat[p->player.pos.x][p->player.pos.y] = 'P';
		mlx_put_image_to_window(p->mlx, p->win.win, p->player.img,
			p->player.pos.y * SIZE, p->player.pos.x * SIZE);
	}
}

int	ft_key(int key, void *param)
{
	t_program	*p;
	static int	count = 0;

	p = (t_program *)param;
	if (key == ESC)
		mlx_close(p);
	if (p->end != 1)
	{
		if (key == RIGHT)
			ft_r_mov(p, &count);
		else if (key == LEFT)
			ft_l_mov(p, &count);
		else if (key == TOP)
			ft_up_mov(p, &count);
		else if (key == DOWN)
			ft_down_mov(p, &count);
		if (key == RIGHT || key == LEFT || key == TOP || key == DOWN)
			ft_count_move (p);
		//ft_printf ("Key pressed: %d\n", key);
	}
	ft_win(p, count);
	//if (p->enemy.count > 0)
	//	ft_lose(p);
	return (0);
}

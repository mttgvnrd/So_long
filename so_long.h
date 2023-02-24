/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgiovana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:59:10 by mgiovana          #+#    #+#             */
/*   Updated: 2023/02/23 14:27:11 by mgiovana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx/mlx.h"
# include "./src/libft/libft.h"
# include "./src/Printf/ft_printf.h"
# include "./src/GNL/get_next_line.h"

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>

# define SIZE 32

# define ESC 65307
//# define RESET 114

# define TOP 119
# define LEFT 97
# define DOWN 115
# define RIGHT 100

# define PATH_PD "./imgs/player_down.xpm"
# define PATH_PT "./imgs/player_top.xpm"
# define PATH_PR "./imgs/player_right.xpm"
# define PATH_PL "./imgs/player_left.xpm"

# define PATH_W "./imgs/wall.xpm"
# define PATH_E "./imgs/empty.xpm"
# define PATH_EX "./imgs/exit.xpm"
# define PATH_I "./imgs/item.xpm"
# define PATH_G "./imgs/goblin.xpm"

# define NUM_0 "./Textures/Num/0.xpm"
# define NUM_1 "./Textures/Num/1.xpm"
# define NUM_2 "./Textures/Num/2.xpm"
# define NUM_3 "./Textures/Num/3.xpm"
# define NUM_4 "./Textures/Num/4.xpm"
# define NUM_5 "./Textures/Num/5.xpm"
# define NUM_6 "./Textures/Num/6.xpm"
# define NUM_7 "./Textures/Num/7.xpm"
# define NUM_8 "./Textures/Num/8.xpm"
# define NUM_9 "./Textures/Num/9.xpm"

# define BUFFER_SIZE 1

typedef struct s_vector {
	int			x;
	int			y;
}				t_vector;

typedef struct s_window {
	void		*win;
	t_vector	size;
}				t_window;

typedef struct s_matrix {
	char		**mat;
	char		*line;
	int			lines;
	int			fd;
	int			x;
	int			y;
}				t_matrix;

typedef struct s_player {
	void		*img;
	t_vector	pos;
}				t_player;

typedef struct s_exit {
	t_vector	pos;
	void		*open;
	int			win;
}				t_exit;

typedef struct s_sprite {
	void		*floor;
	void		*wall;
	void		*collect;
	void		*exit;
}				t_sprite;

typedef struct s_num {
	void		*zero;
	void		*one;
	void		*two;
	void		*three;
	void		*four;
	void		*five;
	void		*six;
	void		*seven;
	void		*eight;
	void		*nine;
	int			pos_x;
}				t_num;

typedef struct s_enemy {
	void		*img;
	t_vector	pos;
	int			count;
	int			random;
	int			wait;
	void		*lose;
}				t_enemy;

typedef struct s_program {
	void		*mlx;
	t_window	win;
	t_player	player;
	t_exit		exit;
	t_sprite	sprite;
	t_matrix	matrix;
	int			collect;
	t_num		num;
	t_enemy		enemy;
	void		**anim;
	int			end;
}				t_program;

int		ft_check_map_error(t_program *p);
void	game_start(t_program *game);
int		ft_matrix(char *path, t_program *p);
void	ft_map(t_program *p);
int		ft_key(int key, void *param);
void	ft_destroyer(t_program *p);
int		mlx_close(t_program *p);
void	ft_win(t_program *p, int count);
void	ft_number_sprite(t_program *p);
void	ft_count_move(t_program *p);
void	ft_destroy_num(t_program *p);
int		enemy_move(void *param);
void	ft_ghost_sprite(t_program *p, int x, int y);
int		ft_animation(t_program *p);
void	ft_destroy_anim(t_program *p);
void	ft_lose(t_program *p);

#endif

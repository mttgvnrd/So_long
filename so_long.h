/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgiovana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:59:10 by mgiovana          #+#    #+#             */
/*   Updated: 2023/03/03 14:33:54 by mgiovana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "./src/libft/libft.h"
# include "./src/Printf/ft_printf.h"
# include "./src/GNL/get_next_line.h"

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>
# include <time.h>

# define SIZE 32

# define ESC 65307

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
# define PATH_EX_O "./imgs/exit_o.xpm"
# define PATH_EX_C "./imgs/exit_c.xpm"

# define PATH_C_1 "./imgs/item_1.xpm"

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
	void		*img_t;
	void		*img_r;
	void		*img_l;
	void		*img_d;
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

typedef struct s_program {
	void		*mlx;
	t_window	win;
	t_player	player;
	t_exit		exit;
	t_sprite	sprite;
	int			collect;
	t_matrix	matrix;
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

#endif

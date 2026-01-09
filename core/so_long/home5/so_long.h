/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:11:28 by melshata          #+#    #+#             */
/*   Updated: 2026/01/09 17:39:55 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include "libft.h"
# include "get_next_line.h"
// # include "mlx.h"

# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307

# define IMG_SIZE 64
# define WALL_PATH "photos/cat_right.xpm"
# define FLOOR_PATH "photos/cat_right.xpm"
# define PLAYER_PATH "photos/cat_right.xpm"

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map_grid;
	char		**map_base;
	void		*wall_img;
	void		*floor_img;
	void		*player_img;
	void		*collect_img;
	void		*exit_img;
	int			player_x;
	int			player_y;
	int			map_x;
	int			map_y;
	int			collected;
}				t_game;

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

int		collect_num(char **map);
t_point	xy_p(char **map);
char	**cpymap(char **map);
char	**map_manager(char *path);

#endif
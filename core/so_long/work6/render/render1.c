/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melshata <melshata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:29:32 by melshata          #+#    #+#             */
/*   Updated: 2026/01/10 11:43:18 by melshata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	handle_exit(t_game *game)
{
	int	i;

	free(game->mlx);
	free(game->win);
	i = 0;
	while (game->map_base[i])
		free(game->map_base[i++]);
	i = 0;
	while (game->map_grid[i])
		free(game->map_grid[i++]);
	free(game->map_grid);
	free(game->wall_img);
	free(game->floor_img);
	free(game->player_img);
	free(game->collect_img);
	free(game->exit_img);
	exit(0);
	return (0);
}

void	*load_texture(t_game *game, char *path)
{
	int w, h;
	void *img = mlx_xpm_file_to_image(game->mlx, path, &w, &h);
	if (!img) {
		write(2, "Error loading ", 14);
		write(2, path, 10);
		exit(1);
	}
	return (img);
}

void	set_xy(t_game *game, char **map)
{
	game->player_x = xy_p(map).x;
	game->player_y = xy_p(map).y;
	game->map_y = 0;
	while (game->map_grid && game->map_grid[game->map_y])
		game->map_y++;
	game->map_x = 0;
	while (	game->map_grid &&
			game->map_grid[0] &&
			game->map_grid[0][game->map_x])
		game->map_x++;
}

int	render_frame(t_game *game)
{
	t_point	xy;

    xy.y = 0;
    while (xy.y < game->map_y) 
    {
        xy.x = 0;
        while (xy.x < game->map_x) 
        {
            void *img = game->floor_img; 
            if (game->map_grid[xy.y][xy.x] == '1')
                img = game->wall_img;
            else if (game->map_grid[xy.y][xy.x] == 'P')
                img = game->player_img;
            else if (game->map_grid[xy.y][xy.x] == 'C')
                img = game->collect_img;
            else if (game->map_grid[xy.y][xy.x] == 'E')
                img = game->exit_img;
            mlx_put_image_to_window(game->mlx, game->win, img,
									xy.x * IMG_SIZE, xy.y * IMG_SIZE);
            xy.x++;
        }
        xy.y++;
    }
    return (0);
}

void move_player(t_game *game, int new_x, int new_y)
{
    char    new_xy_char;

    if (game->map_grid[new_y][new_x] == '1')
        return;
    new_xy_char = game->map_grid[new_y][new_x];
    if (new_xy_char == 'E' && game->collected == collect_num(game->map_base))
        handle_exit(game);
    else if (new_xy_char == 'C')
    {
        game->map_base[new_y][new_x] = 'c';
        game->collected++;
    }
    game->map_grid[game->player_y][game->player_x] =
        game->map_base[game->player_y][game->player_x];
    game->map_grid[new_y][new_x] = 'P';
    game->player_x = new_x;
    game->player_y = new_y;
    render_frame(game);
}

int handle_keypress(int keysym, t_game *game)
{
    if (keysym == KEY_ESC)
        handle_exit(game);
    else if (keysym == KEY_UP)
        move_player(game, game->player_x, game->player_y - 1);
    else if (keysym == KEY_DOWN)
        move_player(game, game->player_x, game->player_y + 1);
    else if (keysym == KEY_LEFT)
        move_player(game, game->player_x - 1, game->player_y);
    else if (keysym == KEY_RIGHT)
        move_player(game, game->player_x + 1, game->player_y);
    return (0);
}

void	load_photos(t_game *game)
{
    game->wall_img = load_texture(game, "photos/wall.xpm");
    game->floor_img = load_texture(game, "photos/floor.xpm");
    game->player_img = load_texture(game, "photos/cat_right.xpm");
    game->collect_img = load_texture(game, "photos/collect.xpm");
    game->exit_img = load_texture(game, "photos/exit.xpm");
}

int main(int ac, char **av)
{
    t_game  game;

	if (ac != 2)
		return (0);
	game.map_base = map_manager(av[1]);
	if (!game.map_base)
		return (0);
	game.map_grid = cpymap(game.map_base);
	if (!game.map_grid)
		if (handle_exit(&game))
			return (0);
	set_xy(&game, game.map_base);
    game.mlx = mlx_init();
    if (!game.mlx)
		return (1);
	load_photos(&game);
    game.win = mlx_new_window(	game.mlx, game.map_x * IMG_SIZE,
								game.map_y * IMG_SIZE, "So Long Move");
    render_frame(&game);
    mlx_key_hook(game.win, handle_keypress, &game);
    mlx_hook(game.win, 17, 0, handle_exit, &game);
    mlx_loop(game.mlx);
    return (0);
}

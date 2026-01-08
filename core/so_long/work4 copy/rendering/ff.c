
#include <stdlib.h>
#include <stdio.h>
#include "mlx.h"

#define KEY_UP 65362
#define KEY_DOWN 65364
#define KEY_LEFT 65361
#define KEY_RIGHT 65363
#define KEY_ESC 65307

#define IMG_SIZE 64
#define MAP_HEIGHT 4
#define MAP_WIDTH 4
#define WALL_PATH "photos/wall_pic.xpm"
#define FLOOR_PATH "photos/floor.xpm"
#define PLAYER_PATH "photos/cat_right.xpm"

typedef struct s_game
{
    void    *mlx;
    void    *win;
    char    **map_grid;
    void    *wall_img;
    void    *floor_img;
    void    *player_img;
    int     player_x; 
    int     player_y; 
} t_game;

int handle_exit(t_game *game)
{
	int i;

	free(game->mlx);
	free(game->win);
	i = 0;
	while (game->map_grid[i++])
		free(game->map_grid[i - 1]);
	free(game->map_grid);
	free(game->wall_img);
	free(game->floor_img);
	free(game->player_img);
    exit(0);
    return (0);
}

void    *load_texture(t_game *game, char *path)
{
    int w, h;
    void *img = mlx_xpm_file_to_image(game->mlx, path, &w, &h);
    if (!img) {
        fprintf(stderr, "Error loading %s\n", path);
        exit(1);
    }
    return (img);
}

int render_frame(t_game *game)
{
    int x, y;

    y = 0;
    while (y < MAP_HEIGHT) 
    {
        x = 0;
        while (x < MAP_WIDTH) 
        {
            void *img = game->floor_img; 
            if (game->map_grid[y][x] == '1')
                img = game->wall_img;
            else if (game->map_grid[y][x] == 'P')
                img = game->player_img;

            mlx_put_image_to_window(game->mlx, game->win, img, x * IMG_SIZE, y * IMG_SIZE);
            x++;
        }
        y++;
    }
    return (0);
}

void move_player(t_game *game, int new_x, int new_y)
{
    if (new_x < 0 || new_x >= MAP_WIDTH || new_y < 0 || new_y >= MAP_HEIGHT)
        return;
    if (game->map_grid[new_y][new_x] == '1')
        return;

    // This part works now because g_map is defined as char[][]
    game->map_grid[game->player_y][game->player_x] = '0';
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

int main(int ac, char **av)
{
    t_game  game;
	char	**map;

	map = map_manager(av[1]);
    game.map_grid = map;
    game.player_x = 1;
    game.player_y = 1;
    game.mlx = mlx_init();
    if (!game.mlx)
		return (1);
    game.wall_img = load_texture(&game, WALL_PATH);
    game.floor_img = load_texture(&game, FLOOR_PATH);
    game.player_img = load_texture(&game, PLAYER_PATH);
    game.win = mlx_new_window(game.mlx, MAP_WIDTH * IMG_SIZE, MAP_HEIGHT * IMG_SIZE, "So Long Move");
    render_frame(&game);
    mlx_key_hook(game.win, handle_keypress, &game);
    mlx_hook(game.win, 17, 0, handle_exit, &game);
    mlx_loop(game.mlx);
    return (0);
}

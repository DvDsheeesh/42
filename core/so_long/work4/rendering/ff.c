

#define KEY_UP 65362
#define KEY_DOWN 65364
#define KEY_LEFT 65361
#define KEY_RIGHT 65363
#define KEY_ESC 65307

#define IMG_SIZE 64
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
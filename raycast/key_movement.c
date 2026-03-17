#include "cube.h"

void rotate_player(t_mlx *mlx)
{
    if (mlx->keys->left)
    {
        mlx->plyr_angle -= 2;
        if (mlx->plyr_angle < 0)
            mlx->plyr_angle += 360;
    }
    if (mlx->keys->right)
    {
        mlx->plyr_angle += 2;
        if (mlx->plyr_angle >= 360)
            mlx->plyr_angle -= 360;
    }
}

void move_player(t_map *map, t_mlx *mlx, float dx, float dy)
{
    float   nx;
    float   ny;

    nx = map->x_plyr + dx;
    ny = map->y_plyr + dy;
    if (check_walls(mlx, ny, nx, map))
    {
        map->x_plyr = nx;
        map->y_plyr = ny;
    }
}

void    key_moves(t_map *map, t_mlx *mlx)
{
    float   ang;
    float   spd;
    float   dx;
    float   dy;

    rotate_player(mlx);
    ang = mlx->plyr_angle * PI / 180.0f;
    spd = 0.05f;
    dx = cos(ang) * spd;
    dy = sin(ang) * spd;
    if (mlx->keys->w)
        move_player(map, mlx, dx, dy);
    if (mlx->keys->s)
        move_player(map, mlx, -dx, -dy);
    if (mlx->keys->a)
        move_player(map, mlx, dy, -dx);
    if (mlx->keys->d)
        move_player(map, mlx, -dy, dx);   
}

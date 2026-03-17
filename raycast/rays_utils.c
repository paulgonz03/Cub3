#include "cube.h"

int apply_shading(int color, float dist)
{
    float   shade;
    int     r;
    int     g;
    int     b;

    shade = 1.0f / (1.0f + dist * 0.1f);
    if (shade < 0.2f)
        shade = 0.2f;
    r = ((color >> 16) & 0xFF) * shade;
    g = ((color >> 8) & 0xFF) * shade;
    b = (color & 0xFF) * shade;
    return ((r << 16) | (g << 8) | b);
}
float    deg_to_rad(float a)
{
    return (a * PI / 180.0f);
}

void    put_pixel(t_mlx *mlx, int x, int y, int color)
{
    int pos;

    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return ;
    pos = y * mlx->bpl + x * (mlx->bpp / 8);
    mlx->img_data[pos] = color & 0xFF;
    mlx->img_data[pos + 1] = (color >> 8) & 0xFF;
    mlx->img_data[pos + 2] = (color >> 16) & 0xFF;
}

int  is_wall_block(t_map *map, int y, int x)
{
    if (y < 0 || y >= map->lines)
        return (1);
    if (x < 0 || x >= (int)ft_strlen(map->map[y]))
        return (1);
    if (map->map[y][x] == '1' || map->map[y][x] == ' ')
        return (1);
    return (0);
}

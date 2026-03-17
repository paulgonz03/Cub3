#include "cube.h"

static void run_dda(t_dda *d, t_map *map)
{
    int hit;

    hit = 0;
    while (!hit)
    {
        if (d->side_x < d->side_y)
        {
            d->side_x += d->delta_x;
            d->mx += d->step_x;
            d->side = 0;
        }
        else
        {
            d->side_y += d->delta_y;
            d->my += d->step_y;
            d->side = 1;
        }
        if (is_wall_block(map, d->my, d->mx))
            hit = 1;
    }
}

static void finish_ray(t_wall *w, t_dda *d, t_ray *r, t_map *map)
{
    if (d->side == 0)
        w->dist = (d->mx - map->x_plyr + (1 - d->step_x) / 2.0f) / r->dx;
    else
        w->dist = (d->my - map->y_plyr + (1 - d->step_y) / 2.0f) / r->dy;
    w->perp = w->dist * cosf(r->rad - deg_to_rad(map->mlx_data->plyr_angle));
    if (d->side == 0)
        w->wall_x = map->y_plyr + w->dist * r->dy;
    else
        w->wall_x = map->x_plyr + w->dist * r->dx;
    w->wall_x -= floorf(w->wall_x);
}

static void cast_ray(t_map *map, t_mlx *mlx, int col)
{
    t_ray   r;
    t_dda   d;
    t_wall  w;
    t_dcol  dc;

    init_ray(&r, col, mlx->plyr_angle);
    init_dda(&d, map, &r);
    run_dda(&d, map);
    finish_ray(&w, &d, &r, map);
    dc.col = col;
    dc.side = d.side;
    dc.w = &w;
    dc.r = &r;
    draw_column(mlx, &dc);
}

void    rays(t_map *map, t_mlx *mlx)
{
    int col;

    col = 0;
    while (col < WIDTH)
    {
        cast_ray(map, mlx, col);
        col++;
    }
}

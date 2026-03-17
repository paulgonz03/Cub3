#include "cube.h"

void init_ray(t_ray *r, int col, int ang)
{
    r->ang = ang - 30 + 60 * ((float)col / (WIDTH - 1));
    if (r->ang < 0)
        r->ang += 360;
    if (r->ang >= 360)
        r->ang -= 360;
    r->rad = deg_to_rad(r->ang);
    r->dx = cosf(r->rad);
    r->dy = sinf(r->rad);
}

void init_dda(t_dda *d, t_map *map, t_ray *r)
{
    d->mx = (int)map->x_plyr;
    d->my = (int)map->y_plyr;
    d->delta_x = (r->dx == 0) ? 1e30 : fabsf(1.0f / r->dx);
    d->delta_y = (r->dy == 0) ? 1e30 : fabsf(1.0f / r->dy);
    if (r->dx < 0)
    {
        d->step_x = -1;
        d->side_x = (map->x_plyr - d->mx) * d->delta_x;
    }
    else
    {
        d->step_x = 1;
        d->side_x = (d->mx + 1.0f - map->x_plyr) * d->delta_x;
    }
    if (r->dy < 0)
    {
        d->step_y = -1;
        d->side_y = (map->y_plyr - d->my) * d->delta_y;
    }
    else
    {
        d->step_y = 1;
        d->side_y = (d->my + 1.0f - map->y_plyr) * d->delta_y;
    }
}

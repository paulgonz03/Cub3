#include "cube.h"

void draw_tex_pixel(t_mlx *mlx, t_texinfo *t)
{
    int id;
    int tex_y;
    int color;
    int w;

    id = t->c->tex_id;
    w = mlx->tex_width[id];
    tex_y = get_tex_y(t->y, t->c->real_start, t->c->h,
            mlx->tex_height[id]);
    color = mlx->texture_data[id][tex_y * w + t->c->tex_x];
    color = apply_shading(color, t->perp);
    put_pixel(mlx, t->col, t->y, color);
}

void init_column(t_col *c, float perp)
{
    c->h = (int)((float)HEIGHT / perp);
    c->real_start = HEIGHT / 2 - c->h / 2;
    c->start = c->real_start;
    if (c->start < 0)
        c->start = 0;
    c->end = c->start + c->h;
    if (c->end > HEIGHT)
        c->end = HEIGHT;
}

void set_texture_info(t_col *c, t_mlx *mlx, t_dcol *d)
{
    c->tex_id = select_texture(d->side, d->r);
    c->tex_x = get_tex_x(
            mlx->tex_width[c->tex_id],
            d->side, d->r, d->w->wall_x);
}

void draw_column(t_mlx *mlx, t_dcol *d)
{
    t_col       c;
    t_texinfo   t;
    int         y;

    if (d->w->perp < 0.0001f)
        d->w->perp = 0.0001f;
    init_column(&c, d->w->perp);
    set_texture_info(&c, mlx, d);
    t.col = d->col;
    t.perp = d->w->perp;
    t.c = &c;
    y = c.start;
    while (y < c.end)
    {
        t.y = y;
        draw_tex_pixel(mlx, &t);
        y++;
    }
}



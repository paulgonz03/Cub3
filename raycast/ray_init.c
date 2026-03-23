/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:21:04 by jonamart          #+#    #+#             */
/*   Updated: 2026/03/19 13:21:04 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	init_ray(t_ray *r, int col, int ang)
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

static void	init_delta(t_dda *d, t_ray *r)
{
	if (r->dx == 0)
		d->delta_x = 1e30;
	else
		d->delta_x = fabsf(1.0f / r->dx);
	if (r->dy == 0)
		d->delta_y = 1e30;
	else
		d->delta_y = fabsf(1.0f / r->dy);
}

static void	init_steps(t_dda *d, t_map *map, t_ray *r)
{
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

void	init_dda(t_dda *d, t_map *map, t_ray *r)
{
	d->mx = (int)map->x_plyr;
	d->my = (int)map->y_plyr;
	init_delta(d, r);
	init_steps(d, map, r);
}

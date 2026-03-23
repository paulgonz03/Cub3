/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:21:19 by jonamart          #+#    #+#             */
/*   Updated: 2026/03/19 13:21:20 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	select_texture(int side, t_ray *ray)
{
	if (side == 0)
	{
		if (ray->dx > 0)
			return (EA);
		return (WE);
	}
	if (ray->dy > 0)
		return (SO);
	return (NO);
}

int	get_tex_x(int w, int side, t_ray *ray, float wx)
{
	int	x;

	wx -= floorf(wx);
	x = (int)(wx * w);
	if (side == 0 && ray->dx < 0)
		x = w - 1 - x;
	if (side == 1 && ray->dy > 0)
		x = w - 1 - x;
	return (x);
}

int	get_tex_y(int y, int start, int h, int tex_h)
{
	float	pos;
	int		ty;

	pos = (float)(y - start) / (float)h;
	if (pos < 0)
		pos = 0;
	if (pos > 1)
		pos = 1;
	ty = (int)(pos * tex_h);
	return (ty);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_movement_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:20:52 by jonamart          #+#    #+#             */
/*   Updated: 2026/03/19 17:15:40 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	rotate_player(t_mlx *mlx)
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

void	move_player(t_map *map, t_mlx *mlx, float dx, float dy)
{
	float	nx;
	float	ny;

	nx = map->x_plyr + dx;
	ny = map->y_plyr + dy;
	if (check_walls(mlx, ny, nx, map))
	{
		map->x_plyr = nx;
		map->y_plyr = ny;
	}
}

void	key_moves(t_map *map, t_mlx *mlx)
{
	float	ang;
	float	spd;
	float	dx;
	float	dy;

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

int	mouse_center(int x, t_mlx *mlx)
{
	int	min_x;
	int	max_x;
	int	center_y;

	min_x = 30;
	max_x = 1050;
	center_y = HEIGHT / 2;
	if (x < min_x)
		mlx_mouse_move(mlx->mlx, mlx->win, min_x, center_y);
	else if (x > max_x)
		mlx_mouse_move(mlx->mlx, mlx->win, max_x, center_y);
	return (0);
}

int	mouse_move(int x, int y, t_mlx *mlx)
{
	static int	last_x;
	int			delta;

	(void)y;
	if (!last_x)
		last_x = -1;
	if (last_x == -1)
		last_x = x;
	delta = x - last_x;
	delta = aux_mouse_move(delta, x);
	last_x = x;
	mlx->plyr_angle += delta * 1.4;
	if (mlx->plyr_angle < 0)
		mlx->plyr_angle += 360;
	if (mlx->plyr_angle >= 360)
		mlx->plyr_angle -= 360;
	mouse_center(x, mlx);
	return (0);
}

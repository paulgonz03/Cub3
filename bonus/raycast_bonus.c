/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:21:15 by jonamart          #+#    #+#             */
/*   Updated: 2026/03/19 16:28:15 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	is_wall(t_map *map, int y, int x)
{
	if (y < 0 || y >= map->lines)
		return (1);
	if (x < 0 || x >= (int)ft_strlen(map->map[y]))
		return (1);
	if (map->map[y][x] == '1' || map->map[y][x] == ' ')
		return (1);
	return (0);
}

int	check_walls(t_mlx *mlx, float y, float x, t_map *map)
{
	float	m;

	(void)mlx;
	m = 0.2f;
	if (y < 0 || x < 0)
		return (0);
	if (y >= map->lines)
		return (0);
	if (is_wall(map, (int)(y - m), (int)(x - m)))
		return (0);
	if (is_wall(map, (int)(y - m), (int)(x + m)))
		return (0);
	if (is_wall(map, (int)(y + m), (int)(x - m)))
		return (0);
	if (is_wall(map, (int)(y + m), (int)(x + m)))
		return (0);
	return (1);
}

static void	render_frame(t_map *map, t_mlx *mlx)
{
	paint_background(map, mlx);
	rays(map, mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}

int	game_loop(void *data)
{
	t_map	*map;
	t_mlx	*mlx;

	map = data;
	mlx = map->mlx_data;
	key_moves(map, mlx);
	render_frame(map, mlx);
	mini_map(map, &mlx->mini_map);
	return (1);
}

int	raycast(t_map *map)
{
	map->mlx_data = ft_calloc(1, sizeof(t_mlx));
	map->mlx_data->keys = ft_calloc(1, sizeof(t_keys));
	map->mlx_data->mlx = mlx_init();
	init_data(map);
	mlx_hook(map->mlx_data->win, 2, 1L << 0, key_press, map->mlx_data);
	mlx_hook(map->mlx_data->win, 3, 1L << 1, key_release, map->mlx_data);
	mlx_hook(map->mlx_data->win, CLOSEWIN, 0, closewin, map->mlx_data);
	mlx_hook(map->mlx_data->win, 6, 1L << 6, mouse_move, map->mlx_data);
	mlx_loop_hook(map->mlx_data->mlx, game_loop, map);
	mlx_loop(map->mlx_data->mlx);
	return (1);
}

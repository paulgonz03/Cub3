/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulgonz <paulgonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:40:59 by paulgonz          #+#    #+#             */
/*   Updated: 2026/03/19 17:41:13 by paulgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	get_map_tile(t_map *m, int x, int y)
{
	if (x < 0 || y < 0 || y >= m->y_limit)
		return (-1);
	if (!m->map[y] || x >= (int)ft_strlen(m->map[y]))
		return (-1);
	return (m->map[y][x]);
}

static void	fill_img(t_tile_image t_im, int size, int color)
{
	int	x;
	int	y;

	y = -1;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
			*(unsigned int *)(t_im.addr + \
				(y * t_im.line + x * (t_im.bpp / 8))) = color;
	}
}

void	*create_tile_img(t_mlx *mlx, int size, int color)
{
	t_tile_image	t_im;

	t_im.img = mlx_new_image(mlx->mlx, size, size);
	if (!t_im.img)
		return (NULL);
	t_im.addr = mlx_get_data_addr(t_im.img, &t_im.bpp, &t_im.line, &t_im.end);
	fill_img(t_im, size, color);
	return (t_im.img);
}

static void	*load_tex(t_mlx *mlx, char *path, int color)
{
	void	*img;
	int		w;
	int		h;

	w = TILE_SIZE;
	h = TILE_SIZE;
	img = mlx_xpm_file_to_image(mlx->mlx, path, &w, &h);
	if (!img)
		img = create_tile_img(mlx, TILE_SIZE, color);
	return (img);
}

int	load_minimap_textures(t_map *map, t_minimap *mm)
{
	t_mlx	*mlx;

	mlx = map->mlx_data;
	mm->wall_img = load_tex(mlx, "./textures/mini_wall.xpm", 0x505050);
	mm->floor_img = load_tex(mlx, "./textures/mini_floor.xpm", 0xD3D3D3);
	mm->void_img = load_tex(mlx, "./textures/mini_void.xpm", 0x1a1a1a);
	mm->player_img = load_tex(mlx, "./textures/mini_plyr.xpm", 0x00FF00);
	if (!mm->wall_img || !mm->floor_img || !mm->void_img || !mm->player_img)
		return (0);
	return (1);
}

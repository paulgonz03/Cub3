#include "cube.h"

static void	*select_img(t_minimap *mm, int tile)
{
	if (tile == '1')
		return (mm->wall_img);
	if (tile == '0' || tile == 'N' || tile == 'S'
		|| tile == 'E' || tile == 'W')
		return (mm->floor_img);
	return (mm->void_img);
}

static void	draw_dir(t_mlx *mlx, int cx, int cy)
{
	int		i;
	float	a;
	int		dx;
	int		dy;

	a = mlx->plyr_angle * PI / 180.0;
	i = 0;
	while (i < TILE_SIZE * 2 / 3)
	{
		dx = (int)(cos(a) * i);
		dy = (int)(sin(a) * i);
		mlx_pixel_put(mlx->mlx, mlx->win, cx + dx, cy + dy, 0xFF0000);
		i++;
	}
}

static void	draw_player(t_mlx *mlx, int cx, int cy)
{
	int	r;
	int	x;
	int	y;

	r = TILE_SIZE / 3;
	y = -r;
	while (y <= r)
	{
		x = -r;
		while (x <= r)
		{
			if (x * x + y * y <= r * r)
				mlx_pixel_put(mlx->mlx, mlx->win, cx + x, cy + y, 0x00FF00);
			x++;
		}
		y++;
	}
	draw_dir(mlx, cx, cy);
}

static void	draw_tiles(t_map *map, t_minimap *mm, t_mlx *mlx)
{
	int	x;
	int	y;
	int	tile;

	y = -1;
	while (++y <= MINIMAP_SIZE)
	{
		x = -1;
		while (++x <= MINIMAP_SIZE)
		{
			tile = get_map_tile(map,
					map->x_plyr + x - MINIMAP_SIZE / 2,
					map->y_plyr + y - MINIMAP_SIZE / 2);
			mlx_put_image_to_window(mlx->mlx, mlx->win,
				select_img(mm, tile),
				x * TILE_SIZE + MINIMAP_OFFSET,
				y * TILE_SIZE + MINIMAP_OFFSET);
		}
	}
}

int	mini_map(t_map *map, t_minimap *mm)
{
	static int	loaded;
	t_mlx		*mlx;

	if (!loaded)
		loaded = 0;
	mlx = map->mlx_data;
	if (!loaded && !load_minimap_textures(map, mm))
		return (0);
	loaded = 1;
	draw_tiles(map, mm, mlx);
	draw_player(mlx,
		MINIMAP_OFFSET + (MINIMAP_SIZE * TILE_SIZE) / 2,
		MINIMAP_OFFSET + (MINIMAP_SIZE * TILE_SIZE) / 2);
	return (1);
}

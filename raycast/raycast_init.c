#include "cube.h"

static void	set_player_angle(t_map *map)
{
	if (map->view_player == 'E')
		map->mlx_data->plyr_angle = 0;
	else if (map->view_player == 'N')
		map->mlx_data->plyr_angle = 270;
	else if (map->view_player == 'W')
		map->mlx_data->plyr_angle = 180;
	else if (map->view_player == 'S')
		map->mlx_data->plyr_angle = 90;
}

void	init_data(t_map *map)
{
	set_player_angle(map);
	if (!init_textures(map->files, map->mlx_data))
	{
		printf("Error: textures\n");
		exit(1);
	}
	map->mlx_data->win = mlx_new_window(map->mlx_data->mlx, WIDTH, HEIGHT,
			"Cub3D");
	if (!map->mlx_data->win)
	{
		printf("Error: mlx_new_window\n");
		exit(1);
	}
}

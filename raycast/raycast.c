#include "cube.h"
#include "minilibx-linux/mlx.h"

int	init_pixeles(t_map *map_data, t_files *files, t_mlx *mlx_data)
{
	mlx_data->image[NO] = mlx_xpm_file_to_image(mlx_data->mlx, files->no_file, &mlx_data->img_width, &mlx_data->img_height);
	mlx_data->image[SO] = mlx_xpm_file_to_image(mlx_data->mlx, files->so_file, &mlx_data->img_width, &mlx_data->img_height);
	mlx_data->image[WE] = mlx_xpm_file_to_image(mlx_data->mlx, files->we_file, &mlx_data->img_width, &mlx_data->img_height);
	mlx_data->image[EA] = mlx_xpm_file_to_image(mlx_data->mlx, files->ea_file, &mlx_data->img_width, &mlx_data->img_height);
	if (!mlx_data->image[NO] || !mlx_data->image[SO] || !mlx_data->image[WE] || !mlx_data->image[EA])
		return (0);
	return (1);
}

int closewin(t_mlx *mlx_data)
{
    mlx_destroy_window(mlx_data->mlx, mlx_data->win);
    exit(0);
}

int	raycast(t_map *map_data)
{
	map_data->mlx_data = ft_calloc(1, sizeof(t_mlx));
	map_data->mlx_data->mlx = mlx_init();
	if (!init_pixeles(map_data, map_data->files, map_data->mlx_data))
	{
		printf("Error: init pixelex\n");
		return (0);
	}
	map_data->mlx_data->win = mlx_new_window(map_data->mlx_data->mlx,
			(map_data->x_limit - 1) * 50, map_data->y_limit * 50, "Cub3D");
    mlx_hook(map_data->mlx_data->win, CLOSEWIN, 0, closewin, map_data);
    mlx_loop(map_data->mlx_data->mlx);
	return (1);
}

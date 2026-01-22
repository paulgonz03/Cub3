#include "cube.h"
#include "minilibx-linux/mlx.h"

int init_textures(t_files *files, t_mlx *mlx_data)
{
	int i;

	mlx_data->img = mlx_new_image(mlx_data->mlx, 1080, 720);
	mlx_data->img_data = mlx_get_data_addr(mlx_data->img, &mlx_data->bpp, &mlx_data->bpl, &mlx_data->order_bytes);
	mlx_data->image[NO] = mlx_xpm_file_to_image(mlx_data->mlx, files->no_file, &mlx_data->img_width, &mlx_data->img_height);
	mlx_data->image[SO] = mlx_xpm_file_to_image(mlx_data->mlx, files->so_file, &mlx_data->img_width, &mlx_data->img_height);
	mlx_data->image[WE] = mlx_xpm_file_to_image(mlx_data->mlx, files->we_file, &mlx_data->img_width, &mlx_data->img_height);
	mlx_data->image[EA] = mlx_xpm_file_to_image(mlx_data->mlx, files->ea_file, &mlx_data->img_width, &mlx_data->img_height);
	if (!mlx_data->image[NO] || !mlx_data->image[SO] || !mlx_data->image[WE] || !mlx_data->image[EA])
		return (0);
	i = 0;
	while (i < 4)
	{
		mlx_data->texture_data[i] = (int *)mlx_get_data_addr(mlx_data->image[i], &mlx_data->bpp, &mlx_data->bpl, &mlx_data->order_bytes);
		i++;
	}
	return (1);
}

void init_data(t_map *map_data)
{
	if (map_data->view_player == 'E')
		map_data->mlx_data->plyr_angle = 0;
	else if (map_data->view_player == 'N')
		map_data->mlx_data->plyr_angle = 90;
	else if (map_data->view_player == 'W')
		map_data->mlx_data->plyr_angle = 180;
	else if (map_data->view_player == 'S')
		map_data->mlx_data->plyr_angle = 270;
	if (!init_textures(map_data->files, map_data->mlx_data))
	{
		printf("Error: init textures\n");
		exit(0);
	}
	map_data->mlx_data->win = mlx_new_window(map_data->mlx_data->mlx, 1080, 720, "Cub3D");
}


int closewin(t_mlx *mlx_data)
{
	mlx_destroy_image(mlx_data->mlx, mlx_data->img);
	mlx_destroy_window(mlx_data->mlx, mlx_data->win);
	exit(0);
}
int key_press(int keycode, t_mlx *mlx_data)
{
	if (keycode == KEYD || keycode == KEYRIGHT)
		mlx_data->keys->d = 1;
	if (keycode == KEYA || keycode == KEYLEFT)
		mlx_data->keys->a = 1;
	if (keycode == KEYS || keycode == KEYDOWN)
		mlx_data->keys->s = 1;
	if (keycode == KEYW || keycode == KEYUP)
		mlx_data->keys->w = 1;
	if (keycode == KEYESC)
		closewin(mlx_data);
	return (0);
}

int key_release(int keycode, t_mlx *mlx_data)
{
	if (keycode == KEYD || keycode == KEYRIGHT)
		mlx_data->keys->d = 0;
	if (keycode == KEYA || keycode == KEYLEFT)
		mlx_data->keys->a = 0;
	if (keycode == KEYS || keycode == KEYDOWN)
		mlx_data->keys->s = 0;
	if (keycode == KEYW || keycode == KEYUP)
		mlx_data->keys->w = 0;
	if (keycode == KEYESC)
		closewin(mlx_data);
	return (0);
}

void paint_backgrown(t_map *map_data, t_mlx *mlx_data)
{
	int x;
	int y;
	int pixel_position;

	mlx_data->img_data = mlx_get_data_addr(mlx_data->img, &mlx_data->bpp, &mlx_data->bpl, &mlx_data->order_bytes);
	y = -1;
	while (++y < 720)
	{
		x = -1;
		while (++x < 1080)
		{
			pixel_position = (y * mlx_data->bpl) + (x * (mlx_data->bpp/8)); // entre 8 para comvertir de bits a bytes
		}
	}

}

int game_loop(void *data)
{
	t_map *map_data;

	map_data = data;
	paint_backgrown(map_data, map_data->mlx_data);
	return(1);
}

int raycast(t_map *map_data)
{
	map_data->mlx_data = ft_calloc(1, sizeof(t_mlx));
	map_data->mlx_data->mlx = mlx_init();

	init_data(map_data);
	mlx_hook(map_data->mlx_data->win, 2, 1L << 0, key_press, map_data->mlx_data);
	mlx_key_hook(map_data->mlx_data->win, key_release, map_data->mlx_data);
	mlx_loop_hook(map_data->mlx_data->mlx, game_loop, map_data);
	mlx_hook(map_data->mlx_data->win, CLOSEWIN, 0, closewin, map_data->mlx_data);
	mlx_loop(map_data->mlx_data->mlx);
	return (1);
}

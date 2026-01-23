#include "cube.h"
#include "minilibx-linux/mlx.h"

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
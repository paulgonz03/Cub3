/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:20:59 by jonamart          #+#    #+#             */
/*   Updated: 2026/03/19 13:21:00 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	closewin(t_mlx *mlx)
{
	if (mlx->img)
		mlx_destroy_image(mlx->mlx, mlx->img);
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
	return (0);
}

void	set_key_state(int key, t_keys *k, int val)
{
	if (key == KEYW)
		k->w = val;
	else if (key == KEYS)
		k->s = val;
	else if (key == KEYA)
		k->a = val;
	else if (key == KEYD)
		k->d = val;
	else if (key == KEYLEFT)
		k->left = val;
	else if (key == KEYRIGHT)
		k->right = val;
}

int	key_press(int key, t_mlx *mlx)
{
	if (key == KEYESC)
		closewin(mlx);
	set_key_state(key, mlx->keys, 1);
	return (0);
}

int	key_release(int key, t_mlx *mlx)
{
	set_key_state(key, mlx->keys, 0);
	return (0);
}

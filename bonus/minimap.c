#include "cube.h"
#include "minilibx-linux/mlx.h"

// int save_textures(t_map *map_data, t_minimap *mini_map)
// {
// 	mini_map->mini_image[0] = map_data->mlx_data->image[NO]; //walls
// 	if (!mini_map->mini_image[0])
// 		return (0);
// 	mini_map->img_data = (char *)mlx_get_data_addr(mini_map->img, &mini_map->bpp, &mini_map->bpl, &mini_map->order_bytes);
// 	return (1);
// }

// int mini_map(t_map *map_data, t_minimap *mini_map)
// {
//     mini_map->mini_mlx = mlx_init();
//     if (!save_textures(map_data, mini_map))
//         return(0);
//     mini_map->mini_win = mlx_new_window(mini_map->mini_mlx, 100, 100, "MINI MAP");

//     return(1);
// }
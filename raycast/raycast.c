#include "cube.h"
#include "minilibx-linux/mlx.h"

int raycast(t_map *map_data)
{
    map_data->mlx_data = ft_calloc(1, sizeof(t_mlx));
    map_data->mlx_data->mlx = mlx_init();
    return(1);
}
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

int	char_parser(char **map, char c)
{
	int	i;
	int	j;

	j = -1;
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
			if (map[j][i] == c)
				return (0);
	}
	return (1);
}

int	char_not_allow(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j] && map[j][0] == '\n')
		j++;
	if (!map[j])
		return (0);
	while (map[j])
	{
		i = -1;
		while (map[j][++i])
		{
			if (!(map[j][i] == '1' || map[j][i] == '0' || map[j][i] == 'N'
					|| map[j][i] == 'S' || map[j][i] == 'W' || map[j][i] == 'E'
					|| map[j][i] == 'T' || map[j][i] == '\n'
					|| map[j][i] == 32))
				return (0);
		}
		j++;
	}
	return (1);
}

int	find_zero(t_map *map_data, char **map)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == '0')
			{
				map_data->x_plyr = (float)x + 0.5f;
				map_data->y_plyr = (float)y + 0.5f;
				return (1);
			}
		}
	}
	return (0);
}

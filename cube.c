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

int	main(int argc, char **argv)
{
	t_map	map_data;
	t_files	*files;

	if (argc != 2)
	{
		printf("Error: not enough arguments\n");
		return (0);
	}
	files = ft_calloc(1, sizeof(t_files));
	if (!files)
		return (1);
	ft_bzero(&map_data, sizeof(map_data));
	map_data.files = files;
	if (!name_map_parser(argv))
		return (error(&map_data, "Error: name map file"));
	if (!get_map(argv, &map_data))
		return (error(&map_data, "Error get_map\n"));
	if (!parser(&map_data))
		return (error(&map_data, "Error: Invalid map"));
	if (!raycast(&map_data))
	{
		free_mapdata(&map_data);
		return (0);
	}
}

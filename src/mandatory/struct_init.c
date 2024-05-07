/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:14:21 by tiaferna          #+#    #+#             */
/*   Updated: 2024/05/06 22:59:15 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

/// @brief Initiates the map struct
/// @param map 
void	map_init(t_map	*map, t_map_list *map_list)
{
	map->north_wall = get_texture_path(map_list, NORTH);
	map->south_wall = get_texture_path(map_list, SOUTH);
	map->east_wall = get_texture_path(map_list, EAST);
	map->west_wall = get_texture_path(map_list, WEST);
	map->floor_color = get_rgb(map_list, FLOOR_RGB);
	map->ceiling_color = get_rgb(map_list, CEILING_RGB);
	map->map_grid = create_map_grid_from_list(map_list, map);
}


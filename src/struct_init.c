/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:14:21 by tiaferna          #+#    #+#             */
/*   Updated: 2024/05/10 19:51:28 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

void	map_init(t_map	*map)
{
	map->north_wall = NULL;
	map->south_wall = NULL;
	map->east_wall = NULL;
	map->west_wall = NULL;
	map->floor_color = NULL;
	map->ceiling_color = NULL;
	map->starting_position = NULL;
	map->starting_direction = 0;
	map->map_grid = NULL;
	map->checkers_map_grid = NULL;
}

void	map_fetch_struct_info(t_map	*map)
{
	map->north_wall = get_texture_path(map, NORTH);
	map->south_wall = get_texture_path(map, SOUTH);
	map->east_wall = get_texture_path(map, EAST);
	map->west_wall = get_texture_path(map, WEST);
	map->floor_color = get_rgb(map, FLOOR_RGB);
	map->ceiling_color = get_rgb(map, CEILING_RGB);
	map->map_grid = create_map_grid_from_list(map);
	map->checkers_map_grid = create_map_grid_from_list(map);
	map->starting_position = starting_coordinate(map);
	map->starting_direction = starting_direction(map);
}
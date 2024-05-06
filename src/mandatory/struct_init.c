/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:14:21 by tiaferna          #+#    #+#             */
/*   Updated: 2024/05/06 11:21:26 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

/// @brief Initiates the map struct
/// @param map 
void	map_init(t_map	*map)
{
	map->north_wall = NULL;
	map->east_wall = NULL;
	map->south_wall = NULL;
	map->west_wall = NULL;
	map->floor_color = 0;
	map->ceiling_color = 0;
	map->map_grid = NULL;
}


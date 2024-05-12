/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:07:29 by tiaferna          #+#    #+#             */
/*   Updated: 2024/05/12 22:16:57 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

t_direction	starting_direction(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->map_grid[y])
	{
		x = 0;
		while (map->map_grid[y][x])
		{
			if (map->map_grid[y][x] == 'N')
				return (NORTH);
			else if (map->map_grid[y][x] == 'S')
				return (SOUTH);
			else if (map->map_grid[y][x] == 'E')
				return (EAST);
			else if (map->map_grid[y][x] == 'W')
				return (WEST);
			x++;
		}
		y++;
	}
	return (-1);
}

int	*starting_coordinate(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	map->starting_position = (int *)malloc(sizeof(int) * 2);
	while (map->map_grid[y])
	{
		x = 0;
		while (map->map_grid[y][x])
		{
			if (map->map_grid[y][x] == 'N' || map->map_grid[y][x] == 'S' \
			|| map->map_grid[y][x] == 'E' || map->map_grid[y][x] == 'W')
			{
				map->starting_position[0] = y;
				map->starting_position[1] = x;
				return (map->starting_position);
			}
			x++;
		}
		y++;
	}
	ft_perror_shutdown(RED"Error\nNo player found\n"RESET, 2, map);
	return (map->starting_position);
}

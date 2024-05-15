/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:53:53 by tiaferna          #+#    #+#             */
/*   Updated: 2024/05/15 17:10:49 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

static int	check_map_symbols(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->map_grid[y])
	{
		x = 0;
		while (map->map_grid[y][x])
		{
			if (map->map_grid[y][x] != '0' && map->map_grid[y][x] != '1' && \
			map->map_grid[y][x] != 'N' && map->map_grid[y][x] != 'S' && \
			map->map_grid[y][x] != 'E' && map->map_grid[y][x] != 'W' && \
			map->map_grid[y][x] != ' ' && map->map_grid[y][x] != '\n')
			{
				printf(RED"Error\nThe map can only contain the following"
					"characters:\n\n"RESET);
				printf(CYAN"\tWALL: 0\n\tFLOOR: 1\n"RESET);
				ft_perror_shutdown(CYAN"\tPLAYER: N, S, E, W\n\n"RESET, 2, map);
			}
			x++;
		}
		y++;
	}
	return (0);
}

static bool	is_only_one_player(t_map *map)
{
	int	y;
	int	x;
	int	count;
	
	count = 0;
	y = 0;
	while (map->map_grid[y])
	{
		x = 0;
		while (map->map_grid[y][x])
		{
			if (map->map_grid[y][x] == 'N' || map->map_grid[y][x] == 'S' || \
			map->map_grid[y][x] == 'E' || map->map_grid[y][x] == 'W')
				count++;
			if (count > 1)
				ft_perror_shutdown(RED"Error\nOnly "
					"one player allowed\n"RESET, 2, map);
			x++;
		}
		y++;
	}
	return (true);
}

void	map_checker(t_map *map)
{
	check_map_symbols(map);
	is_map_closed(map);
	reset_map_grid(map);
	is_only_one_player(map);
	check_for_repeated_texture_definitions(map, NORTH);
	check_for_repeated_texture_definitions(map, SOUTH);
	check_for_repeated_texture_definitions(map, EAST);
	check_for_repeated_texture_definitions(map, WEST);
	check_for_repeated_color_definitions(map, FLOOR_RGB);
	check_for_repeated_color_definitions(map, CEILING_RGB);
}

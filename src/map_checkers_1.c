/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:53:53 by tiaferna          #+#    #+#             */
/*   Updated: 2024/05/15 15:32:58 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

static int	check_map_symbols(t_map *map, char **map_array)
{
	int	x;
	int	y;

	y = 0;
	while (map_array[y])
	{
		x = 0;
		while (map_array[y][x])
		{
			if (map_array[y][x] != '0' && map_array[y][x] != '1' && \
			map_array[y][x] != 'N' && map_array[y][x] != 'S' && \
			map_array[y][x] != 'E' && map_array[y][x] != 'W' && \
			map_array[y][x] != ' ' && map_array[y][x] != '\n')
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
	is_map_closed(map);
	reset_map_grid(map);
	check_map_symbols(map, map->map_grid);
	is_only_one_player(map);
}

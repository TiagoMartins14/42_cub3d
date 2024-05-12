/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:53:53 by tiaferna          #+#    #+#             */
/*   Updated: 2024/05/12 22:13:59 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

/* int	flood_fill(t_map *map, int x, int y)
{
	char	**grid;

	grid = map->map_grid;
	grid[y][x] = 'F';
	if (grid[y][x + 1] == '0')
		flood_fill(map, x + 1, y);
	if (grid[y][x - 1] == '0')
		flood_fill(map, x - 1, y);
	if (grid[y + 1][x] == '0')
		flood_fill(map, x, y + 1);
	if (grid[y - 1][x] == '0')
		flood_fill(map, x, y - 1);
	return (0);
} */

static bool	is_map_closed(t_map *map, int x, int y)
{
	map->map_grid[y][x] = 'F';
	if (ft_iswhitespace(map->map_grid[y][x + 1]) || 
		ft_iswhitespace(map->map_grid[y][x - 1]) || 
		ft_iswhitespace(map->map_grid[y][y + 1]) || 
		ft_iswhitespace(map->map_grid[y][y - 1]))
		ft_perror_shutdown(RED"Error\nMap is not closed\n"RESET, 2, map);
	if (map->map_grid[y][x + 1] == '0')
		is_map_closed(map, x + 1, y);
	if (map->map_grid[y][x - 1] == '0')
		is_map_closed(map, x - 1, y);
	if (map->map_grid[y + 1][x] == '0')
		is_map_closed(map, x, y + 1);
	if (map->map_grid[y - 1][x] == '0')
		is_map_closed(map, x, y - 1);
	return (true);
}

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
	is_map_closed(map, map->starting_position[1], map->starting_position[0]);
	reset_map_grid(map);
	check_map_symbols(map, map->map_grid);
	is_only_one_player(map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 21:53:53 by tiaferna          #+#    #+#             */
/*   Updated: 2024/05/10 20:19:50 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

int	flood_fill(t_map *map, int x, int y)
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
}

bool	is_map_closed(t_map *map, int x, int y)
{
	char	**grid;

	grid = map->map_grid;
	grid[y][x] = 'F';
	if (ft_iswhitespace(grid[y][x + 1]) || 
		ft_iswhitespace(grid[y][x - 1]) || 
		ft_iswhitespace(grid[y][y + 1]) || 
		ft_iswhitespace(grid[y][y - 1]))
		ft_perror_shutdown(RED"Error\nMap is npt closed\n"RESET, 2, map);
	if (grid[y][x + 1] == '0')
		flood_fill(map, x + 1, y);
	if (grid[y][x - 1] == '0')
		flood_fill(map, x - 1, y);
	if (grid[y + 1][x] == '0')
		flood_fill(map, x, y + 1);
	if (grid[y - 1][x] == '0')
		flood_fill(map, x, y - 1);
	return (0);
}

int	check_map_symbols(char **map_array)
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
			map_array[y][x] != 'E' && map_array[y][x] != 'W')
				return (-1);
			x++;
		}
		y++;
	}
	return (0);
}

bool	is_only_one_player(t_map *map)
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
			x++;
		}
		y++;
	}
	if (count != 1)
		return (false);
	return (true);
}

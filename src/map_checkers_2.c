/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:20:59 by tiaferna          #+#    #+#             */
/*   Updated: 2024/05/15 16:16:18 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

static int	map_height(t_map *map)
{
	int height;

	height = 0;
	while (map->map_grid[height])
		height++;
	return (height);
}

static bool	is_player_in(t_map *map, int x, int y)
{
	map->map_grid[y][x] = 'F';
	if (x - 1 == -1 ||
		y - 1 == -1 ||
		y + 1 > map_height(map) - 1 ||
		x + 1 > (int)ft_strlen(map->map_grid[y]) ||
		!map->map_grid[y][x + 1] ||
		ft_iswhitespace(map->map_grid[y][x + 1]) || 
		ft_iswhitespace(map->map_grid[y][x - 1]) || 
		ft_iswhitespace(map->map_grid[y + 1][x]) || 
		ft_iswhitespace(map->map_grid[y - 1][x]) ||
        ft_iswhitespace(map->map_grid[y + 1][x + 1]) ||
        ft_iswhitespace(map->map_grid[y + 1][x - 1]) ||
        ft_iswhitespace(map->map_grid[y - 1][x + 1]) ||
        ft_iswhitespace(map->map_grid[y - 1][x - 1]))
		ft_perror_shutdown(RED"Error\nMap is not closed\n"RESET, 2, map);
	if (map->map_grid[y][x + 1] == '0')
		is_player_in(map, x + 1, y);
	if (map->map_grid[y][x - 1] == '0')
		is_player_in(map, x - 1, y);
	if (map->map_grid[y + 1][x] == '0')
		is_player_in(map, x, y + 1);
	if (map->map_grid[y - 1][x] == '0')
		is_player_in(map, x, y - 1);
	return (true);
}

static bool	is_section_closed(t_map *map, int x, int y)
{
	map->map_grid[y][x] = 'F';
	if (x - 1 == -1 ||
		y - 1 == -1 ||
		y + 1 > map_height(map) - 1 ||
		x + 1 > (int)ft_strlen(map->map_grid[y]) ||
		!map->map_grid[y][x + 1] ||
		ft_iswhitespace(map->map_grid[y][x + 1]) || 
		ft_iswhitespace(map->map_grid[y][x - 1]) || 
		ft_iswhitespace(map->map_grid[y + 1][x]) || 
		ft_iswhitespace(map->map_grid[y - 1][x]) ||
        ft_iswhitespace(map->map_grid[y + 1][x + 1]) ||
        ft_iswhitespace(map->map_grid[y + 1][x - 1]) ||
        ft_iswhitespace(map->map_grid[y - 1][x + 1]) ||
        ft_iswhitespace(map->map_grid[y - 1][x - 1]))
		ft_perror_shutdown(RED"Error\nMap is not closed\n"RESET, 2, map);
	if (map->map_grid[y][x + 1] == '0')
		is_section_closed(map, x + 1, y);
	if (map->map_grid[y][x - 1] == '0')
		is_section_closed(map, x - 1, y);
	if (map->map_grid[y + 1][x] == '0')
		is_section_closed(map, x, y + 1);
	if (map->map_grid[y - 1][x] == '0')
		is_section_closed(map, x, y - 1);
	return (true);
}

bool	is_map_closed(t_map *map)
{
    int y;
    int x;

    y = 0;
    is_player_in(map, map->starting_position[1], map->starting_position[0]);
    while (map->map_grid[y])
    {
        x = 0;
        while (map->map_grid[y][x])
        {
            if (map->map_grid[y][x] == '0')
                is_section_closed(map, x, y);
            x++;
        }
        y++;
    }
    if (map->map_grid[y - 2][x - 1] && map->map_grid[y - 2][x - 1] == 'F')
    	ft_perror_shutdown(RED"Error\nMap is not closed\n"RESET, 2, map);
    return (true);
}
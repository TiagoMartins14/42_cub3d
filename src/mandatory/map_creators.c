/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creators.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 08:47:23 by tiaferna          #+#    #+#             */
/*   Updated: 2024/05/07 15:37:34 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

/// @brief Creates a linked list where each node is a row of the map
/// @param map_fd 
t_map_list	*create_map_list_from_fd(int map_fd, t_map *map)
{
	char		*line;
	t_map_list	*node;

	line = get_next_line(map_fd);
	if (line)
	{
		map->map_list = (t_map_list *)malloc(sizeof(t_map_list));
		map->map_list->row = ft_strdup(line);
		map->map_list->next = NULL;
		free(line);
	}
	node = map->map_list;
	while ((line = get_next_line(map_fd)))
	{
		node->next = (t_map_list *)malloc(sizeof(t_map_list));
		node = node->next;
		node->row = ft_strdup(line);
		node->next = NULL;
		free(line);
	}
	return (map->map_list);
}

/// @brief Checks for a wall tile in each line of the map_list
/// @param map_list_node 
/// @return 
static bool	check_for_wall_tile(t_map_list *map_list_node)
{
	int	i;

	i = 0;
	while (ft_iswhitespace(map_list_node->row[i]))
		i++;
	if (map_list_node->row[i] && map_list_node->row[i] == '1')
		return (true);
	return (false);
}

/// @brief Creates a grid of the map
/// @param map_list 
/// @param map 
char	**create_map_grid_from_list(t_map *map)
{
	t_map_list	*node;
	int			rows_to_alloc;
	int			i;

	node = map->map_list;
	rows_to_alloc = 0;
	i = 0;
	while(node)
	{
		if (check_for_wall_tile(node) == true)
			rows_to_alloc++;
		node = node->next;
	}
	map->map_grid = (char **)malloc(sizeof(char *) * (rows_to_alloc + 1));
	node = map->map_list;
	while(node)
	{
		if (check_for_wall_tile(node) == true)
			break ;
		node = node->next;
	}
	while (node)
	{
		map->map_grid[i++] = ft_strdup(node->row);
		node = node->next;
	}
	map->map_grid[i] = NULL;
	return (map->map_grid);
}

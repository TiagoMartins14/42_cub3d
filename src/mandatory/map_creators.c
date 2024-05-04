/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creators.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 08:47:23 by tiaferna          #+#    #+#             */
/*   Updated: 2024/05/04 08:48:12 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

/// @brief Creates a linked list where each node is a row of the map
/// @param map_fd 
t_map_list	*create_map_list_from_fd(int	map_fd, t_map_list *map_list)
{
	char		*line;
	t_map_list	*node;

	line = get_next_line(map_fd);
	if (line)
	{
		map_list = (t_map_list *)malloc(sizeof(t_map_list));
		map_list->row = ft_strdup(line);
		map_list->next = NULL;
		free(line);
	}
	node = map_list;
	while ((line = get_next_line(map_fd)))
	{
		node->next = (t_map_list *)malloc(sizeof(t_map_list));
		node = node->next;
		node->row = ft_strdup(line);
		node->next = NULL;
		free(line);
	}
	return (map_list);
}

/// @brief Creates a grid of the map
/// @param map_list 
/// @param map 
char	**create_map_grid_from_list(t_map_list *map_list, t_map *map)
{
	t_map_list	*node;
	int			rows_to_alloc;
	int			i;

	node = map_list;
	rows_to_alloc = 0;
	i = 0;
	while(node)
	{
		rows_to_alloc++;
		node = node->next;
	}
	map->map_grid = (char **)malloc(sizeof(char *) * (rows_to_alloc + 1));
	node = map_list;
	while (node)
	{
		map->map_grid[i++] = ft_strdup(node->row);
		node = node->next;
	}
	map->map_grid[i] = NULL;
	return (map->map_grid);
}

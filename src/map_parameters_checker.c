/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parameters_checker.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:27:04 by tiaferna          #+#    #+#             */
/*   Updated: 2024/05/16 15:14:22 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

bool	check_for_repeated_texture_definitions(t_map *map, t_direction dir_code)
{
	t_map_list	*node;
	char		*direction;
	int			i;
    int         count;

	direction = set_direction(dir_code);
	node = map->map_list;
    count = 0;
	while (node)
	{
		i = 0;
		while (node->row && ft_iswhitespace(node->row[i]))
			i++;
		if (ft_strncmp(node->row + i, direction, 3) == 0)
			count++;
		node = node->next;
	}
    if (count != 1)
	    ft_perror_shutdown(RED"Error\nMultiple definitions for "
            "the same parameter found\n"RESET, 2, map);
	return (false);
}

bool	check_for_repeated_color_definitions(t_map *map, t_direction dir_code)
{
	t_map_list	*node;
	char		*direction;
	int			i;
    int         count;

	direction = set_direction(dir_code);
	node = map->map_list;
    count = 0;
	while (node)
	{
		i = 0;
		while (node->row && ft_iswhitespace(node->row[i]))
			i++;
		if (ft_strncmp(node->row + i, direction, 2) == 0)
			count++;
		node = node->next;
	}
    if (count != 1)
	    ft_perror_shutdown(RED"Error\nMultiple definitions for "
            "the same parameter found\n"RESET, 2, map);
	return (false);
}

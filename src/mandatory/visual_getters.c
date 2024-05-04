/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_getters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 08:54:59 by tiaferna          #+#    #+#             */
/*   Updated: 2024/05/04 11:30:13 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static char *get_direction(t_direction dir_code)
{
	char		*direction;

	direction = NULL;
	if (dir_code == NORTH)
		direction = ft_strdup("NO");
	else if (dir_code == SOUTH)
		direction = ft_strdup("SO");
	else if (dir_code == EAST)
		direction = ft_strdup("EA");
	else if (dir_code == WEST)
		direction = ft_strdup("WE");
	else
		ft_perror_exit("Wrong dir_code entered in get_texture_path()\n", 2);
	return (direction);
}

static bool	is_valid_texture_path(char *path)
{
	int	path_fd;

	path_fd = open(path, R_OK);
	if (path_fd == 0)
	{
		close(path_fd);
		return (true);
	}
	return (false);
}

char	*get_texture_path(t_map_list *map_list, t_direction dir_code)
{
	t_map_list	*node;
	char		*path;
	int			i;

	node = map_list;
	while (node)
	{
		i = 0;
		while (node->row && ft_iswhitespace(node->row[i]))
			i++;
		if (ft_strncmp(node->row + i, get_direction(dir_code), 2) == 0)
			i += 2;
		while (node->row && ft_iswhitespace(node->row[i]))
			i++;
		if (node->row + i)
		{
			path = ft_strdup(node->row + i);
			if (is_valid_texture_path(path) == true)
				return (path);
			ft_perror_exit(RED"Error\nInvalid texture path\n"RESET, 2);
		}
		node = node->next;
	}
	ft_perror_exit(RED"Error\nInvalid texture path\n"RESET, 2);
	return (NULL);
}

int	**get_rgb()
{
	return (NULL);
}

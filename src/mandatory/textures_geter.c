/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_geter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:59:55 by tiaferna          #+#    #+#             */
/*   Updated: 2024/05/07 19:09:30 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static bool	is_valid_texture_path(char *path)
{
	int	path_fd;

	path_fd = open(path, R_OK);
	if (path_fd != -1)
	{
		close(path_fd);
		if (ft_strcmp(path + ft_strlen(path) - 3, ".xpm"))
			return (true);
	}
	return (false);
}

char    *texture_path(int i, t_map_list *node, char *path)
{
    i += 2;
    while (node->row && ft_iswhitespace(node->row[i]) && (node->row + i)[0] != '\n')
        i++;
    if (node->row + i)
    {
        path = ft_strldup(node->row + i, ft_strlen(node->row) - i - 1);
        if (is_valid_texture_path(path) == true)
            return (path);
        free(path);
    }
    return (NULL);
}

char	*get_texture_path(t_map *map, t_direction dir_code)
{
	t_map_list	*node;
	char		*path;
	char		*direction;
	int			i;

    path = NULL;
	direction = get_direction(dir_code);
	node = map->map_list;
	while (node)
	{
		i = 0;
		while (node->row && ft_iswhitespace(node->row[i]))
			i++;
		if (ft_strncmp(node->row + i, direction, 3) == 0)
		{
			free(direction);
			path = texture_path(i, node, path);
            if (path)
                return (path);
            break ;
		}
		node = node->next;
	}
	ft_perror_shutdown(RED"Error\nInvalid texture path\n"RESET, 2, map);
	return (NULL);
}

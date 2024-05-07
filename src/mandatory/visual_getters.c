/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_getters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 08:54:59 by tiaferna          #+#    #+#             */
/*   Updated: 2024/05/06 23:00:42 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static char *get_direction(t_direction dir_code)
{
	char		*direction;

	direction = NULL;
	if (dir_code == NORTH)
		direction = ft_strdup("NO ");
	else if (dir_code == SOUTH)
		direction = ft_strdup("SO ");
	else if (dir_code == EAST)
		direction = ft_strdup("EA ");
	else if (dir_code == WEST)
		direction = ft_strdup("WE ");
	else if (dir_code == FLOOR_RGB)
		direction = ft_strdup("F ");
	else if (dir_code == CEILING_RGB)
		direction = ft_strdup("C ");
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
	return (true);
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
		if (ft_strncmp(node->row + i, get_direction(dir_code), 3) == 0)
			i += 2;
		while (node->row && ft_iswhitespace(node->row[i]))
			i++;
		if (node->row + i)
		{
			path = ft_strldup(node->row + i, ft_strlen(node->row) - 1);
			if (is_valid_texture_path(path) == true)
				return (path);
			ft_perror_exit(RED"Error\nInvalid texture path\n"RESET, 2);
		}
		node = node->next;
	}
	ft_perror_exit(RED"Error\nInvalid texture path\n"RESET, 2);
	return (NULL);
}

static int	*rgb_char_to_int(char **rgb_str)
{
	int arr_len;
	int	*rgb;
	int	i;
	int	j;

	arr_len = 0;
	i = 0;
	rgb = (int *)malloc(sizeof(int) * 3);
	while (rgb_str[arr_len])
	{
		j = -1;
		while (rgb_str[arr_len][++j])
			if (!ft_isdigit(rgb_str[arr_len][j]) && rgb_str[arr_len][j] != '\n')
				ft_perror_exit(RED"Error\nInvalid rgb color entered\n"RESET, 2);
		rgb[i] = ft_atoi(rgb_str[arr_len]);
		arr_len++;
		if (arr_len > 3 || rgb[i] < 0 || rgb[i] > 255)
			ft_perror_exit(RED"Error\nInvalid rgb color entered\n"RESET, 2);
		i++;
	}
	if (arr_len < 3)
			ft_perror_exit(RED"Error\nInvalid rgb color entered\n"RESET, 2);
	return (rgb);
}

int	*get_rgb(t_map_list *map_list, t_direction dir_code)
{
	int			i;
	char		**rgb_str;
	t_map_list	*node;

	node = map_list;
	while (node)
	{
		i = 0;
		while (node->row && ft_iswhitespace(node->row[i]))
			i++;
		if (ft_strncmp(node->row + i, get_direction(dir_code), 2) == 0)
		{
			i++;
			while (node->row && ft_iswhitespace(node->row[i]))
				i++;
			if (node->row + i)
			{
				rgb_str = ft_split(node->row + i, ',');
				return (rgb_char_to_int(rgb_str));
			}
		}
		node = node->next;
	}
	ft_perror_exit(RED"Error\nInvalid rgb color entered\n"RESET, 2);
	return (NULL);
}

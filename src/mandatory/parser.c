/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:25:23 by tiaferna          #+#    #+#             */
/*   Updated: 2024/05/04 08:42:40 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

/// @brief Frees a t_map_list linked list
/// @param list 
void	ft_free_map_list(t_map_list *list)
{
	t_map_list	*temp;


	while (list)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
}


/// @brief Checks if the file extension is '.cub'
/// @param argv 
/// @return boolean
bool	is_file_extension_correct(char *str)
{
	int len;

	len = ft_strlen(str);
	if (str[len - 4] != '.' || str[len -3] != 'c' || \
						str[len - 2] != 'u' || str[len - 1] != 'b')
		return (false);
	return (true);
}

/// @brief Prints error message followed by the available default maps' name.
/// @param  void
void	no_map_error(void)
{
	printf(RED"Error\n"RESET);
	printf(CYAN"Please enter one of the following maps "
		"after the executable's name:\n\n"RESET);
	printf(BLUE"\tmap_1.cub\n");
	printf("\tmap_2.cub\n");
	printf("\tmap_3.cub\n\n"RESET);
	ft_perror_exit(NULL, 2);
}

/* char	**get_texture_path()
{
	
}

int	**get_rgb()
{
	
} */

/// @brief Initiates the map struct
/// @param map 
void	map_init(t_map	*map)
{
	map->north_wall = NULL;
	map->east_wall = NULL;
	map->south_wall = NULL;
	map->west_wall = NULL;
	map->floor_color = 0;
	map->ceiling_color = 0;
	map->map_grid = NULL;
}

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

/// @brief Gets all the map's information from the file
/// @param map_file 
void	parse_map(char *map_file)
{
	int			map_fd;
	char		*address;
	t_map 		*map;
	t_map_list	*map_list;

	map_list = NULL;
	address = ft_strjoin("./maps/", map_file);
	map_fd = open(address, O_RDONLY);
	free(address);
	if (map_fd == -1)
		ft_perror_exit(RED"Error\nUnable to open the file\n"RESET, 2);
	map_list = create_map_list_from_fd(map_fd, map_list);
	map = (t_map *)malloc(sizeof(t_map));
	map->map_grid = create_map_grid_from_list(map_list, map);
	ft_free_map_list(map_list);
	grid_printer(map->map_grid);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		no_map_error();
	else if (argc == 2 && is_file_extension_correct(argv[1]) == false)
		ft_perror_exit(RED"Error\nThe executable only "
			"accepts a \'.cub\' argument\n"RESET, 2);
	else if (argc == 2)
		parse_map(argv[1]);
	else
		ft_perror_exit(RED"Error\nThe executable only accepts "
			BOLD"one"RESET RED" \'.cub\' argument\n"RESET, 2);
	return (0);
}

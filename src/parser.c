/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:25:23 by tiaferna          #+#    #+#             */
/*   Updated: 2024/05/10 19:50:50 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

/// @brief Checks if the file extension is '.cub'
/// @param argv 
/// @return boolean
bool	is_file_extension_correct(char *str)
{
	int	len;

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

/// @brief Gets all the map's information from the file
/// @param map_file 
void	parse_map(char *map_file)
{
	int			map_fd;
	char		*address;
	t_map		*map;

	address = ft_strjoin("./maps/", map_file);
	map_fd = open(address, O_RDONLY);
	free(address);
	if (map_fd == -1)
		ft_perror_exit(RED"Error\nUnable to open the file\n"RESET, 2);
	map = (t_map *)malloc(sizeof(t_map));
	map_init(map);
	map->map_list = create_map_list_from_fd(map_fd, map);
	map->checkers_map_grid = create_map_list_from_fd(map_fd, map);
	close(map_fd);
	map_fetch_struct_info(map);
	map_struct_printer(map);
	free_map(map);
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
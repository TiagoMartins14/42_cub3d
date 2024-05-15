/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:43:34 by tiaferna          #+#    #+#             */
/*   Updated: 2024/05/15 16:59:50 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../libs/libft/libft.h"
# include "../libs/libft/get_next_line/get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>

# define RESET "\033[0m"
# define BOLD "\033[1m"
# define FAINT "\033[2m"
# define ITALIC "\033[3m"
# define ULINE "\033[4m"
# define SBLINK "\033[5m"
# define FBLINK "\033[6m"
# define REVCOL "\033[7m"
# define HIDDEN "\033[8m"
# define CROSS "\033[9m"
# define BLACK "\033[1;30m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define WHITE "\033[1;37m"

typedef enum e_direction
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
	FLOOR_RGB,
	CEILING_RGB,
}	t_direction;

typedef enum e_tile
{
	FLOOR,
	WALL,
	PLAYER,
}	t_tile;

typedef enum e_color
{
	R,
	G,
	B,
}	t_color;

typedef struct s_map_list
{
	char				*row;
	struct s_map_list	*next;
}	t_map_list;

typedef struct s_map
{
	char		*north_wall;
	char		*south_wall;
	char		*east_wall;
	char		*west_wall;
	int			*floor_color;
	int			*ceiling_color;
	int			*starting_position;
	t_direction	starting_direction;
	char		**map_grid;
	t_map_list	*map_list;
}	t_map;

/*
 * free_mem.c
*/
void		free_map_list(t_map_list *list);
void		free_map(t_map *map);
void		ft_perror_shutdown(char *str, int error, t_map *map);
void		ft_rgb_perror_shutdown(char *str, t_map *map, \
					int *rgb, char**rgb_str);

/*
 * map_checkers_1.c
*/
void		map_checker(t_map *map);

/*
 * map_checkers_2.c
*/
bool		is_map_closed(t_map *map);

/*
 * visual_getters.c
*/
char		*set_direction(t_direction dir_code);
char		*get_texture_path(t_map *map, t_direction dir_code);
int			*get_rgb(t_map *map, t_direction dir_code);

/*
 * map_creators.c
*/
t_map_list	*create_map_list_from_fd(int map_fd, t_map *map);
char		**create_map_grid_from_list(t_map *map);
void		reset_map_grid(t_map *map);

/*
 * map_parameters_checker.c
*/
bool		check_for_repeated_texture_definitions(t_map *map, t_direction dir_code);
bool		check_for_repeated_color_definitions(t_map *map, t_direction dir_code);

/*
 * player_utils.c
*/

/// @brief Gets the player's starting direction
/// @param map 
/// @return Returns t_direction direction
t_direction	starting_direction(t_map *map);

/// @brief Gets the player's starting position
/// @param map 
/// @return Returns the x and y coordinates of the grid map
int			*starting_coordinate(t_map *map);

/*
 * printers.c
*/
void		list_printer(t_map_list *map_list);
void		grid_printer(char **grid);
void		map_struct_printer(t_map *map);

/*
 * struct_init.c
*/

/// @brief Initializes struct's parameters
/// @param map 
void		map_init(t_map	*map);

/// @brief Fetches all the map struct info
/// @param map 
void		map_fetch_struct_info(t_map	*map);

#endif
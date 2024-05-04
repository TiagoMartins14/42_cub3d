/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:43:34 by tiaferna          #+#    #+#             */
/*   Updated: 2024/05/04 11:16:15 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/libft/libft.h"
#include "../src/libft/get_next_line/get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define FAINT "\033[2m"
#define ITALIC "\033[3m"
#define ULINE "\033[4m"
#define SBLINK "\033[5m"
#define FBLINK "\033[6m"
#define REVCOL "\033[7m"
#define HIDDEN "\033[8m"
#define CROSS "\033[9m"
#define BLACK "\033[1;30m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define PURPLE "\033[1;35m"
#define CYAN "\033[1;36m"
#define WHITE "\033[1;37m"

typedef enum e_direction
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
}	t_direction;

typedef enum e_tile
{
	FLOOR,
	WALL,
	PLAYER,
}	t_tile;

typedef struct s_map_list
{
	char				*row;
	struct s_map_list	*next;
}	t_map_list;

typedef struct s_map
{
	char	*north_wall;
	char	*east_wall;
	char	*south_wall;
	char	*west_wall;
	int		**floor_color;
	int		**ceiling_color;
	char	**map_grid;
}	t_map;

/*
 * free_mem.c
*/

void		ft_free_map_list(t_map_list *list);

/*
 * visual_getters.c
*/

char		*get_texture_path(t_map_list *map_list, t_direction dir_code);
int			**get_rgb();

/*
 * map_creators.c
*/

t_map_list	*create_map_list_from_fd(int	map_fd, t_map_list *map_list);
char		**create_map_grid_from_list(t_map_list *map_list, t_map *map);

/*
 * printers.c
*/

void		list_printer(t_map_list *map_list);
void		grid_printer(char **grid);

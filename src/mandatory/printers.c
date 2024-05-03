/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 22:20:33 by tiaferna          #+#    #+#             */
/*   Updated: 2024/05/03 22:21:13 by tiaferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	list_printer(t_map_list *map_list)
{
	t_map_list *node;

	node = map_list;
	while (node)
	{
		printf("%s", node->row);
		node = node->next;
	}
}

void	grid_printer(char **grid)
{
	int	i;

	i = -1;
	while (grid[++i])
		printf("%s", grid[i]);
}

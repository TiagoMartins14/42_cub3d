/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiaferna <tiaferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 08:50:28 by tiaferna          #+#    #+#             */
/*   Updated: 2024/05/04 08:50:57 by tiaferna         ###   ########.fr       */
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

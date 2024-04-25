/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:19:37 by guilrodr          #+#    #+#             */
/*   Updated: 2023/12/09 18:18:47 by guilrodr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(char **map, size_t y_index)
{
	size_t	index;

	index = 0;
	while (index < y_index)
	{
		free(map[index]);
		index++;
	}
	free(map);
}

void	print_map(char **map, size_t y_index)
{
	size_t	index;
	size_t	len;

	index = 0;
	len = str_len(map[index]);
	while (index < y_index)
	{
		write(1, map[index], len);
		write(1, "\n", 1);
		index++;
	}
}

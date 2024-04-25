/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_closed.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:01:42 by guilrodr          #+#    #+#             */
/*   Updated: 2023/12/09 12:36:28 by guilrodr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	is_closed(t_master *master, char **map)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (x < master->map.map_size_x)
		if (map[y][x++] != '1')
			second_class_error_handler(master, 1);
	x--;
	while (y < master->map.map_size_y)
		if (map[y++][x] != '1')
			second_class_error_handler(master, 1);
	y--;
	while (x)
		if (map[y][x--] != '1')
			second_class_error_handler(master, 1);
	while (y)
		if (map[y--][x] != '1')
			second_class_error_handler(master, 1);
}

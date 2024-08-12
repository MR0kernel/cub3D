/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_are_valid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:27:08 by guilrodr          #+#    #+#             */
/*   Updated: 2024/08/10 18:39:09 by guilrodr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	player_counter(t_master *master, size_t y, size_t x);
static void	exit_counter(t_master *master);

void	valid_objects_check(t_master *master, char **map)
{
	size_t	x;
	size_t	y;

	master->collectibles = 0;
	x = 0;
	y = 0;
	while (y < master->map.map_size_y)
	{
		while (x < master->map.map_size_x)
		{
			if (map[y][x] != 'P' && map[y][x] != 'C' &&
				map[y][x] != 'E' && map[y][x] != '1' && map[y][x] != '0')
				second_class_error_handler(master, 2);
			if (map[y][x] == 'P')
				player_counter(master, y, x);
			if (map[y][x] == 'E')
				exit_counter(master);
			if (map[y][x] == 'C')
				master->collectibles++;
			x++;
		}
		x = 0;
		y++;
	}
}

static void	player_counter(t_master *master, size_t y, size_t x)
{
	static int	player;

	player++;
	master->player.y = y;
	master->player.x = x;
	if (player > 1)
		second_class_error_handler(master, 3);
}

static void	exit_counter(t_master *master)
{
	static int	game_exit;

	(void)master;
	game_exit++;
}

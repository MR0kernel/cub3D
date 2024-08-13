/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_mouvement_master.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:28:41 by guilrodr          #+#    #+#             */
/*   Updated: 2024/08/13 20:41:41 by guilrodr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	validation(t_master *master, t_xy x, t_xy y);

int	character_mouvement(t_master *master, int keypressed)
{
	if (keypressed == 119)
	{
		master->player.y += (sin(master->player.dir) / 10);
		master->player.x += (cos(master->player.dir) / 10);
		clear_canvas(SCREEN_SIZE_X / MINI_MAP_DIV_X, SCREEN_SIZE_Y / MINI_MAP_DIV_Y, master->mini_map);
	}
	
	if (keypressed == 115)
	{
		master->player.y -= (sin(master->player.dir) / 10);
		master->player.x -= (cos(master->player.dir) / 10);
		clear_canvas(SCREEN_SIZE_X / MINI_MAP_DIV_X, SCREEN_SIZE_Y / MINI_MAP_DIV_Y, master->mini_map);
	}
	if (keypressed == 100)
	{
		master->player.y += (sin(master->player.dir) / 10);
		master->player.x -= (cos(master->player.dir) / 10);
		clear_canvas(SCREEN_SIZE_X / MINI_MAP_DIV_X, SCREEN_SIZE_Y / MINI_MAP_DIV_Y, master->mini_map);
	}
	if (keypressed == 97)
	{
		master->player.y -= (sin(master->player.dir) / 10);
		master->player.x += (cos(master->player.dir) / 10);
		clear_canvas(SCREEN_SIZE_X / MINI_MAP_DIV_X, SCREEN_SIZE_Y / MINI_MAP_DIV_Y, master->mini_map);
	}
	if (keypressed == XK_Left)
	{
		master->player.dir -= 0.05;
		if (master->player.dir < 0)
			master->player.dir += 2 * PI;

		master->player.dir_x = cos(master->player.dir);
		master->player.dir_y = sin(master->player.dir);

		clear_canvas(SCREEN_SIZE_X / MINI_MAP_DIV_X, SCREEN_SIZE_Y / MINI_MAP_DIV_Y, master->mini_map);
	}
	if (keypressed == XK_Right)
	{
		master->player.dir += 0.05;
		if (master->player.dir > 2 * PI)
			master->player.dir -= 2 * PI;
		master->player.dir_x = cos(master->player.dir);
		master->player.dir_y = sin(master->player.dir);
	}
	clear_canvas(SCREEN_SIZE_X / MINI_MAP_DIV_X, SCREEN_SIZE_Y / MINI_MAP_DIV_Y, master->mini_map);
	return (0);
}

static int	validation(t_master *master, t_xy _x, t_xy _y)
{
	int	x;
	int	y;

	
	printf("x = %d, y = %d\n", x, y);

	if (x < 0 || y < 0 || x >= master->map.map_size_x || y >= master->map.map_size_y)
		return (1);
	return (0);
}

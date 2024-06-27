/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_mouvement_master.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:28:41 by guilrodr          #+#    #+#             */
/*   Updated: 2024/06/21 12:08:00 by guilrodr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	score_and_validation(t_master *master, int x, int y);

int	character_mouvement(t_master *master, int keypressed)
{
	if (keypressed == 119)
		if (score_and_validation(master, master->player.x, \
								master->player.y - 1))
			master->player.y -= 0.1;
	if (keypressed == 115)
		if (score_and_validation(master, master->player.x, \
								master->player.y + 1))
			master->player.y += 0.1;
	if (keypressed == 97)
		if (score_and_validation(master, master->player.x, \
								master->player.y + 1))
			master->player.x -= 0.1;
	if (keypressed == 100)
		if (score_and_validation(master, master->player.x, \
								master->player.y + 1))
			master->player.x += 0.1;
	if (keypressed == XK_Left)
		if (score_and_validation(master, master->player.x - 1, \
								master->player.y))
		{
			master->player.dir -= 0.1;
			if (master->player.dir < 0)
				master->player.dir = 2 * PI;
			clear_canvas(SCREEN_SIZE_X / MINI_MAP_DIV_X, SCREEN_SIZE_Y / MINI_MAP_DIV_Y, master->mini_map);
		}
	if (keypressed == XK_Right)
		if (score_and_validation(master, master->player.x + 1, \
								master->player.y))
		{
			master->player.dir += 0.1;
			if (master->player.dir > 2 * PI)
				master->player.dir = 0;
			clear_canvas(SCREEN_SIZE_X / MINI_MAP_DIV_X, SCREEN_SIZE_Y / MINI_MAP_DIV_Y, master->mini_map);
		}
	printf("player x = %f, player y = %f\n", master->player.x, master->player.y);
	return (0);
}

static int	score_and_validation(t_master *master, int x, int y)
{
	static int	number_of_moves;

	if (master->map.original_map[y][x] == 'C')
	{
		master->map.original_map[y][x] = '0';
		if (master->collectibles > 0)
			master->collectibles--;
	}
	if (master->collectibles == 0)
	{
		if (master->map.original_map[y][x] == 'E')
		{
			ft_printf("Congratulations : number of mouvements = %d\n", \
			number_of_moves += 1);
			end_of_program(master, 0);
		}
	}
	if (master->map.original_map[y][x] == '0' \
	|| master->map.original_map[y][x] == 'P' )
	{
		number_of_moves++;
		ft_printf("number of moves = %d\n", number_of_moves);
		return (1);
	}
	return (0);
}

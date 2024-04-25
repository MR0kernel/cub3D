/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_mouvement_master.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:28:41 by guilrodr          #+#    #+#             */
/*   Updated: 2023/12/10 13:02:27 by guilrodr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	score_and_validation(t_master *master, int x, int y);

int	character_mouvement(t_master *master, int keypressed)
{
	mlx_put_image_to_window(master->mlx, master->win, master->imgs.floor_img, (
			master->player.x * 70), (master->player.y * 70));
	if (keypressed == 119)
		if (score_and_validation(master, master->player.x, \
								master->player.y - 1))
			master->player.y -= 1;
	if (keypressed == 115)
		if (score_and_validation(master, master->player.x, \
								master->player.y + 1))
			master->player.y += 1;
	if (keypressed == 97)
		if (score_and_validation(master, master->player.x - 1, \
								master->player.y))
			master->player.x -= 1;
	if (keypressed == 100)
		if (score_and_validation(master, master->player.x + 1, \
								master->player.y))
			master->player.x += 1;
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

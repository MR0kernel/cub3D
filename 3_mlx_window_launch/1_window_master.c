/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_window_master.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 19:08:01 by guilrodr          #+#    #+#             */
/*   Updated: 2024/06/21 12:21:20 by guilrodr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	end_of_program_macro(t_master *master);
int	draw_player(t_master *master);

void	launch_window(t_master *master)
{
	master->mini_map_size_x = (SCREEN_SIZE_X / MINI_MAP_DIV_X);
	master->mini_map_size_y = (SCREEN_SIZE_Y / MINI_MAP_DIV_Y);
	master->mini_map_step_size_x = master->mini_map_size_x / master->map.map_size_x;
	master->mini_map_step_size_y = master->mini_map_size_y / master->map.map_size_y;
	master->win = mlx_new_window(master->mlx, SCREEN_SIZE_X, \
			SCREEN_SIZE_Y, "so_long_3D");
	if (!master->win)
		third_class_error_handler(master, 1);
    master->canvas = mlx_new_image(master->mlx, SCREEN_SIZE_X, SCREEN_SIZE_Y);
	master->mini_map = mlx_new_image(master->mlx, master->mini_map_size_x, master->mini_map_size_y);
	draw_map(master);
	mlx_loop_hook(master->mlx, draw_map, master);
	mlx_hook(master->win, 2, (1L << 0),  keypress, master);
	mlx_hook(master->win, 17, 0, end_of_program_macro, master);
	mlx_loop(master->mlx);
}

int	end_of_program_macro(t_master *master)
{
	end_of_program(master, 0);
	return (0);
}

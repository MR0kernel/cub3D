/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_master.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:45:15 by guilrodr          #+#    #+#             */
/*   Updated: 2024/07/30 13:24:04 by guilrodr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <math.h>

int	draw_mini_map(t_master *master, double hit_x, double hit_y)
{
	(void)hit_x;
	(void)hit_y;
	size_t	x;
	size_t	y;
	
	y = 0;
	draw_cross(master->canvas, master->player.x * master->mini_map_step_size_x, \
								master->player.y * master->mini_map_step_size_y, 0x00FF66FF);
	while (y < master->map.map_size_y)
	{
		x = 0;
		while (x < master->map.map_size_x)
		{
			if (master->map.original_map[y][x] == '1')
			{
				draw_block(master, master->canvas, (t_xy){x *  master->mini_map_step_size_x, \
																y * master->mini_map_step_size_y});
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(master->mlx, master->win, master->canvas, 0, 0);
	return (0);
}

int	draw_map(t_master *master)
{
	clear_canvas(SCREEN_SIZE_X, SCREEN_SIZE_Y, master->canvas);
	draw_floor(master->canvas);
	draw_sky(master->canvas);
	render_3d_map(master, master->player);
	mlx_put_image_to_window(master->mlx, master->win, master->canvas, 0, 0);
	draw_mini_map(master, 1, 1);
	return (0);
}

void draw_sky(t_img *canvas)
{
    int x;
    int y;

    // Define the color for the sky
    unsigned int sky_color = 0x0099CCFF; // Light blue

    // Draw the sky on the upper half of the screen
    y = 0;
    while (y < SCREEN_SIZE_Y / 2)
    {
        x = 0;
        while (x < SCREEN_SIZE_X)
        {
            draw_pixel(canvas, x, y, sky_color);
            x++;
        }
        y++;
    }
}

void draw_floor(t_img *canvas)
{
    int x;
    int y;

    // Define the color for the floor
    unsigned int floor_color = 0x00333333; // Dark gray

    // Draw the floor on the lower half of the screen
    y = SCREEN_SIZE_Y / 2;
    while (y < SCREEN_SIZE_Y)
    {
        x = 0;
        while (x < SCREEN_SIZE_X)
        {
            draw_pixel(canvas, x, y, floor_color);
            x++;
        }
        y++;
    }
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_by_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:35:29 by guilrodr          #+#    #+#             */
/*   Updated: 2024/08/01 23:03:47 by guilrodr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    draw_pixel(t_img *canvas, int x, int y, int color)
{
    char *dest;

    dest = canvas->data + (y * canvas->size_line + x * (canvas->bpp / 8));
    *(unsigned int*)dest = color;
}

void    draw_debug_lines(t_img *canvas)
{
    int _y;
    int _x;

    _y = SCREEN_SIZE_Y;
    _x = SCREEN_SIZE_X;
    while (_y > -1)
        draw_pixel(canvas, SCREEN_SIZE_X >> 1, (_y--), 0x0000FF33);
    while (_x > -1)
        draw_pixel(canvas, _x--, SCREEN_SIZE_Y >> 1, 0x00FF6600); // violet
}

inline void    draw_block(t_master *master, t_img *canvas, t_xy origin, t_img *img)
{
    int x;
    int y;
    unsigned int color;
    int tex_x;
    int tex_y;

    y = 0;
    while (y < master->mini_map_step_size_y)
    {
        x = 0;
        while (x < master->mini_map_step_size_x)
        {
            tex_x = (x * img->width) / master->mini_map_step_size_x;
            tex_y = (y * img->height) / master->mini_map_step_size_y;
            if (x == 0 || y == 0 || x == master->mini_map_step_size_x - 1 || y == master->mini_map_step_size_y - 1)
                color = 0x00FF6600;
            else
                color = *(unsigned int *)(img->data + (tex_y * img->size_line + tex_x * (img->bpp / 8)));
            draw_pixel(canvas, x + origin.x, y + origin.y, color);
            x++;
        }
        y++;
    }
}

void    draw_cross(t_img *canvas, double x, double y, int color)
{
    draw_pixel(canvas, (int)x - 1, (int)y, color);
    draw_pixel(canvas, (int)x - 2, (int)y, color);
    draw_pixel(canvas, (int)x - 3, (int)y, color);
    draw_pixel(canvas, (int)x + 1, (int)y, color);
    draw_pixel(canvas, (int)x + 2, (int)y, color);
    draw_pixel(canvas, (int)x + 3, (int)y, color);
    draw_pixel(canvas, (int)x, (int)y - 1, color);
    draw_pixel(canvas, (int)x, (int)y - 2, color);
    draw_pixel(canvas, (int)x, (int)y - 3, color);
    draw_pixel(canvas, (int)x, (int)y + 1, color);
    draw_pixel(canvas, (int)x, (int)y + 2, color);
    draw_pixel(canvas, (int)x, (int)y + 3, color);
}

void draw_mini_player(t_master *master, t_img *canvas, t_xy origin)
{
    int x;
    int y;
    unsigned int color;

    y = 0;
    color = 0x00000000;
    while (y < 5)
    {
        x = 0;
        while (x < 5)
        {
            draw_pixel(canvas, x + origin.x, y + origin.y, color);
            x++;
        }
        y++;
    }
}

void	clear_canvas(int size_x, int size_y, t_img *canvas)
{
	int i;

	i = 0;
	while (i < size_x * size_y)
		((unsigned int *)canvas->data)[i++] = 0x00000000;
}


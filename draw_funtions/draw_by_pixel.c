/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_by_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:35:29 by guilrodr          #+#    #+#             */
/*   Updated: 2024/06/26 16:45:31 by guilrodr         ###   ########lyon.fr   */
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

void    draw_column(t_img *canvas, t_xy origin, t_xy dest)
{
	double	base;
	double	origin_;

	base = 0;
	origin_ = origin.y;
//	 while (base++ < COLLUMN_SIZE)
//	 {
	while (origin_++ <  dest.y)
	{
		draw_pixel(canvas, origin.x + base, origin_, 0x00FF66FF);
	}
//	 	origin_ = origin.y;
//	 }
}

void    draw_block(t_img *canvas, t_xy origin)
{
	int	x;
	int	y;
	
	x = origin.x;
	y = origin.y;
	while (y < ((COLLUMN_SIZE / MINI_MAP_DIV_Y) + origin.y))
	{
		while (x < ((COLLUMN_SIZE / MINI_MAP_DIV_X) + origin.x))
		{
			draw_pixel(canvas, x, y, 0x0FF0FF00);
			x++;
		}
		x = origin.x;
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

void	clear_canvas(int size_x, int size_y, t_img *canvas)
{
	int i;

	i = 0;
	while (i < size_x * size_y)
		((unsigned int *)canvas->data)[i++] = 0x00000000;
}

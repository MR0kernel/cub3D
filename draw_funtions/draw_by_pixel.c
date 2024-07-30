/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_by_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:35:29 by guilrodr          #+#    #+#             */
/*   Updated: 2024/07/30 13:23:15 by guilrodr         ###   ########lyon.fr   */
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

void    draw_column(t_master *master, t_img *canvas, t_xy origin, t_xy dest)
{
	(void)master;
    char	*color = NULL;
	char	*img_data = master->imgs.wall_img->data; 
	
	printf("AAAA origin.x = %d\n origin.y = %d\n", (origin.x  , origin.y));
	while (origin.y++ <  dest.y)
	{
		if (master->imgs.wall_img->height > origin.x && master->imgs.wall_img->width > origin.y )
		{
			printf("origin.x = %d\n origin.y = %d\n", origin.x  , origin.y);
			color = img_data + (long)(origin.y *(canvas->size_line + origin.x) * (canvas->bpp / 8));
			printf("\n%s\n", color);
		}
		// printf("\n%s\n", color);
		if (!color)
			color = "0x0000FF33";
		draw_pixel(canvas, origin.x, origin.y, *(unsigned int*)color);
	}

}

void    draw_block(t_master *master, t_img *canvas, t_xy origin)
{
	int	x;
	int	y;
	
	x = 0;
	y = 0;
    char	*color = NULL;
	char	*img_data = master->imgs.wall_img->data; 
	
	
	while (y < master->mini_map_step_size_y)
	{
		while (x < master->mini_map_step_size_x)
		{
			x++;
			if (master->imgs.wall_img->height > x + origin.x && master->imgs.wall_img->width > y + origin.y)
			{
				// printf("x + origin.x = %ld\ny + origin.y = %d\n",\
						x + origin.x , y + origin.y);
				color = 0;
				color = img_data + (int)(y + origin.y *( canvas->size_line + x + origin.x) * (canvas->bpp / 8));
			}
			draw_pixel(canvas, x + origin.x, y + origin.y, color);
		}
		x = 0;
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


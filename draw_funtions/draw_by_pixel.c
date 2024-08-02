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

inline void    draw_column(t_master *master, t_img *canvas, t_int_xy origin, t_int_xy dest)
{
    int tex_x;
    int tex_y;
    unsigned int color = 0x00FF6600;
	int texture_index = 0;
    int wall_height = dest.y - origin.y;
    
    // double step = master->ray.distance/10;
    double step = 1;
    // printf("step = %f\n", step);
    double wallX; //where exactly the wall was hit
 
    if (master->ray.side == 0)
        wallX = master->player.y + master->ray.distance * master->ray.dir_y;
    else
        wallX = master->player.x + master->ray.distance * master->ray.dir_x;
    wallX -= floor((wallX));

    int texX = (int)(wallX * (double)(master->imgs.wall_img->height));
    if(master->ray.side == 0 && master->ray.dir_x > 0) 
        texX = master->imgs.wall_img->height - texX - 1;
    if(master->ray.side == 1 && master->ray.dir_y < 0) 
        texX = master->imgs.wall_img->height - texX - 1;
    // printf("master->player.x %f\n",master->player.x);
    // printf(" master->ray.distance %f\n", master->ray.distance);
    // printf("master->ray.dir_x%f\n",master->ray.dir_x);

    // printf("wallX%f\n",wallX);
    while (origin.y <= dest.y)
    {
        tex_x = (int)(((texX * master->imgs.wall_img->height)) / wall_height) ;
        tex_y = (master->player.dir_y + (texture_index) * master->imgs.wall_img->height / wall_height) * step;

        color = *(unsigned int *)(master->imgs.wall_img->data + ((tex_y * master->imgs.wall_img->size_line) + (tex_x * (master->imgs.wall_img->bpp / 8))));
		draw_pixel(canvas, origin.x, origin.y, color);
        origin.y++;
    	texture_index++;
    }
}

void    draw_block(t_master *master, t_img *canvas, t_xy origin)
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
            tex_x = (x + origin.x) * master->imgs.wall_img->width /  (SCREEN_SIZE_X / MINI_MAP_DIV_X);
            tex_y = (y + origin.y) * master->imgs.wall_img->height / (SCREEN_SIZE_Y / MINI_MAP_DIV_Y);

            color = *(unsigned int *)(master->imgs.wall_img->data + (tex_y * master->imgs.wall_img->size_line + tex_x * (master->imgs.wall_img->bpp / 8)));
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

void	clear_canvas(int size_x, int size_y, t_img *canvas)
{
	int i;

	i = 0;
	while (i < size_x * size_y)
		((unsigned int *)canvas->data)[i++] = 0x00000000;
}


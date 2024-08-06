/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:35:29 by guilrodr          #+#    #+#             */
/*   Updated: 2024/08/01 23:03:47 by guilrodr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int  get_texture_x(t_master *master, t_img *img, int wall_height);

inline void draw_column(t_master *master, t_img *canvas, t_img *img, t_int_xy origin, t_int_xy dest)
{
    unsigned int color = 0x00FF6600;
    int tex_x;
    int tex_y;
    int wall_height;
    double step;
    int texture_index = 0;

    wall_height = dest.y - origin.y;
    tex_x = get_texture_x(master, img, wall_height);

    step = (double)  img->height / wall_height ;

    // printf("step: %f\n", step);
    tex_x = get_texture_x(master, img, wall_height);
    tex_y = 0; 
    while (origin.y < dest.y)
    {
        tex_y = ((texture_index * img->height) / (wall_height));
        tex_y += (int)(master->ray.y_offset * step);
        
        color = *(unsigned int *)(img->data + ((tex_y * img->size_line) + (tex_x * (img->bpp / 8))));
        draw_pixel(canvas, origin.x, origin.y, color);

        texture_index++;
        origin.y++;
    }
}


static int get_texture_x(t_master *master, t_img *img, int wall_height)
{
    if (master->ray.side == 0)
        return ((master->ray.y - (int)master->ray.y) * img->width);
    else
        return ((master->ray.x - (int)master->ray.x) * img->width);
}

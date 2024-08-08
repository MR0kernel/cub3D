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
    unsigned int color;
    int tex_x;
    int tex_y;
    int wall_height;
    double step;
    double tex_pos;

    wall_height = (dest.y - origin.y) + master->ray.y_offset;
    tex_x = get_texture_x(master, img, wall_height);
    step = (double) img->height / wall_height;

    tex_pos = 0;
    tex_pos += master->ray.y_offset * step / 2;
    
    while (origin.y < dest.y)
    {
        tex_y = (int)tex_pos;
        
        if (tex_y >= 0 && tex_y < img->height)
        {
            color = *(unsigned int *)(img->data + ((tex_y * img->size_line) + (tex_x * (img->bpp / 8))));
            draw_pixel(canvas, origin.x, origin.y, color);
        }

        tex_pos += step;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_by_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:35:29 by guilrodr          #+#    #+#             */
/*   Updated: 2024/04/25 17:48:35 by guilrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    draw_pixel(t_img *canvas, int x, int y, int color)
{
    char *dest;

    dest = canvas->data + (y * canvas->size_line + x * (canvas->bpp / 8));
    *(unsigned int*)dest = color;
}

void    draw_line(t_img *canvas, int x, int size, int color)
{
    int index_up;
//    int index_down;
    int _y;

    index_up = size >> 1;
//    index_down = size >> 1;
    _y = SCREEN_SIZE_Y >> 1;
    while (index_up > -1)
    {
        draw_pixel(canvas, x, (_y + index_up--), color);
//        draw_pixel(canvas, x, (_y + index_down--), color);
    }
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_by_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:35:29 by guilrodr          #+#    #+#             */
/*   Updated: 2024/05/10 17:30:19 by guilrodr         ###   ########lyon.fr   */
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
        draw_pixel(canvas, _x--, SCREEN_SIZE_Y >> 1, 0x00FF66FF); // violet
}
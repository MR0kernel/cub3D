/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_by_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:35:29 by guilrodr          #+#    #+#             */
/*   Updated: 2024/08/13 20:50:03 by guilrodr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_pixel(t_img *canvas, int x, int y, int color)
{
	char	*dest;

	dest = canvas->data + (y * canvas->size_line + x * (canvas->bpp / 8));
	*(unsigned int *)dest = color;
}

inline void	draw_block(t_master *master, t_img *canvas, t_xy origin, t_img *img)
{
	int				x;
	int				y;
	unsigned int	color;
	int				tex_x;
	int				tex_y;

	origin.x *= master->mini_map_step_size_x;
	origin.y *= master->mini_map_step_size_y;
	y = 0;
	while (y < master->mini_map_step_size_y)
	{
		x = 0;
		while (x < master->mini_map_step_size_x)
		{
			tex_x = (x * img->width) / master->mini_map_step_size_x;
			tex_y = (y * img->height) / master->mini_map_step_size_y;
			color = *(unsigned int *)(img->data + \
					(tex_y * img->size_line + tex_x * (img->bpp / 8)));
			draw_pixel(canvas, x + origin.x, y + origin.y, color);
			x++;
		}
		y++;
	}
}

void	draw_cross(t_img *canvas, double x, double y, int color)
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

void	draw_mini_player(t_master *master, t_xy origin)
{
	int				x;
	int				y;
	unsigned int	color;

	origin.x *= master->mini_map_step_size_x;
	origin.y *= master->mini_map_step_size_y;
	y = 0;
	color = 0x00000000;
	while (y < 5)
	{
		x = 0;
		while (x < 5)
		{
			draw_pixel(master->canvas, x + origin.x, y + origin.y, color);
			x++;
		}
		y++;
	}
}

void	clear_canvas(int size_x, int size_y, t_img *canvas)
{
	int	i;

	i = 0;
	while (i < size_x * size_y)
		((unsigned int *)canvas->data)[i++] = 0x00000000;
}

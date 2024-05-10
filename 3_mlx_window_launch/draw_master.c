/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_master.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:45:15 by guilrodr          #+#    #+#             */
/*   Updated: 2024/05/10 17:30:27 by guilrodr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void insert_objects(t_master *master, char object, int x, int y);
//static void draw_line(t_master *master, int x0,int y0,int x1,int y1);

int	draw_player(t_master *master)
{
    mlx_put_image_to_window(master->mlx, master->win, master->canvas, 0, 0);
//	mlx_put_image_to_window(master->mlx, master->win,
//							master->imgs.player_img,
//							(master->player.x * 70),
//							(master->player.y * 70));
    draw_debug_lines(master->canvas);
    return (0);
}

//void draw_line (t_master *master, int x0,int y0,int x1,int y1)
//{
//    int dy, dx, incrE, incrNE, d,x,y;
//
//    dx = x1 - x0;
//    dy = y1 - y0;
//    d = 2 * dy - dx;
//    incrE = 2*dy;
//    incrNE = 2*(dy - dx);
//    x = x0;
//    y = y0;
//    mlx_pixel_put(master->mlx, master->win, x, y, 0x00FF0000);
//    while(x < x1)
//    {
//        if (d <= 0)
//        {
//            d += incrE;
//            x++;
//        }
//        else
//        {
//            d += incrNE;
//            x++;
//            y++;
//        }
//        mlx_pixel_put(master->mlx, master->win, x, y, 0x00FF0000);
//    }
//    printf("player X %d; player Y%d; ------- X%d Y%d\n", x1, y1, x, y);
//}

void	draw_map(t_master *master)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (y < master->map.map_size_y)
	{
		while (x < master->map.map_size_x)
		{
			insert_objects(master, master->map.original_map[y][x], x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

static void	insert_objects(t_master *master, char object, int x, int y)
{
	if (object == '1')
		mlx_put_image_to_window(master->mlx, master->win, \
								master->imgs.wall_img, (x * 70), \
								(y * 70));
	if (object == '0')
		mlx_put_image_to_window(master->mlx, master->win, \
								master->imgs.floor_img, (x * 70), \
								(y * 70));
	else if (object == 'C')
		mlx_put_image_to_window(master->mlx, master->win, \
								master->imgs.collectible_img, (x * 70), \
								(y * 70));
	else if (object == 'E')
		mlx_put_image_to_window(master->mlx, master->win, \
								master->imgs.exit_img, (x * 70), \
								(y * 70));
}

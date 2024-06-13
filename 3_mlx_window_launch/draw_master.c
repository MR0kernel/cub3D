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
#include <math.h>

//static void draw_line(t_master *master, int x0,int y0,int x1,int y1);
static double raycast_x(t_master *master, t_player player);
static double raycast_y(t_master *master, t_player player);
static void raycast(t_master *master, t_player player);

int	draw_player(t_master *master)
{
//    mlx_put_image_to_window(master->mlx, master->win, master->canvas, 0, 0);
//	mlx_put_image_to_window(master->mlx, master->win,
//							master->imgs.player_img,
//							(master->player.x * 70),
//							(master->player.y * 70));
    draw_debug_lines(master->canvas);
//    draw_map(master);
    return (0);
}

void	draw_map(t_master *master)
{
    t_player player;
    t_xy a;
    t_xy b;

    player.x = 5.20;
    player.y = 5.10;
    player.dir = 0.66;

    a.y = 10;
    a.x = 10;

    b.y = 300;
    b.x = 10;
    draw_debug_lines(master->canvas);
    draw_column(master->canvas, a, b);
    draw_cross(master->canvas, 120, 320);
    raycast(master, player);
    mlx_put_image_to_window(master->mlx, master->win, master->canvas, 0, 0);

}
static void raycast(t_master *master, t_player player)
{
    double x = raycast_x(master, player);
    double y = raycast_y(master, player);
    printf("[x = %f] [y = %f]", fabs(x), fabs(y));
//    draw_cross(master->canvas, fabs(x), fabs(y));

}

static double raycast_y(t_master *master, t_player player)
{
    (void)master;
    double y;
    double i;

    y = round(player.y);
    i = tan(player.dir) * (y - player.y);
    return (i);
}

static double raycast_x(t_master *master, t_player player)
{
    (void)master;
    double x;
    double i;

    x = round(player.x);
    i = tan(player.dir) * (x - player.x);
    return (i);
}
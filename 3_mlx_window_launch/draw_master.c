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
static t_xy	raycast_x(t_master *master, t_player player);
static t_xy	raycast_y(t_master *master, t_player player);
static void	raycast(t_master *master, t_player player);

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
    t_xy a;
    t_xy b;

    a.y = 10;
    a.x = 10;

    b.y = 300;
    b.x = 10;
    draw_debug_lines(master->canvas);
    draw_column(master->canvas, a, b);
    draw_cross(master->canvas, 120, 320);
    raycast(master, master->player);
    mlx_put_image_to_window(master->mlx, master->win, master->canvas, 0, 0);

}
static void raycast(t_master *master, t_player player)
{
	t_xy test;
	

    test = raycast_y(master, player);
    printf("Y = [x = %f] [y = %f]\n", fabs(test.x), fabs(test.y));
//    draw_cross(master->canvas, fabs(x), fabs(y));
	test = raycast_x(master, player);
	printf("X = [x = %f] [y = %f]\n", fabs(test.x), fabs(test.y));

}

static t_xy raycast_y(t_master *master, t_player player)
{
    t_xy	p_;
    t_xy	ret;
	
	ret.x = 0;
	ret.y = -1;
//    determiner le la direction
    if (!sin(player.dir))
        return (ret);
//    p1x est egal a p plus ou moins 1 depandant de la direction
	ret.x = player.x + 1;
    p_.x = 1;
    if (sin(player.dir) < 0)
    {
        p_.x = -1;
		ret.x--;
    }
	p_.y = p_.x * tan(player.dir);
	ret.y =  player.y + p_.y * fabs(ret.x - player.x);
	printf("in raycast y [x = %ld] [y = %ld]\n", (size_t)(ret.x), (size_t)ret.y);
	while (master->map.original_map[(size_t)(ret.x)][(size_t)ret.y] == '0' \
		&& ret.x < master->map.map_size_x && ret.y < master->map.map_size_y)
	{
		printf("\n\nhere\n\n");
		ret.x += p_.x;
		ret.y += p_.y;
	}
    return (ret);
}

static t_xy	raycast_x(t_master *master, t_player player)
{
	t_xy	p_;
	t_xy	ret;
	
	ret.x = -1;
	ret.y = 1;
//    determiner le la direction
	if (!cos(player.dir))
		return (ret);
//    p1x est egal a p plus ou moins 1 depandant de la direction
	ret.y = player.y + 1;
	p_.y = 1;
	if (cos(player.dir) < 0)
	{
		p_.y = -1;
		ret.y--;
	}
	p_.x = p_.y * tan(player.dir);
	printf ("player dir %f\n", player.dir);
	ret.x =  player.x + p_.x * fabs(ret.y - player.y);
	printf("in raycast x [x = %ld] [y = %ld]\n", (size_t)(ret.x), (size_t)ret.y);
	
	while (master->map.original_map[(size_t)ret.x][(size_t)ret.y] == '0' \
		&& ret.x < master->map.map_size_x && ret.y < master->map.map_size_y)
	{
		ret.x += p_.x;
		ret.y += p_.y;
	}
	return (ret);
}
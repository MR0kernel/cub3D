/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 23:37:11 by guilrodr          #+#    #+#             */
/*   Updated: 2024/08/01 22:40:40 by guilrodr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

inline t_ray raycast_y(t_master *master, t_player player)
{
	t_xy	p_;
	t_ray	ret;
	double	sp;

	bzero(&ret, sizeof(t_ray));// CHANGE TO FT_BZERO
	sp = sin(player.dir);
	ret.x = -1;
	ret.y = -1;
	if (!fabs(sp))
		return (ret);
	if (sp > 0) {
		ret.y = floor(player.y) + 1;
		p_.y = 1;
		ret.orientation = SOUTH;
	} else {
		ret.y = ceil(player.y) - 1;
		p_.y = -1;
		ret.orientation = NORTH;
	}
	p_.x = p_.y / tan(player.dir);
	ret.x = player.x + p_.x * fabs(ret.y - player.y);
	while (ret.y > 0 && ret.x >= 0 && ret.x < master->map.map_size_x && ret.y < master->map.map_size_y)
	{
		if (master->map.original_map[(size_t)(ret.y - (sp < 0))][(size_t)(ret.x)] != '0' && \
			master->map.original_map[(size_t)(ret.y - (sp < 0))][(size_t)(ret.x)] != 'P')
			break;
		ret.x += p_.x;
		ret.y += p_.y;
		if (ret.x < 0 || ret.y < 0 || ret.x >= master->map.map_size_x || ret.y >= master->map.map_size_y)
			break;
	}
	return (ret);
}

inline t_ray raycast_x(t_master *master, t_player player)
{
	t_xy	p_;
	t_ray	ret;
	double	cp;

	bzero(&ret, sizeof(t_ray));// CHANGE TO FT_BZERO
	cp = cos(player.dir);
	ret.x = -1;
	ret.y = -1;
	if (!fabs(cp))
		return (ret);
	if (cp > 0)
	{
		ret.x = floor(player.x) + 1;
		p_.x = 1;
		ret.orientation = EAST;
	} else
	{
		ret.x = ceil(player.x) - 1;
		p_.x = -1;
		ret.orientation = WEST;
	}
	p_.y = p_.x * tan(player.dir);
	ret.y = player.y + p_.y * fabs(ret.x - player.x);
	while (ret.y >= 0 && ret.x >= 0 && ret.x < master->map.map_size_x && ret.y < master->map.map_size_y)
	{
		if (master->map.original_map[(size_t)ret.y][(size_t)(ret.x - (cp < 0))] != '0' && \
			master->map.original_map[(size_t)ret.y][(size_t)(ret.x - (cp < 0))] != 'P')
			break;
		ret.x += p_.x;
		ret.y += p_.y;
	}
	return (ret);
}

inline double	closest_distance(t_master *master, t_ray hit_x, t_ray hit_y, t_player player)
{
	double	distance_a;
	double	distance_b;
	t_xy	a;
	t_xy	b;

	a.x = hit_x.x - player.x;
	a.y = hit_x.y - player.y;
	b.x = hit_y.x - player.x;
	b.y = hit_y.y - player.y;
	
	distance_a = sqrt(a.x * a.x + a.y * a.y);
	distance_b = sqrt(b.x * b.x + b.y * b.y);
	if (distance_a < distance_b)
	{
		master->ray = hit_x;
		master->ray.side = 0;
		master->ray.dir_x = hit_x.x - player.x;
		master->ray.dir_y = hit_x.y - player.y;
		return (distance_a);
	}
	master->ray = hit_y;
	master->ray.side = 1;
	master->ray.dir_x = hit_y.x - player.x;
	master->ray.dir_y = hit_y.y - player.y;
	return (distance_b);
}

inline void render_3d_map(t_master *master, t_player player)
{
	t_player ray_player = {player.x, player.y, player.dir_x, player.dir_y, 0};
	double	ray_dir;
	int		wall_height;
	int		wall_start;
	int		wall_end;
	master->ray.y_offset = 1;
	bzero(master->list_of_rays, sizeof(t_ray) * SCREEN_SIZE_X);// CHANGE TO FT_BZERO
	for (int x = 0; x < SCREEN_SIZE_X; x++)
	{
		ray_dir = (player.dir) + (ONE_DEGREE * x / FOV);
		ray_player.dir = ray_dir;
		master->ray.dir_x = cos(ray_dir);
		master->ray.dir_y = sin(ray_dir);

		
		master->ray.distance = closest_distance(master, raycast_x(master, ray_player),
									raycast_y(master, ray_player), player);
		master->list_of_rays[x] = master->ray;
		master->wall_height = (int)(WALL_HEIGHT / master->ray.distance);
		if (master->wall_height > SCREEN_SIZE_Y)
		{
			master->ray.y_offset = (master->wall_height - SCREEN_SIZE_Y) >> 1;
			master->wall_height = SCREEN_SIZE_Y;
		}
		wall_start = (-master->wall_height >> 1) + (SCREEN_SIZE_Y >> 1);
		wall_end = (master->wall_height >> 1) + (SCREEN_SIZE_Y >> 1);

		if (master->ray.orientation == NORTH)
			draw_column(master, master->canvas, master->imgs.wall_img, (t_int_xy){x, wall_start}, (t_int_xy){x, wall_end});
		else if (master->ray.orientation == SOUTH)
			draw_column(master, master->canvas, master->imgs.player_img, (t_int_xy){x, wall_start}, (t_int_xy){x, wall_end});
		else if (master->ray.orientation == EAST)
			draw_column(master, master->canvas, master->imgs.exit_img, (t_int_xy){x, wall_start}, (t_int_xy){x, wall_end});
		else
			draw_column(master, master->canvas, master->imgs.floor_img, (t_int_xy){x, wall_start}, (t_int_xy){x, wall_end});
	}
}

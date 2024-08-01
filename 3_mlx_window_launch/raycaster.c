/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 23:37:11 by guilrodr          #+#    #+#             */
/*   Updated: 2024/04/27 23:37:47 by guilrodr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_xy raycast_y(t_master *master, t_player player)
{
	t_xy	p_;
	t_xy	ret;
	double	sp;

	sp = sin(player.dir);
	ret.x = -1;
	ret.y = -1;
	if (!fabs(sp))
		return (ret);
	if (sp > 0) {
		ret.y = floor(player.y) + 1;
		p_.y = 1;
	} else {
		ret.y = ceil(player.y) - 1;
		p_.y = -1;
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

t_xy raycast_x(t_master *master, t_player player)
{
	t_xy	p_;
	t_xy	ret;
	double	cp;

	cp = cos(player.dir);
	ret.x = -1;
	ret.y = -1;
	if (!fabs(cp))
		return (ret);
	if (cp > 0)
	{
		ret.x = floor(player.x) + 1;
		p_.x = 1;
	} else
	{
		ret.x = ceil(player.x) - 1;
		p_.x = -1;
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

double	closest_distance(t_master *master, t_xy hit_x, t_xy hit_y, t_player player)
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
	// printf("distanace a = %f", distance_a);
	distance_b = sqrt(b.x * b.x + b.y * b.y);
	// printf("distanace a = %f", distance_b);
	if (distance_a < distance_b)
	{
		draw_cross(master->canvas, hit_x.x * master->mini_map_step_size_x, \
										hit_x.y * master->mini_map_step_size_y, 0x0000FF33);
		return (distance_a);
	}
	draw_cross(master->canvas, hit_y.x * master->mini_map_step_size_x, \
									hit_y.y * master->mini_map_step_size_y, 0x0000FF33);
	// printf("hit_y.x = %f, hit_y.y = %f\n", hit_y.x, hit_y.y);
	return (distance_b);
}

void render_3d_map(t_master *master, t_player player)
{
	t_player ray_player = {player.x, player.y, player.dir_x, player.dir_y, 0};
	double	ray_dir;
	double	distance;
	int		wall_height;
	int		wall_start;
	int		wall_end;

	for (int x = 0; x < SCREEN_SIZE_X; x++)
	{
		ray_dir = player.dir - (ONE_DEGREE * x / FOV);
		// printf("RAY DIR %f\n", ray_dir);
		ray_player.dir = ray_dir;
		distance = closest_distance(master, raycast_x(master, ray_player),
									raycast_y(master, ray_player), player);
		wall_height = (int)(SCREEN_SIZE_Y / distance);
		wall_start = (-wall_height >> 1) + (SCREEN_SIZE_Y >> 1);
		if (wall_start < 0)
			wall_start = 0;
		wall_end = (wall_height >> 1) + (SCREEN_SIZE_Y >> 1);
		if (wall_end >= SCREEN_SIZE_Y)
			wall_end = SCREEN_SIZE_Y - 1;
		draw_column(master, master->canvas, (t_int_xy){x, wall_start}, (t_int_xy){x, wall_end});
	}
}

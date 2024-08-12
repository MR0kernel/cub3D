/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:35:29 by guilrodr          #+#    #+#             */
/*   Updated: 2024/08/10 18:36:46 by guilrodr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static float	degree_to_radian(float degree);
static int		get_texture_x(t_master *master, t_img *img);

inline void	draw_wall(t_master *master, int x)
{
	int	wall_start;
	int	wall_end;

	master->wall_height = (int)(WALL_HEIGHT / master->ray.distance);
	if (master->wall_height > SCREEN_SIZE_Y)
	{
		master->ray.y_offset = ((master->wall_height - SCREEN_SIZE_Y));
		master->wall_height = SCREEN_SIZE_Y;
	}
	wall_start = (-master->wall_height >> 1) + (SCREEN_SIZE_Y >> 1);
	wall_end = (master->wall_height >> 1) + (SCREEN_SIZE_Y >> 1);
	if (master->ray.orientation == NORTH)
		draw_column(master, master->imgs.wall_img, \
				(t_int_xy){x, wall_start}, (t_int_xy){x, wall_end});
	else if (master->ray.orientation == SOUTH)
		draw_column(master, master->imgs.player_img, \
				(t_int_xy){x, wall_start}, (t_int_xy){x, wall_end});
	else if (master->ray.orientation == EAST)
		draw_column(master, master->imgs.exit_img, \
				(t_int_xy){x, wall_start}, (t_int_xy){x, wall_end});
	else
		draw_column(master, master->imgs.floor_img, \
				(t_int_xy){x, wall_start}, (t_int_xy){x, wall_end});
}

inline void	draw_column(t_master *master, t_img *img, \
							t_int_xy origin, t_int_xy dest)
{
	unsigned int	color;
	t_int_xy		tex;
	int				wall_height;
	double			step;
	double			tex_pos;

	wall_height = (dest.y - origin.y) + master->ray.y_offset;
	tex.x = get_texture_x(master, img);
	step = (double) img->height / wall_height;
	tex_pos = 0;
	tex_pos += master->ray.y_offset * step / 2;
	while (origin.y < dest.y)
	{
		tex.y = (int)tex_pos;
		if (tex.y >= 0 && tex.y < img->height)
		{
			color = *(unsigned int *)(img->data + \
						((tex.y * img->size_line) + (tex.x * (img->bpp / 8))));
			draw_pixel(master->canvas, origin.x, origin.y, color);
		}
		tex_pos += step;
		origin.y++;
	}
}

static int	get_texture_x(t_master *master, t_img *img)
{
	if (master->ray.side == 0)
		return ((master->ray.y - (int)master->ray.y) * img->width);
	else
		return ((master->ray.x - (int)master->ray.x) * img->width);
}

inline void	render_3d_map(t_master *master, t_player player)
{
	t_player	ray_player;
	int			x;
	double		ray_dir;
	double		ray_increment;

	init_tools(&ray_player, &player);
	x = 0;
	ft_bzero(master->list_of_rays, sizeof(t_ray) * SCREEN_SIZE_X);
	ray_dir = player.dir - degree_to_radian(FOV / 2);
	ray_increment = ONE_DEGREE * FOV / SCREEN_SIZE_X;
	while (x < SCREEN_SIZE_X)
	{
		ray_dir += ray_increment;
		ray_player.dir = ray_dir;
		master->ray.dir_x = cos(ray_dir);
		master->ray.dir_y = sin(ray_dir);
		master->ray.distance = closest_distance(master, \
									raycast_x(master, ray_player), \
									raycast_y(master, ray_player), player);
		master->ray.angle = ray_dir - player.dir;
		master->ray.distance *= cos(master->ray.angle);
		master->list_of_rays[x] = master->ray;
		draw_wall(master, x);
		x++;
	}
}

static float	degree_to_radian(float degree)
{
	return (degree * (PI / 180));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 23:37:11 by guilrodr          #+#    #+#             */
/*   Updated: 2024/08/10 18:25:01 by guilrodr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	side_mesure_x(double cp, t_ray *ret, t_player player, t_xy *p_);
void	side_mesure_y(double sp, t_ray *ret, t_player player, t_xy *p_);

inline t_ray	raycast_y(t_master *master, t_player player)
{
	t_xy	p_;
	t_ray	ret;
	double	sp;

	ft_bzero(&ret, sizeof(t_ray));
	sp = sin(player.dir);
	ret.x = -1;
	ret.y = -1;
	if (!fabs(sp))
		return (ret);
	side_mesure_y(sp, &ret, player, &p_);
	p_.x = p_.y / tan(player.dir);
	ret.x = player.x + p_.x * fabs(ret.y - player.y);
	while (ret.y > 0 && ret.x >= 0 && ret.x < master->map.map_size_x && \
			ret.y < master->map.map_size_y)
	{
		if (master->map.original_map[(size_t)(ret.y - (sp < 0))] \
									[(size_t)(ret.x)] != '0' && \
			master->map.original_map[(size_t)(ret.y - (sp < 0))] \
									[(size_t)(ret.x)] != 'P')
			break ;
		ret.x += p_.x;
		ret.y += p_.y;
	}
	return (ret);
}

inline t_ray	raycast_x(t_master *master, t_player player)
{
	t_xy	p_;
	t_ray	ret;
	double	cp;

	ft_bzero(&ret, sizeof(t_ray));
	cp = cos(player.dir);
	ret.x = -1;
	ret.y = -1;
	if (!fabs(cp))
		return (ret);
	side_mesure_x(cp, &ret, player, &p_);
	p_.y = p_.x * tan(player.dir);
	ret.y = player.y + p_.y * fabs(ret.x - player.x);
	while (ret.y >= 0 && ret.x >= 0 && ret.x < master->map.map_size_x \
				&& ret.y < master->map.map_size_y)
	{
		if (master->map.original_map[(size_t)ret.y] \
				[(size_t)(ret.x - (cp < 0))] != '0' && \
			master->map.original_map[(size_t)ret.y] \
				[(size_t)(ret.x - (cp < 0))] != 'P')
			break ;
		ret.x += p_.x;
		ret.y += p_.y;
	}
	return (ret);
}

void	side_mesure_y(double sp, t_ray *ret, t_player player, t_xy *p_)
{
	if (sp > 0)
	{
		ret->y = floor(player.y) + 1;
		p_->y = 1;
		ret->orientation = SOUTH;
	}
	else
	{
		ret->y = ceil(player.y) - 1;
		p_->y = -1;
		ret->orientation = NORTH;
	}
}

void	side_mesure_x(double cp, t_ray *ret, t_player player, t_xy *p_)
{
	if (cp > 0)
	{
		ret->x = floor(player.x) + 1;
		p_->x = 1;
		ret->orientation = EAST;
	}
	else
	{
		ret->x = ceil(player.x) - 1;
		p_->x = -1;
		ret->orientation = WEST;
	}
}

inline double	closest_distance(t_master *master, \
								t_ray hit_x, t_ray hit_y, t_player player)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_mouvement_master.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:28:41 by guilrodr          #+#    #+#             */
/*   Updated: 2024/08/13 23:09:53 by guilrodr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	validation(t_master *master, t_xy next_pos);
static void	move_left_right(t_master *master);
static void	rotate(t_master *master, double angle);
static void	move_back_foward(t_master *master);

int	character_mouvement(t_master *master)
{
	if (master->player.up || master->player.down)
		move_back_foward(master);
	else if (master->player.left || master->player.rigth)
		move_left_right(master);
	if (master->player.rotate_left || master->player.rotate_right)
		rotate(master, 0.008);
	return (0);
}

static void	move_left_right(t_master *master)
{
	t_xy	next_pos;

	next_pos.x = 0;
	next_pos.y = 0;
	if (master->player.left)
	{
		next_pos.x = master->player.x - (sin(master->player.dir) / MS);
		next_pos.y = master->player.y + (cos(master->player.dir) / MS);
	}
	else if (master->player.rigth)
	{
		next_pos.x = master->player.x + (sin(master->player.dir) / MS);
		next_pos.y = master->player.y - (cos(master->player.dir) / MS);
	}
	if (validation(master, next_pos) == 0)
	{
		master->map.original_map[(int)master->player.y] \
								[(int)master->player.x] = '0';
		master->player.x = next_pos.x;
		master->player.y = next_pos.y;
	}
	master->player.dir_x = cos(master->player.dir);
	master->player.dir_y = sin(master->player.dir);
}

static void	move_back_foward(t_master *master)
{
	t_xy	next_pos;

	next_pos.x = 0;
	next_pos.y = 0;
	if (master->player.up)
	{
		next_pos.x = master->player.x + (cos(master->player.dir) / MS);
		next_pos.y = master->player.y + (sin(master->player.dir) / MS);
	}
	else if (master->player.down)
	{
		next_pos.x = master->player.x - (cos(master->player.dir) / MS);
		next_pos.y = master->player.y - (sin(master->player.dir) / MS);
	}
	if (validation(master, next_pos) == 0)
	{
		master->map.original_map[(int)master->player.y] \
						[(int)master->player.x] = '0';
		master->player.x = next_pos.x;
		master->player.y = next_pos.y;
	}
	master->player.dir_x = cos(master->player.dir);
	master->player.dir_y = sin(master->player.dir);
}

static int	validation(t_master *master, t_xy next_pos)
{
	if ((next_pos.x < 0 || next_pos.y < 0 || \
			next_pos.x >= master->map.map_size_x \
			|| next_pos.y >= master->map.map_size_y) \
			|| master->map.original_map[(int)next_pos.y] \
								[(int)next_pos.x] != '0')
		return (-1);
	return (0);
}

static void	rotate(t_master *master, double angle)
{
	if (master->player.rotate_left)
	{
		master->player.dir -= angle;
		if (master->player.dir < 0)
			master->player.dir += 2 * PI;
	}
	if (master->player.rotate_right)
	{
		master->player.dir += angle;
		if (master->player.dir > 2 * PI)
			master->player.dir = 0 ;
	}
	master->player.dir_x = cos(master->player.dir);
	master->player.dir_y = sin(master->player.dir);
}

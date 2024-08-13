/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_mouvement_master.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:28:41 by guilrodr          #+#    #+#             */
/*   Updated: 2024/08/13 20:31:42 by guilrodr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	validation(t_master *master, t_xy next_pos);
static void	move_left_right(t_master *master, int keypressed);
static void	rotate(t_master *master, double angle, int keypressed);
static void	move_back_foward(t_master *master, int keypressed);

int	character_mouvement(t_master *master, int keypressed)
{
	if (keypressed == 119 || keypressed == 115)
		move_back_foward(master, keypressed);
	else if (keypressed == 97 || keypressed == 100)
		move_left_right(master, keypressed);
	else if (keypressed == XK_Left || keypressed == XK_Right)
		rotate(master, 0.05, keypressed);
	return (0);
}

static void	move_left_right(t_master *master, int keypressed)
{
	t_xy	next_pos;

	next_pos.x = 0;
	next_pos.y = 0;
	if (keypressed == 97)
	{
		next_pos.x = master->player.x - (sin(master->player.dir) / 10);
		next_pos.y = master->player.y + (cos(master->player.dir) / 10);
	}
	else if (keypressed == 100)
	{
		next_pos.x = master->player.x + (sin(master->player.dir) / 10);
		next_pos.y = master->player.y - (cos(master->player.dir) / 10);
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

static void	move_back_foward(t_master *master, int keypressed)
{
	t_xy	next_pos;

	next_pos.x = 0;
	next_pos.y = 0;
	if (keypressed == 119)
	{
		next_pos.x = master->player.x + (cos(master->player.dir) / 10);
		next_pos.y = master->player.y + (sin(master->player.dir) / 10);
	}
	else if (keypressed == 115)
	{
		next_pos.x = master->player.x - (cos(master->player.dir) / 10);
		next_pos.y = master->player.y - (sin(master->player.dir) / 10);
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

static void	rotate(t_master *master, double angle, int keypressed)
{
	if (keypressed == XK_Left)
	{
		master->player.dir -= angle;
		if (master->player.dir < 0)
			master->player.dir += 2 * PI;
	}
	if (keypressed == XK_Right)
	{
		master->player.dir += angle;
		if (master->player.dir > 2 * PI)
			master->player.dir -= 2 * PI;
	}
	master->player.dir_x = cos(master->player.dir);
	master->player.dir_y = sin(master->player.dir);
}

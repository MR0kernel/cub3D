/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_master_structs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:14:53 by guilrodr          #+#    #+#             */
/*   Updated: 2024/08/10 18:08:21 by guilrodr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_master_struct(t_master *master)
{
	master->imgs.wall_img = NULL;
	master->imgs.floor_img = NULL;
	master->imgs.collectible_img = NULL;
	master->imgs.exit_img = NULL;
	master->imgs.player_img = NULL;
	master->player.x = 0;
	master->player.y = 0;
	master->player.dir = 0;
	master->player.dir_x = cos(master->player.dir);
	master->player.dir_y = sin(master->player.dir);
	master->map.original_map = NULL;
	master->map.map_size_x = 0;
	master->map.map_size_y = 0;
	master->given_map = NULL;
	master->collectibles = 0;
	master->mlx = NULL;
	master->win = NULL;
}

void	init_tools(t_player *ray_player, t_player *player)
{
	ray_player->x = player->x;
	ray_player->y = player->y;
	ray_player->dir = player->dir;
	ray_player->dir_x = player->dir_x;
	ray_player->dir_y = player->dir_y;
}

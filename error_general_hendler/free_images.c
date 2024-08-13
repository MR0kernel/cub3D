/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:46:05 by guilrodr          #+#    #+#             */
/*   Updated: 2024/08/13 20:49:36 by guilrodr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_images(t_master *master)
{
	if (master->imgs.wall_img != NULL)
		mlx_destroy_image(master->mlx, master->imgs.wall_img);
	if (master->imgs.floor_img != NULL)
		mlx_destroy_image(master->mlx, master->imgs.floor_img);
	if (master->imgs.collectible_img != NULL)
		mlx_destroy_image(master->mlx, master->imgs.collectible_img);
	if (master->imgs.exit_img != NULL)
		mlx_destroy_image(master->mlx, master->imgs.exit_img);
	if (master->imgs.player_img != NULL)
		mlx_destroy_image(master->mlx, master->imgs.player_img);
	if (master->canvas != NULL)
		mlx_destroy_image(master->mlx, master->canvas);
	if (master->mini_map != NULL)
		mlx_destroy_image(master->mlx, master->mini_map);
}

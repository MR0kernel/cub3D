/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:46:05 by guilrodr          #+#    #+#             */
/*   Updated: 2023/12/10 09:38:21 by guilrodr         ###   ########lyon.fr   */
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
}

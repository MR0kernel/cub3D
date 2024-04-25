/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_converter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:36:29 by guilrodr          #+#    #+#             */
/*   Updated: 2023/12/10 13:48:06 by guilrodr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_images(t_master *master)
{
	int	i;
	int	j;

	master->imgs.wall_img = X_TO_I(master->mlx, WALL_IMAGE, &i, &j);
	if (master->imgs.wall_img == NULL)
		fourth_class_error_handler(master, 1);
	master->imgs.floor_img = X_TO_I(master->mlx, FLOOR_IMAGE, &i, &j);
	if (master->imgs.floor_img == NULL)
		fourth_class_error_handler(master, 2);
	master->imgs.collectible_img = X_TO_I(master->mlx, COLL_IMAGE, &i, &j);
	if (master->imgs.collectible_img == NULL)
		fourth_class_error_handler(master, 3);
	master->imgs.exit_img = X_TO_I(master->mlx, EXIT_IMAGE, &i, &j);
	if (master->imgs.exit_img == NULL)
		fourth_class_error_handler(master, 4);
	master->imgs.player_img = X_TO_I(master->mlx, PLAYER_IMAGE, &i, &j);
	if (master->imgs.player_img == NULL)
		fourth_class_error_handler(master, 5);
}

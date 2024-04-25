/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_images_master.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 07:35:34 by guilrodr          #+#    #+#             */
/*   Updated: 2023/12/10 08:46:15 by guilrodr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	init_pointers(t_master *master);

void	launch_images(t_master *master)
{
	init_pointers(master);
	load_images(master);
}

static void	init_pointers(t_master *master)
{
	master->imgs.wall_img = NULL;
	master->imgs.floor_img = NULL;
	master->imgs.collectible_img = NULL;
	master->imgs.exit_img = NULL;
	master->imgs.player_img = NULL;
}

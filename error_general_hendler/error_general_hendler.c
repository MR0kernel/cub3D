/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_general_hendler.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilrodr <guilrodr@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:41:19 by guilrodr          #+#    #+#             */
/*   Updated: 2023/12/10 13:49:49 by guilrodr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	basic_error_handler(t_master *master, int error_code)
{
	if (error_code == 1)
		ft_printf("Wrong number of arguments only a map must be given\n");
	else if (error_code == 2)
		ft_printf("given map is invalid, must be a .ber map\n");
	else if (error_code == 3)
		ft_printf("can't open given map, no rights or file does not exist\n");
	else if (error_code == 4)
		ft_printf("fail getting map, maybe empty file ? \n");
	else if (error_code == 5)
		ft_printf("map is not rectangular\n");
	else if (error_code == 6)
	{
		ft_printf("malloc failed xD\n");
		if (master->map.original_map)
			free_map(master->map.original_map, master->map.map_size_y);
		if (master)
			free(master);
		exit(EXIT_FAILURE);
	}
	free(master);
	exit(EXIT_FAILURE);
}

void	second_class_error_handler(t_master *master, int error_code)
{
	if (error_code == 1)
		ft_printf("Map must be closed\n");
	else if (error_code == 2)
		ft_printf("Map must only contain P,C,E,0 and 1\n");
	else if (error_code == 3)
		ft_printf("Game must only contain one player \n");
	else if (error_code == 4)
		ft_printf("Game must only contain one exit\n");
	else if (error_code == 5)
		ft_printf("Game must contain at least one collectible\n");
	else if (error_code == 6)
		ft_printf("Player must be able to win\n");
	else if (error_code == 7)
		ft_printf("Not all collectibles are reacheble\n");
	else if (error_code == 8)
		ft_printf("Exit is not reacheble\n");
	else if (error_code == 9)
		ft_printf("t Einstein removed one of the images\n");
	else if (error_code == 10)
		ft_printf("mlx failled to init\n");
	free_map(master->map.original_map, master->map.map_size_y);
	basic_error_handler(master, 0);
}

void	third_class_error_handler(t_master *master, int error_code)
{
	if (error_code == 1)
		ft_printf("window failled to init\n");
	else if (error_code == 2)
		ft_printf("");
	free_images(master);
	mlx_destroy_display(master->mlx);
	free(master->mlx);
	second_class_error_handler(master, 0);
}

void	fourth_class_error_handler(t_master *master, int error_code)
{
	if (error_code == 1)
		ft_printf("could nor get wall image\n");
	else if (error_code == 2)
		ft_printf("could nor get floor image\n");
	else if (error_code == 3)
		ft_printf("could nor get collectible image\n");
	else if (error_code == 4)
		ft_printf("could nor get exit image\n");
	else if (error_code == 5)
		ft_printf("could nor get player image\n");
	third_class_error_handler(master, 0);
}

void	fifth_class_error_handler(t_master *master, int error_code)
{
	if (error_code == 1)
		ft_printf("\n");
	else if (error_code == 2)
		ft_printf("\n");
	else if (error_code == 3)
		ft_printf("\n");
	else if (error_code == 4)
		ft_printf("\n");
	else if (error_code == 5)
		ft_printf("\n");
	mlx_destroy_window(master->mlx, master->win);
	fourth_class_error_handler(master, 0);
}
